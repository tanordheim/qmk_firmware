/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

enum layers {
    COLEMAKDH = 0,
    NAV,
    NUM,
    SYM,
    FN,
    ADJ
};

#define LT_AE_O  LT(COLEMAKDH, KC_O)
#define LT_OE_I  LT(COLEMAKDH, KC_I)
#define LT_AA_SC LT(COLEMAKDH, KC_SCLN)
#define DQT_SQT  LT(COLEMAKDH, KC_DQT)
#define SS_CLP   LGUI(LCTL(LSFT(KC_4)))
#define SS_FILE  LGUI(LSFT(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: COLEMAK DH
 *
 */
    [COLEMAKDH] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    LT_AA_SC,KC_BSPC,
      KC_LSFT, KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                                         KC_M,    KC_N,    KC_E,    LT_OE_I, LT_AE_O, DQT_SQT,
      KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,    KC_LALT, XXXXXXX, XXXXXXX, MO(FN),   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                               KC_MEH, KC_LGUI,KC_ESC,  KC_SPC,  MO(NAV), KC_BSPC, KC_ENT,   MO(SYM), MO(NUM), KC_HYPR
    ),
/*
 * Nagation layer/media
 *
 */
    [NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Number layer
 *
 */
    [NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, KC_SLSH, KC_MINS, KC_PLUS, KC_EQL,  KC_ASTR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Symbol layer
 *
 */
    [SYM] = LAYOUT(
      _______, _______, KC_QUOT, KC_DQT,  KC_CIRC, KC_GRV,                                      KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC, _______,
      _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_PIPE,                                     KC_HASH, KC_COLN, KC_LPRN, KC_RPRN, KC_DLR,  _______,
      _______, _______, KC_LT,   KC_GT,   _______, KC_ASTR, _______, _______, _______, _______, KC_TILD, KC_AT,   KC_LCBR, KC_RCBR, KC_BSLS, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Fn layer
 */
    [FN] = LAYOUT(
      _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,                                      _______, _______, _______, _______, _______, _______,
      _______, _______, KC_F3,   KC_F4,   KC_F5,   KC_F11,                                      SS_CLP,  _______, _______, _______, _______, _______,
      _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, _______, _______, _______, SS_FILE, _______, _______, _______, _______, _______,
                                 MO(ADJ), _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust layer
 */
    [ADJ] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_VAD, RGB_MOD, RGB_TOG, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

static inline bool base_layer_hold_key(uint16_t keycode, keyrecord_t *record) {
    if (!record->tap.count && record->event.pressed) {
        tap_code16(keycode);
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_AE_O:
            return base_layer_hold_key(RALT(KC_Q), record);
        case LT_OE_I:
            return base_layer_hold_key(RALT(KC_O), record);
        case LT_AA_SC:
            return base_layer_hold_key(RALT(KC_A), record);
        case DQT_SQT:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    unregister_mods(MOD_BIT(KC_RSFT));
                    tap_code(KC_QUOT);
                    set_mods(get_mods() | MOD_BIT(KC_LSFT));
                } else {
                    tap_code16(S(KC_QUOT));
                }
            }
            return false;
    }
    return true;
}


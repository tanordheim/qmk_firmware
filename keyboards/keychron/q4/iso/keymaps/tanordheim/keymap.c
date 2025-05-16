/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers {
    CODING_BASE,
    TYPING_BASE,
    _SYM,
    _NAV,
    _FN
};

#define ESC_SYM LT(_SYM, KC_ESC)
#define NO_LBRC RALT(KC_7)
#define NO_RBRC RALT(KC_0)
#define NO_LBRK RALT(KC_8)
#define NO_RBRK RALT(KC_9)
#define NO_LPAR LSFT(KC_8)
#define NO_RPAR LSFT(KC_9)
#define NO_CRT  LSFT(KC_RBRC)
#define NO_DLR  RALT(KC_4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CODING_BASE] = LAYOUT_iso_62(
        KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,
        ESC_SYM, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_BSLS,  KC_ENT,
        KC_LSFT, KC_NUBS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                             MO(_NAV), MO(_FN), KC_RALT,  KC_RCTL),

    [TYPING_BASE] = LAYOUT_iso_62(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_SYM] = LAYOUT_iso_62(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, NO_LPAR, NO_RPAR, _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, NO_CRT,  NO_LBRC, NO_LBRK, NO_RBRK, NO_RBRC,  NO_DLR,   _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_NAV] = LAYOUT_iso_62(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, KC_HOME,  KC_UP,   KC_END,  _______, _______, _______, _______, _______, _______, _______,  _______,  _______,
        _______, KC_LEFT,  KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN] = LAYOUT_iso_62(
        _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
    //     case NO_LBRC:
    //         if (record->event.pressed) {
    //             bool shifted = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
    //             if (shifted) {
    //                 register_code(KC_RALT);
    //                 tap_code(KC_8);
    //                 unregister_code(KC_RALT);
    //             } else {
    //                 register_code(KC_RALT);
    //                 tap_code(KC_7);
    //                 unregister_code(KC_RALT);
    //             }
    //         }
    //         return false;
    // }
    return true;
}
// clnag-format on

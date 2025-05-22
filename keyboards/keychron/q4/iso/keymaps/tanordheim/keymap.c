#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

// clang-format off


enum layers {
    QWERTY_BASE,
    COLEMAK_BASE,
    _LSN, // symbols and nav
    _L2,
    _FN
};

enum custom_keycodes {
    US_LBRK = SAFE_RANGE,
    US_RBRK,
    US_SEMI,
    US_QUOT,
    US_BSLS,
    US_COMM,
    US_DOT,
    US_SLHS,
    US_GRV,
    US_EQL,
    US_2,
    US_4,
    US_6,
    US_7,
    US_8,
    US_9,
    US_0
};

#define ESC_LSN LT(_LSN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY_BASE] = LAYOUT_iso_62(
        US_GRV,  NO_1,     US_2,    NO_3,    US_4,    NO_5,    US_6,    US_7,    US_8,    US_9,    US_0,     NO_MINS,  US_EQL,   KC_BSPC,
        KC_TAB,  NO_Q,     NO_W,    NO_E,    NO_R,    NO_T,    NO_Y,    NO_U,    NO_I,    NO_O,    NO_P,     US_LBRK,  US_RBRK,
        ESC_LSN, NO_A,     NO_S,    NO_D,    NO_F,    NO_G,    NO_H,    NO_J,    NO_K,    NO_L,    US_SEMI,  US_QUOT,  US_BSLS,  KC_ENT,
        KC_LSFT, KC_LCTL,  NO_Z,    NO_X,    NO_C,    NO_V,    NO_B,    NO_N,    NO_M,    US_COMM, US_DOT,   US_SLHS,            KC_RSFT,
        KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                             MO(_L2), MO(_FN),  KC_RALT,  KC_RCTL),

    [COLEMAK_BASE] = LAYOUT_iso_62(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, NO_F,    NO_P,    NO_B,    NO_J,    NO_L,    NO_U,    NO_Y,    US_SEMI,  _______,  _______,
        _______, _______,  NO_R,    NO_S,    NO_T,    _______, NO_M,    NO_N,    NO_E,    NO_I,    NO_O,     _______,  _______,  _______,
        _______, _______,  _______, _______, _______, NO_D,    NO_V,    NO_K,    NO_H,    _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_LSN] = LAYOUT_iso_62(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, NO_CIRC, _______, _______, _______, NO_DLR,   NO_ARNG,  _______,
        _______, _______,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, NO_OSTR,  NO_AE,    _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_L2] = LAYOUT_iso_62(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN] = LAYOUT_iso_62(
        _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        UG_TOGG, UG_VALD,  UG_HUEU, UG_VALU, UG_SPDU, UG_NEXT, _______, _______, _______, _______, _______,  _______,  _______,
        _______, UG_SATD,  UG_HUED, UG_SATU, UG_SPDD, UG_PREV, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  QK_BOOT, EE_CLR,  _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case US_LBRK:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(NO_LCBR);
                    set_mods(mods);
                } else {
                    tap_code16(NO_LBRC);
                }
            }
            return false;


        case US_RBRK:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(NO_RCBR);
                    set_mods(mods);
                } else {
                    tap_code16(NO_RBRC);
                }
            }
            return false;

        case US_SEMI:
            if (record->event.pressed) {
                bool shifted = get_mods() & MOD_MASK_SHIFT;
                if (shifted) {
                    tap_code16(NO_COLN);
                } else {
                    tap_code16(NO_SCLN);
                }
            }
            return false;

        case US_QUOT:
            if (record->event.pressed) {
                bool shifted = get_mods() & MOD_MASK_SHIFT;
                if (shifted) {
                    tap_code16(NO_DQUO);
                } else {
                    tap_code(NO_QUOT);
                }
            }
            return false;

        case US_BSLS:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(NO_PIPE);
                    set_mods(mods);
                } else {
                    tap_code(NO_BSLS);
                }
            }
            return false;

        case US_COMM:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_NUBS);
                    set_mods(mods);
                } else {
                    tap_code(KC_COMM);
                }
            }
            return false;

        case US_DOT:
            if (record->event.pressed) {
                bool shifted = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                if (shifted) {
                    tap_code(KC_NUBS);
                } else {
                    tap_code(KC_DOT);
                }
            }
            return false;

        case US_SLHS:
            if (record->event.pressed) {
                bool shifted = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                if (shifted) {
                    tap_code(KC_MINS);
                } else {
                    tap_code16(LSFT(KC_7));
                }
            }
            return false;

        case US_GRV:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(RALT(KC_RBRC));
                    set_mods(mods);
                } else {
                    tap_code16(LSFT(KC_EQL));
                }
                tap_code(KC_SPC); // dead keys, need a space after
            }
            return false;

        case US_EQL:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_MINS);
                    set_mods(mods);
                } else {
                    tap_code16(LSFT(KC_0));
                }
            }
            return false;

        case US_2:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                bool alt = mods & MOD_MASK_ALT;

                // special case: if hit with ALT+SHIFT modifiers, send the normal NO shifted code since its bound in Hyprland bindings and things gets weird
                // if that is remapped here for some keys.
                if (shifted && alt) {
                    tap_code(NO_2);
                } else if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(NO_AT);
                    set_mods(mods);
                } else {
                    tap_code(NO_2);
                }
            }
            return false;

        case US_4:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                bool alt = mods & MOD_MASK_ALT;

                // special case: if hit with ALT+SHIFT modifiers, send the normal NO shifted code since its bound in Hyprland bindings and things gets weird
                // if that is remapped here for some keys.
                if (shifted && alt) {
                    tap_code(NO_4);
                } else if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(NO_DLR);
                    set_mods(mods);
                } else {
                    tap_code(NO_4);
                }
            }
            return false;

        case US_6:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                bool alt = mods & MOD_MASK_ALT;

                // special case: if hit with ALT+SHIFT modifiers, send the normal NO shifted code since its bound in Hyprland bindings and things gets weird
                // if that is remapped here for some keys.
                if (shifted && alt) {
                    tap_code(NO_6);
                } else if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(NO_CIRC);
                    tap_code(KC_SPC); // dead keys, need a space after
                    set_mods(mods);
                } else {
                    tap_code(NO_6);
                }
            }
            return false;

        case US_7:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                bool alt = mods & MOD_MASK_ALT;

                // special case: if hit with ALT+SHIFT modifiers, send the normal NO shifted code since its bound in Hyprland bindings and things gets weird
                // if that is remapped here for some keys.
                if (shifted && alt) {
                    tap_code(NO_7);
                } else if (shifted) {
                    tap_code16(NO_AMPR);
                } else {
                    tap_code(NO_7);
                }
            }
            return false;

        case US_8:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                bool alt = mods & MOD_MASK_ALT;

                // special case: if hit with ALT+SHIFT modifiers, send the normal NO shifted code since its bound in Hyprland bindings and things gets weird
                // if that is remapped here for some keys.
                if (shifted && alt) {
                    tap_code(NO_8);
                } else if (shifted) {
                    tap_code16(NO_ASTR);
                } else {
                    tap_code(NO_8);
                }
            }
            return false;

        case US_9:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                bool alt = mods & MOD_MASK_ALT;

                // special case: if hit with ALT+SHIFT modifiers, send the normal NO shifted code since its bound in Hyprland bindings and things gets weird
                // if that is remapped here for some keys.
                if (shifted && alt) {
                    tap_code(NO_9);
                } else if (shifted) {
                    tap_code16(NO_LPRN);
                } else {
                    tap_code(NO_9);
                }
            }
            return false;

        case US_0:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                bool shifted = mods & MOD_MASK_SHIFT;
                bool alt = mods & MOD_MASK_ALT;

                // special case: if hit with ALT+SHIFT modifiers, send the normal NO shifted code since its bound in Hyprland bindings and things gets weird
                // if that is remapped here for some keys.
                if (shifted && alt) {
                    tap_code(NO_0);
                } else if (shifted) {
                    tap_code16(NO_RPRN);
                } else {
                    tap_code(NO_0);
                }
            }
            return false;
    }
    return true;
}
// clnag-format on

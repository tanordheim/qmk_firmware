#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"
#include "sendstring_norwegian.h"

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY = 1,
    _NAV_MEDIA,
    _SYM,
    _NUM,
    _INTL,
    _FUNCTION,
    _ADJUST,
};

// MacOS Norwegian keycode overlays
#define NOM_TILD  ALGR(KC_RBRC)
#define NOM_PIPE  ALGR(NO_7)
#define NOM_QUOT  KC_NUBS
#define NOM_LABK  KC_GRV
#define NOM_RABK  S(KC_GRV)
#define NOM_AT    KC_NUHS
#define NOM_CARET S(KC_RBRC)
#define NOM_BSLS  S(ALGR(NO_7))
#define NOM_DLR   KC_DLR
#define NOM_LBRC  ALGR(NO_8)
#define NOM_RBRC  ALGR(NO_9)
#define NOM_LCBR  S(ALGR(NO_8))
#define NOM_RCBR  S(ALGR(NO_9))

// Tap dances
enum {
    TAP_DANCE_BACKTICK = 0
};

static void backtick_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING("```");
    } else {
        SEND_STRING("`");
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_BACKTICK] = ACTION_TAP_DANCE_FN(backtick_tap_dance)
};

// enum custom_keycodes {
//     // NO_CARET_NODEAD = SAFE_RANGE,
// };

// Key overrides
const key_override_t pipe_shift_override = ko_make_basic(MOD_MASK_SHIFT, NOM_PIPE, NOM_TILD);
const key_override_t n2_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_2, NOM_AT);
const key_override_t n6_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_6, NOM_CARET);
const key_override_t n7_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_7, NO_AMPR);
const key_override_t n9_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_9, NO_LPRN);
const key_override_t n0_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_0, NO_RPRN);
const key_override_t eql_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_EQL, NO_PLUS);
const key_override_t semicolon_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_SCLN, NO_COLN);
const key_override_t dblquote_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_DQUO, NOM_QUOT);
const key_override_t comma_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_COMM, NOM_LABK);
const key_override_t dot_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_DOT, NOM_RABK);
const key_override_t slash_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_SLSH, NOM_BSLS);
const key_override_t questionmark_shift_override = ko_make_basic(MOD_MASK_SHIFT, NO_QUES, NO_EXLM);
const key_override_t *key_overrides[] = {
    &pipe_shift_override,
    &n2_shift_override,
    &n6_shift_override,
    &n7_shift_override,
    &n9_shift_override,
    &n0_shift_override,
    &eql_shift_override,
	&semicolon_shift_override,
    &dblquote_shift_override,
    &comma_shift_override,
    &dot_shift_override,
    &slash_shift_override,
    &questionmark_shift_override,
};

// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)
#define QWERTY   DF(_QWERTY)
#define SYM      MO(_SYM)
#define NUM      MO(_NUM)
#define INTL     MO(_INTL)
#define NAVMED   MO(_NAV_MEDIA)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define TD_BTK   TD(TAP_DANCE_BACKTICK)
#define ESC_NAV  LT(_NAV_MEDIA, KC_ESC)
#define DPRV     G(KC_PGDN)
#define DNXT     G(KC_PGUP)
#define DBF      G(KC_HOME)
#define TODO     _______


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 */
    [_COLEMAK_DH] = LAYOUT_myr(
      NOM_PIPE, NO_1 ,  NO_2   ,  NO_3  ,   NO_4 ,   NO_5 ,         _______,     _______,          NO_6 ,  NO_7 ,  NO_8 ,   NO_9 ,  NO_0 , TD_BTK ,
      KC_TAB  , NO_Q ,  NO_W   ,  NO_F  ,   NO_P ,   NO_B ,         _______,     _______,          NO_J,   NO_L ,  NO_U ,   NO_Y ,NO_SCLN, KC_BSPC,
      KC_LSFT , NO_A ,  NO_R   ,  NO_S  ,   NO_T ,   NO_G ,         _______,     _______,          NO_M,   NO_N ,  NO_E ,   NO_I ,  NO_O , NO_DQUO,
      KC_LCTL , NO_Z ,  NO_X   ,  NO_C  ,   NO_D ,   NO_V ,  DPRV  ,ADJUST ,     FKEYS  ,  DNXT ,  NO_K,   NO_H ,NO_COMM, NO_DOT ,NO_SLSH, NO_QUES,
                                  KC_LALT,KC_LGUI,ESC_NAV , KC_SPC , INTL  ,     DBF    , KC_ENT,  SYM ,   NUM  ,KC_HYPR,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Nav Layer: Navigation and Media
 */
    [_NAV_MEDIA] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, _______,
      _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,          _______, _______,          KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_DEL , _______,
      _______, _______, _______, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS , _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Sym Layer: Symbols
 */
    [_SYM] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______,NOM_TILD, _______,NOM_LBRC, NO_HASH, NO_ASTR,          _______, _______,          NO_EURO, NO_PND ,NOM_RBRC, _______, _______, _______,
      _______, NO_PERC,NOM_PIPE,NOM_LCBR, NO_LPRN, NO_EQL ,          _______, _______,          NO_CIRC, NO_RPRN,NOM_RCBR, _______, NOM_DLR, _______,
      _______, NO_PLUS, NO_AMPR,  NOM_AT, NO_UNDS, NO_MINS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Num Layer: Numbers and math
 */
    [_NUM] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______,  KC_P7 ,  KC_P8 ,  KC_P9 , _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, NO_PERC,  KC_P4 ,  KC_P5 ,  KC_P6 , NO_EQL ,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, NO_PLUS,  KC_P1 ,  KC_P2 ,  KC_P3 , NO_MINS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______,  KC_P0 , _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * International Layer: International symbols and characters
 */
    [_INTL] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, NO_ARNG, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, NO_OSTR,  NO_AE , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Function Layer: Function keys
 */
    [_FUNCTION] = LAYOUT_myr(
      KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,          _______, _______,           KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 */
    [_ADJUST] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, COLEMAK, _______, _______,         _______, _______,          RM_TOGG, RM_SATU, RM_HUEU, RM_VALU,  RM_NEXT, _______,
      _______, _______, _______, QWERTY,  _______, _______,_______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD,  RM_PREV, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______

    ),

// /*
//  * Layer template - LAYOUT
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// /*
//  * Layer template - LAYOUT_myr
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  *
//  * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
//  * |        |      |      |      |      |      |                |      |      |      |      |      |      |
//  * `-----------------------------'      `------'                `---------------------------'      '------'
//  */
//     [_LAYERINDEX] = LAYOUT_myr(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
bool oled_task_user(void) {
  // Your code goes here
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // Your code goes here
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

/*
typedef struct { uint16_t kc; uint16_t unshifted; uint16_t shifted; } morph_t;
static const morph_t morphs[] = {
    { US_SEMI, NO_SCLN, NO_COLN },          // ; :
    { US_QUOT, NO_DQUO, NO_QUOT_MAC },      // ' "
    // { US_COMM, NO_COMM, NO_LABK },          // , <
    // { YOUR_KEY, UN, SH },
};
static const size_t morphs_len = sizeof(morphs)/sizeof(morphs[0]);
static inline const morph_t* find_morph(uint16_t kc) {
    for (size_t i = 0; i < morphs_len; i++) if (morphs[i].kc == kc) return &morphs[i];
    return NULL;
}

static inline bool shift_active(void) {
    return (get_mods() | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
}
static uint16_t held_out[MATRIX_ROWS][MATRIX_COLS];

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const morph_t* m = find_morph(keycode);
    if (!m) {
        uprintf("IN process_record_user, keycode is not a registered morph\n");
        return true;  // not one of our morph keys
    }

    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;
    uprintf("IN process_record_user, keycode is a registered morph\n");

    if (record->event.pressed) {
        uint16_t out = shift_active() ? m->shifted : m->unshifted;
        held_out[row][col] = out;
        register_code16(out);
    } else {
        uint16_t out = held_out[row][col];
        if (out) {
            unregister_code16(out);  // must match what we registered
            held_out[row][col] = 0;
        } else {
            uprintf("IN process_record_user, could not find held out code on release\n");
        }
    }
    return false;

    // if (!record->event.pressed) return true;
    //
    // switch (keycode) {
    //     case US_SEMI:
    //         if (shift_active()) tap_code16(NO_COLN);
    //         else                tap_code16(NO_SCLN);
    //         return false;
    // }
    // return true;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }


    // switch (keycode) {
    //     case NO_CARET_NODEAD:
    //         uprintf("in NO_CARET_NODEAD processing\n");
    //         tap_code16(NO_CARET_MAC);
    //         tap_code(KC_SPC);
    //         return false;
    // }

    return true;
}

#include "planck.h"

#define QWRT 0
#define WORK 1
#define MDIA 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWRT] = { /* Qwerty */
    {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_ESC,  KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
    {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_TAB,  KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
    {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_ENT,  KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
    {KC_RSFT, CTL_T(KC_ESC), KC_LALT, KC_LGUI, KC_SPC, FUNC(1), FUNC(1), KC_SPC, KC_LGUI, KC_LALT, CTL_T(KC_ESC), KC_RSFT}
  },
  [WORK] = { /* Workman P */
    {KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,   KC_ESC,  KC_BSPC, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN},
    {KC_A,    KC_S,    KC_H,    KC_T,    KC_G,   KC_TAB,  KC_QUOT, KC_Y,    KC_N,    KC_E,    KC_O,    KC_I},
    {KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,   KC_ENT,  KC_ENT,  KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH},
    {KC_RSFT, CTL_T(KC_ESC), KC_LALT, KC_LGUI, KC_SPC, FUNC(1), FUNC(1), KC_SPC, KC_LGUI, KC_LALT, CTL_T(KC_ESC), KC_RSFT}
    },
  [MDIA] = { /* Utils */
    {FUNC(3),   KC_1,      KC_2,    KC_3,    KC_4,       KC_5,    KC_6,    KC_7,      KC_8,       KC_9,       KC_0,      FUNC(4)},
    {KC_GRV,    S(KC_GRV), S(KC_9), S(KC_0), S(KC_MINS), KC_MINS, KC_EQL,  S(KC_EQL), S(KC_LBRC), S(KC_RBRC), KC_LBRC,   KC_RBRC},
    {S(KC_GRV), S(KC_1),   S(KC_2), S(KC_3), S(KC_4),    S(KC_5), S(KC_6), S(KC_7),   S(KC_8),    S(KC_COMM), S(KC_DOT), KC_BSLS},
    {MT(MOD_LSFT, KC_LEFT), MT(MOD_LCTL, KC_DOWN), MT(MOD_LALT, KC_UP), MT(MOD_LGUI, KC_RIGHT), KC_BTN2, KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_L,    KC_MS_U,    KC_MS_D, KC_MS_R}
    },
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(2),  // to Fn overlay
    /* [2] = ACTION_LAYER_MOMENTARY(3),  // to Fn overlay */
    [3] = ACTION_DEFAULT_LAYER_SET(0),
    [4] = ACTION_DEFAULT_LAYER_SET(1),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

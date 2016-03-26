#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = { /* Qwerty */
    {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_ESC,  KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
    {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_TAB,  KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
    {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_ENT,  KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
    {KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, FUNC(1), FUNC(1), KC_SPC, KC_RGUI, KC_RALT,  KC_RCTL, KC_RSFT}
  },
  [1] = { /* Norman */
    {KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,   KC_ESC,  KC_BSPC, KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN},
    {KC_A,    KC_S,    KC_E,    KC_T,    KC_G,   KC_TAB,  KC_QUOT, KC_Y,    KC_N,    KC_I,    KC_O,    KC_H},
    {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_ENT,  KC_ENT,  KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
    {KC_RSFT, CTL_T(KC_ESC), KC_LALT, KC_LGUI, KC_SPC, FUNC(1), FUNC(1), KC_SPC, KC_LGUI, KC_LALT, CTL_T(KC_ESC), KC_RSFT}
    },
  [2] = { /* Utils */
    {KC_1,   KC_2,   KC_3,    KC_4,    KC_5,   FUNC(3), FUNC(4),  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC},
    {KC_6,   KC_7,   KC_8,    KC_9,    KC_0,   KC_TRNS, KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
    {KC_ESC, KC_EQL, KC_MINS, KC_PIPE, KC_GRV, KC_TRNS, KC_TRNS,  KC_TILD, KC_PIPE, KC_BSLS, KC_LBRC, KC_RBRC},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GUI_T(KC_LEFT), ALT_T(KC_DOWN), CTL_T(KC_UP), SFT_T(KC_RIGHT)}
    },
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(2),  // Fn overlay
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

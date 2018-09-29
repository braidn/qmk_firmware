#include "hhkb.h"

#define BASE 0
#define NAVI 1
#define NUMB 2
#define NORM 3
#define NAVN 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = \
    KEYMAP(KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_GRV, \
           KC_FN4, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC, \
           KC_FN12,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,KC_FN6, \
           KC_LSPO,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSPC,MO(2), \
                KC_FN7,   KC_FN6,          KC_SPC,                KC_FN13,KC_FN11),
    [NAVI] = \
    KEYMAP(KC_GRV,  KC_FN0, KC_FN2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_FN0, KC_FN2, \
           KC_TRNS, KC_BTN1,KC_MS_U, KC_BTN2,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_BTN1,  KC_BTN2,  KC_BSLS, \
           KC_TRNS, KC_MS_L,KC_MS_D, KC_MS_R,KC_PGDN,KC_NO,  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_NO,  KC_BSLS,  KC_ENT, \
           KC_BSPC, KC_VOLD,KC_VOLU, KC_NO,  KC_NO,  KC_PGUP,  KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_NO, KC_BSPC,KC_TRNS, \
                KC_TRNS,KC_TRNS,          KC_SPC,                KC_TRNS,KC_TRNS),
    [NUMB] = \
    KEYMAP(KC_GRV,  KC_FN0, KC_FN2,  KC_F3, KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_FN0, KC_FN2, \
           KC_TRNS, KC_1,   KC_2,    KC_3,  S(KC_1),S(KC_2),S(KC_3),KC_MINS, S(KC_MINS),   KC_9,   KC_0,  KC_BTN1,  KC_BTN2,  KC_BSLS, \
           KC_0,    KC_4,   KC_5,    KC_6,  S(KC_4),S(KC_5),S(KC_6),KC_EQL,  S(KC_EQL),  KC_RGHT,KC_NO,  KC_BSLS,  KC_ENT, \
           KC_BSPC, KC_7,   KC_8,    KC_9,  S(KC_7),S(KC_8),S(KC_9),KC_BSLS, S(KC_BSLS),KC_END, KC_NO, KC_BSPC,KC_TRNS, \
                KC_TRNS,KC_TRNS,          KC_SPC,                KC_TRNS,KC_TRNS),
    [NORM] = \
    KEYMAP(KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_GRV, \
           KC_FN4, KC_Q,   KC_W,   KC_D,   KC_F,   KC_K,   KC_J,   KC_U,   KC_R,   KC_L,   KC_SCLN,   KC_LBRC,KC_RBRC,KC_BSPC, \
           KC_FN12,KC_A,   KC_S,   KC_E,   KC_T,   KC_G,   KC_Y,   KC_N,   KC_I,   KC_O,   KC_H, KC_QUOT,KC_FN6, \
           KC_LSPO,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_P,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSPC,MO(4), \
                KC_LALT,   KC_FN6,          KC_SPC,                KC_FN13, KC_FN11),
    [NAVN] = \
    KEYMAP(KC_GRV,  KC_FN0, KC_FN2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_FN0, KC_FN2, \
           KC_TRNS, KC_BTN1,KC_MS_U, KC_BTN2,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_BTN1,  KC_BTN2,  KC_BSLS, \
           KC_TRNS, KC_MS_L,KC_MS_D, KC_MS_R,KC_PGDN,KC_NO,  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_NO,  KC_BSLS,  KC_ENT, \
           KC_BSPC, KC_VOLD,KC_VOLU, KC_NO,  KC_NO,  KC_PGUP,  KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_NO, KC_BSPC,KC_TRNS, \
                KC_TRNS,KC_TRNS,          KC_SPC,                KC_TRNS,KC_TRNS),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer(not used)
    [2] = ACTION_DEFAULT_LAYER_SET(3),          // Vi layer with Slash*
    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),           // Mousekey layer with Semicolon*
    [4] = ACTION_LAYER_TAP_KEY(1, KC_TAB),            // Mousekey layer with Space
    [5] = ACTION_LAYER_MOMENTARY(4),                  // Mousekey layer(IJKL)
    [6] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ENT),      // RControl with tap Enter
    [7] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC),      // RControl with tap Enter
    [9] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT),
   [10] = ACTION_MODS_KEY(MOD_LALT, KC_RIGHT),
   [11] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_GRV),      // Tilde/Grave with tap LAlt
   [12] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),      // Tap Esc or Ctrl
   [13] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_BSPC),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

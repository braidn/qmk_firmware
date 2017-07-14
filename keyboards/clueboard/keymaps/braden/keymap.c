#include "clueboard.h"

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define _______ KC_TRNS

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _CL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = KEYMAP(
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,          KC_PGUP, \
  KC_FN4,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,                   KC_PGDN, \
  KC_FN12, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                             \
  KC_LSPO, KC_NUBS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSPC,  OSM(MOD_RSFT),          KC_UP,            \
  KC_CAPS, KC_FN13, KC_FN6, KC_MHEN,          KC_SPC,KC_SPC,                         KC_HENK,  KC_RGUI,  KC_FN11,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   */
[_FL] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______, KC_DEL,           BL_STEP, \
  _______, _______, KC_MS_U,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK, KC_PAUS,  _______,  _______,  _______,                   _______, \
  _______, KC_MS_L, KC_MS_D,KC_MS_R,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,_______,  _______,  _______,  _______,                           \
  _______, KC_VOLD, KC_VOLU,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  MO(_CL),          KC_PGUP,         \
  _______, _______, _______, _______,        _______,_______,                        _______,  _______,  _______,  _______, KC_HOME, KC_PGDN, KC_END),

  /* Keymap _CL: Control layer
   */
[_CL] = KEYMAP(
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______, RGB_TOG,             RGB_VAI, \
  _______, _______, _______,_______,RESET,  _______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   RGB_VAD, \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                         \
  MO(_FL), _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  MO(_FL),          RGB_SAI,          \
  _______, _______, _______,_______,        RGB_MOD,   RGB_MOD,                            _______,  _______,  _______,  _______, RGB_HUD,    RGB_SAD,    RGB_HUI),
};

/* This is a list of user defined functions. F(N) corresponds to item N
   of this list.
 */
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
  [1] = ACTION_MODS_TAP_KEY(MOD_RSFT, OSL(1)),                 // HHKB layer(toggle with 5 taps)
  [2] = ACTION_DEFAULT_LAYER_SET(2),          // Vi layer with Slash*
  [4] = ACTION_LAYER_TAP_KEY(1, KC_TAB),            // Mousekey layer with Space
  [6] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ENT),      // RControl with tap Enter
  [5] = ACTION_LAYER_ONESHOT(2),                  // Mousekey layer(IJKL)
  [9] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT),
  [10] = ACTION_MODS_KEY(MOD_LALT, KC_RIGHT),
  [11] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_GRV),      // Tilde/Grave with tap LAlt
  [12] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),      // Tap Esc or Ctrl
  [13] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_BSPC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mods_pressed;
  static bool mod_flag;

  switch (id) {
    case 0:
      /* Handle the combined Grave/Esc key
       */
      mods_pressed = get_mods()&GRAVE_MODS; // Check to see what mods are pressed

      if (record->event.pressed) {
        /* The key is being pressed.
         */
        if (mods_pressed) {
          mod_flag = true;
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        /* The key is being released.
         */
        if (mod_flag) {
          mod_flag = false;
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

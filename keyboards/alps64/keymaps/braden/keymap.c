#include "alps64.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV, \
           FN5, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
           FN7, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,  \
           LSPO, NUBS, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSPC,FN1, \
           CAPS,FN10,FN9,          SPC,                     RGUI, FN8,FN0,FN0),
  [1] = \
    KEYMAP(TRNS, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS, FN4, \
           TRNS, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   TRNS,TRNS,DEL, \
           TRNS, VOLU,VOLD,D,   F,   G,   LEFT,DOWN,UP,  RGHT,TRNS,TRNS,TRNS,  \
           TRNS, TRNS,Z,   X,   C,   V,   B,   N,   M,   TRNS,TRNS,TRNS,TRNS,TRNS, \
           TRNS, TRNS,TRNS,          TRNS,                     TRNS, TRNS,FN3,TRNS),
  [2] = \
    KEYMAP(TRNS, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV, \
           TRNS, Q,   W,   D,   F,   K,   J,   U,   R,   L,   SCLN,LBRC,RBRC,BSPC, \
           TRNS, A,   S,   E,   T,   G,   Y,   N,   I,   O,   H,QUOT,ENT,  \
           TRNS, TRNS, Z,   X,   C,   V,   B,   P,   M,   COMM,DOT, SLSH,RSFT,FN1, \
           TRNS, TRNS,TRNS,          TRNS,                     TRNS, TRNS,TRNS,FN0),
};
/* id for user defined function/macro */
enum function_id {
    NONE,
};

enum macro_id {
    ALT_TAB,
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),
  [1] = ACTION_DEFAULT_LAYER_SET(1),
  [2] = ACTION_MACRO(ALT_TAB),
  [3] = ACTION_DEFAULT_LAYER_SET(0),
  [4] = ACTION_DEFAULT_LAYER_SET(2),
  [5] = ACTION_LAYER_TAP_KEY(1, KC_TAB),
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),  // Backspace with tap LShift
  [7] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),   // Esc with tap caps lock/control
  [8] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_GRV),   // Grave with tap right alt
  [9] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ENT),    // Enter with tap left GUI
  [10] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC)    // Enter with tap left ALT
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), END ));
    }
    return MACRO_NONE;
}

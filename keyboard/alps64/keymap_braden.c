#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  [0] = KEYMAP( \ 
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV, BSLS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,  \
        LSFT,FN3,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN1, \
        LCTL,LALT,LGUI,          SPC,                     RGUI, RALT,RCTL,FN0),
  /* Vim Movement */
  [1] = KEYMAP( \ 
        TRNS, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10,  F11,F12, TRNS, TRNS, \
        TRNS, Q,   W,   E,   R,   T,   Y,   PGUP,   I,   O,   P,   TRNS,TRNS,DEL, \
        TRNS,A,   S,   PGDN,   F,   G,   LEFT,   DOWN,   UP,   RGHT,   TRNS,TRNS,TRNS,  \
        TRNS,TRNS,Z,   X,   C,   V,   B,   N,   M,   TRNS,TRNS, TRNS,TRNS,FN3, \
        TRNS,TRNS,TRNS,          TRNS,                     TRNS, TRNS,TRNS,TRNS),
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

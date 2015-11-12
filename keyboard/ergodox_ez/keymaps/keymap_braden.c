#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define WORK 1 // workman layout
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP(  // Layer0: default, leftled:none
        // left hand
        KC_ESC,       KC_1,   KC_2,   KC_3,   KC_4,   KC_5,  KC_MINS,
        KC_TAB,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_BSLS,
        CTL_T(KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_LBRC,
        KC_F9,        KC_F10, KC_F11, KC_F12, KC_VOLU,
                                      KC_LGUI, KC_LALT,
                                               KC_LCTL,
                              KC_SPC, KC_BSPC, TG(2),
        // right hand
             KC_EQL, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_GRV,
             KC_QUOT,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSPC,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENT,
             KC_RBRC,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                       KC_VOLD,KC_LEFT,KC_UP,  KC_DOWN, KC_RGHT,
        KC_RALT, KC_RGUI,
        KC_RCTL,
        TG(1), KC_ENT, KC_SPC
    ),

[WORK] = KEYMAP(  // Layer1: Workman layout, leftled:all
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_Q,   KC_D,   KC_R,   KC_W,   KC_B,   KC_TRNS,
        KC_TRNS,KC_A,   KC_S,   KC_H,   KC_T,   KC_G,
        KC_TRNS,KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                              KC_TRNS,
                              KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
             KC_TRNS,KC_J,   KC_F,   KC_U,   KC_P,   KC_SLSH,KC_TRNS,
                     KC_Y,   KC_N,   KC_E,   KC_O,   KC_I,   KC_TRNS,
             KC_TRNS,KC_K,   KC_L,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

[MDIA] = KEYMAP(  // Layer2: numpad, leftled:blue
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,   KC_NO,   KC_TRNS,
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS,  KC_TRNS,
                                                KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PGUP,
                      KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PGDN,
             KC_TRNS, KC_FN17, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_PENT,
                       KC_P0, KC_PDOT, KC_SLSH, KC_NO, KC_NO,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_BTN1,KC_BTN2
    ),


};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(WORK)                // FN1 - Momentary Layer 1 (Symbols)
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

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

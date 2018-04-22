#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define MDIA 1 // media keys
#define WORK 2 // workman layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP(  // Layer0: default, leftled:none
        // left hand
        KC_MINS,      KC_1,   KC_2,   KC_3,   KC_4,   KC_5,  KC_GRV,
        KC_FN5,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_BSLS,
        KC_FN3,       KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSPO,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_LBRC,
        KC_VOLU,      KC_LCTL,KC_LALT,KC_LGUI,KC_LPRN,
                                      KC_LGUI, KC_LALT, // Top 2 1u thumb cluster
                                               KC_LCTL, // Single 1u thumb cluster
                                 KC_FN6, KC_ENT, TG(2), // Enter/Space/Lower 1u thumb cluster
        // right hand
             KC_ESC, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_EQL,
             KC_QUOT,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSPC,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENT,
             KC_RBRC,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSPC,
                       KC_RPRN,KC_RGUI,KC_RALT,  KC_RCTL, KC_VOLD,
        KC_FN4, KC_RGUI, // Top 2 1u thumb cluster
        KC_RCTL, // Single 1u thumb cluster
        TG(1), KC_BSPC, KC_FN6 // Enter/Space/Lower 1u thumb cluster
    ),

[MDIA] = KEYMAP(  // Layer2: numpad, leftled:blue
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_MINS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_EQL,  KC_4, KC_5, KC_6, KC_TRNS,
        KC_TRNS, KC_0,    KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS,  KC_TRNS,
                                                KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PGUP,
                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_PGDN,
             KC_TRNS, KC_FN17, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_PENT,
                       KC_P0, KC_PDOT, KC_SLSH, KC_NO, KC_NO,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_BTN1,KC_BTN2
    ),

[WORK] = KEYMAP(  // Layer1: Workman layout, leftled:all
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_Q,   KC_W,   KC_D,   KC_F,   KC_K,   KC_TRNS,
        KC_TRNS,KC_A,   KC_S,   KC_E,   KC_T,   KC_G,
        KC_TRNS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                              KC_TRNS,
                              KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
             KC_TRNS,KC_J,   KC_U,   KC_R,   KC_L,   KC_SCLN,KC_TRNS,
                     KC_Y,   KC_N,   KC_I,   KC_O,   KC_H,   KC_TRNS,
             KC_TRNS,KC_P,   KC_M,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MDIA),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(WORK),                // FN1 - Momentary Layer 1 (Symbols)
    [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),        // Tap Esc or Ctrl
    [4] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_GRV),        // Grave with tap right alt
    [5] = ACTION_LAYER_TAP_KEY(1, KC_TAB),               // FN/Mouse Layer layer with Tab
    [6] = ACTION_LAYER_TAP_KEY(1, KC_SPC)               // FN/Mouse Layer layer with Space
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
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

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

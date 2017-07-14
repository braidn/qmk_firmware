/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "whitefox.h"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Ins|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del|
     * |---------------------------------------------------------------|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
     * |---------------------------------------------------------------|
     * |Shif|   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space    |Fn0 |Alt |Gui |  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP( \
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_GRV, KC_ESC, \
        KC_FN5, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC,     KC_DEL, \
        KC_FN7,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,      KC_PGUP, \
        KC_LSPO,KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSPC,     KC_UP,  KC_PGDN, \
        KC_CAPS,KC_LALT,KC_FN8,               KC_SPC,           KC_RGUI,KC_RALT,KC_TRNS,     KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    [1] = KEYMAP( \
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12, KC_TRNS,KC_TRNS, KC_FN4, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_FN3, \
        KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, \
        KC_TRNS, KC_BSPC,KC_TRNS,               KC_TRNS,           KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS \
    ),
    [2] = KEYMAP( \
        KC_TRNS, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_GRV, KC_ESC, \
        KC_FN5,  KC_Q,   KC_W,   KC_D,   KC_F,   KC_K,   KC_J,   KC_U,   KC_R,   KC_L,   KC_SCLN,   KC_LBRC,KC_RBRC,KC_BSPC,  KC_DEL, \
        KC_TRNS, KC_A,   KC_S,   KC_E,   KC_T,   KC_G,   KC_Y,   KC_N,   KC_I,   KC_O,   KC_H,KC_QUOT,KC_NUHS,KC_ENT,      KC_PGUP, \
        KC_TRNS,KC_TRNS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_P,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,  KC_PGDN, \
        KC_TRNS,KC_TRNS,KC_TRNS,               KC_TRNS,           KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS \
    ),
};

const uint16_t fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),
  [1] = ACTION_DEFAULT_LAYER_SET(1),
  [3] = ACTION_DEFAULT_LAYER_SET(0),
  [4] = ACTION_DEFAULT_LAYER_SET(2),
  [5] = ACTION_LAYER_TAP_KEY(1, KC_TAB),
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),      // Backspace with tap LShift
  [7] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [8] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ENT)    // Enter with tap left GUI
};

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Default Layer in QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   [    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Tab/Shf|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl/~|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   ]    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      | Caps | LAlt | LGui |                                       | RGui |      |      |      |      |
     *   |      |      |      | Spc  | Esc  |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | BkSp |  Del |------|       |------| Enter| Space|
     *                                 |      |      |  Esc |       | Ins  |      |      |
     *                                 | LCtl | LSft | LAlt |       | RAlt | RSft | RCtl |
     *                                 `--------------------'       `--------------------'
     *
     * Keymap: Default Layer in Workman
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   D  |   R  |   W  |   B  |      |           |      |   J  |   F  |   U  |   P  |   $  |   :    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Tab/Shf|   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   -    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  |   |    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      | Caps | LAlt | LGui |                                       | RGui |      |      |      |      |
     *   |      |      |      | Spc  | Esc  |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | BkSp |  Del |------|       |------| Enter| Space|
     *                                 |      |      |  Esc |       | Ins  |      |      |
     *                                 | LCtl | LSft | LAlt |       | RAlt | RSft | RCtl |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(  // Layer0: default, leftled:none
        // left hand
        ESC, 1,   2,   3,   4,   5,  MINS,
        TAB, Q,   W,   E,   R,   T,  BSLS,
        LCTL,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,  LBRC,
        F9,  F10, F11, F12, VOLU,
                                      LGUI, LALT,
                                            LCTL,
                                 SPC, BSPC, FN24,
        // right hand
             EQL, 6,   7,   8,   9,   0,    GRV,
             QUOT,Y,   U,   I,   O,   P,    BSPC,
                  H,   J,   K,   L,   SCLN, ENT,
             RBRC,N,   M,   COMM,DOT, SLSH,   RSFT,
                       VOLD,LEFT,UP,  DOWN, RGHT,
        RALT, RGUI,
        RCTL,
        FN23, ENT, SPC
    ),

    KEYMAP(  // Layer1: Workman layout, leftled:all
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,Q,   D,   R,   W,   B,   TRNS,
        TRNS,A,   S,   H,   T,   G,
        TRNS,Z,   X,   M,   C,   V,   TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,J,   F,   U,   P,   SLSH,TRNS,
                  Y,   N,   E,   O,   I,   TRNS,
             TRNS,K,   L,   TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer2: numpad, leftled:blue
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,BTN1,MS_U,BTN2, NO,  NO,  TRNS,
        TRNS,MS_L,MS_D,MS_R, TRNS,NO,
        TRNS,NO,  NO,  NO,  TRNS,NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,NLCK,P7,  P8,  P9,  PMNS,PGUP,
                  PAST,P4,  P5,  P6,  PPLS,PGDN,
             TRNS,FN17,P1,  P2,  P3,  PSLS,PENT,
                       P0,  PDOT,SLSH,NO,  NO,
        TRNS,TRNS,
        TRNS,
        TRNS,BTN1,BTN2
    ),
/*
    // templates to copy from

    KEYMAP(  // LayerN: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [21] = ACTION_FUNCTION(TEENSY_KEY),                    // Teensy key

    // Layers switching
    [22] = ACTION_LAYER_SET(0, ON_BOTH),                   // set Layer0
    [23] = ACTION_LAYER_TOGGLE(1),                   // set Layer1, to use Workman layout at firmware level
    [24] = ACTION_LAYER_TOGGLE(2),                   // set Layer2, to use with Numpad keys

    [25] = ACTION_LAYER_MOMENTARY(2),                      // UNUSED:  momentary Layer2, to use with Numpad keys
    /* [26] = ACTION_LAYER_TAP_KEY(5, KC_F),                  // momentary Layer5, to use with cursor */
    /* [27] = ACTION_LAYER_TAP_KEY(6, KC_SCLN),               // tapping ; Layer6, to use with F1-F10, Workman-layer switch, Teensy, layer switches */
    /* [28] = ACTION_LAYER_MOMENTARY(7),                      // UNUSED: momentary Layer7, to use with F* keys (F1-F24) */

    /* [29] = ACTION_LAYER_TAP_KEY(4, KC_Z),                  // momentary Layer4 on Z key, to use with unconvenient keys */
    /* [30] = ACTION_LAYER_TAP_KEY(3, KC_X),                  // momentary Layer3 on X key, to use with F* keys */
    /* [31] = ACTION_LAYER_TAP_KEY(8, KC_C),                  // momentary Layer8 on C key, to use with mouse and navigation keys */
    [32] = ACTION_LAYER_TAP_KEY(2, KC_V),                  // momentary Layer2 on V key, to use with Numpad keys

    // i'd like to remove this - will try to get used to live without this and convert them to usual keys
    /* [33] = ACTION_LAYER_TAP_KEY(4, KC_A),                  // momentary Layer4 on A key, to use with unconvenient keys */
    /* [34] = ACTION_LAYER_TAP_KEY(3, KC_S),                  // momentary Layer3 on S key, to use with F* keys */
    /* [35] = ACTION_LAYER_TAP_KEY(8, KC_D),                  // momentary Layer8 on D key, to use with mouse and navigation keys */
    [36] = ACTION_LAYER_TAP_KEY(2, KC_F),                  // UNUSED: momentary Layer2 on F key, to use with Numpad keys
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}


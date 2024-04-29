#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

#define ALT_TAB_TIME 1000

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAMING,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_GITCON
};

enum {
    TD_WIN_NUM,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_WIN_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RGUI, _NUMPAD)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
   KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_CAPS,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   ES_GRV,
   KC_TAB,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  ES_ACUT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    _______,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTRL, KC_LOWER, KC_ENT,      KC_SPC,  KC_RAISE, KC_RCTRL, KC_RALT, TD(TD_WIN_NUM)
),
/*
 * GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | SPC  |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_GAMING] = LAYOUT(
   KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
   KC_TAB,  KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   ES_GRV,
  KC_LSFT,  KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  ES_ACUT,
 KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,    XXXXXXX,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                   KC_LGUI,KC_LALT,KC_SPC, KC_LOWER, KC_SPC,      KC_ENT,  KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |NumLck|   /  |   *  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   7  |   8  |   9  |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /       /       \Enter \  |RAISE |   0  |   .  | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  _______ , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX,  KC_NUM, KC_PSLS, KC_PAST, XXXXXXX, _______,
  _______ , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,
  _______ , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,
  _______ , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, _______,
                   _______, _______, _______, _______, XXXXXXX,         KC_PENT, _______, KC_KP_0, KC_PDOT, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  º   |  !   |  "   |  ·   |  $   |  %   |                    |  &   |  /   |  (   |  )   |  =   | Bcks |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |  F10 |  F5  |  F11 |                    |   {  |   }  |      |   '  |   ¡  |   +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |   <  |   >  |-------.    ,-------|   (  |   )  |      |      |      |   Ç  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |   <  |  >   |      |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  ES_MORD, ES_EXLM,    ES_DQUO, ES_BULT,        ES_DLR,       ES_PERC,                               ES_AMPR,       ES_SLSH,    ES_LPRN,   ES_RPRN,     ES_EQL, _______,
  _______, _______,    _______,  KC_F10,         KC_F5,        KC_F11,                         ALGR(ES_ACUT), ALGR(ES_CCED),    _______,   ES_QUOT,    ES_IEXL, ES_PLUS,
  _______, _______,    _______, _______,       ES_LABK,    S(ES_LABK),                               S(KC_8),       S(KC_9),    _______,   _______,    _______, ES_CCED,
  _______, ES_LABK, S(ES_LABK), _______, ALGR(ES_ACUT), ALGR(ES_CCED), _______,       _______,  ALGR(ES_GRV), ALGR(ES_PLUS), S(KC_COMM), S(KC_DOT), S(KC_SLSH), _______,
                                _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAt  | LCtl |LShift|      |      |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
KC_GITCON,   KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,                            KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
  _______,  KC_INS, KC_PSCR,  KC_APP,  XXXXXXX, XXXXXXX,                          KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD, KC_DLINE,  KC_F12,
  _______, KC_LALT, KC_LCTL, KC_LSFT,  XXXXXXX, XXXXXXX,                          KC_PGDN,  KC_LEFT, KC_DOWN,  KC_RGHT,   KC_DEL, KC_BSPC,
  _______, KC_UNDO,  KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX,  KC_LEND,  XXXXXXX, _______,
                 _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|GAMING|      |      |                    |      | MODUP| RGB  | BRIUP|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX, XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RESET   , XXXXXXX, KC_QWERTY,KC_GAMING ,XXXXXXX, XXXXXXX,                       XXXXXXX, RGB_MOD, RGB_TOG, RGB_VAI, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, CG_TOGG, XXXXXXX,    XXXXXXX, XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  _______ , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Gmng"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _GAMING:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpd"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

void matrix_scan_user(void) {
    // reset alt+tab timer
    if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > ALT_TAB_TIME) {
        unregister_code(KC_LALT);
        unregister_code(KC_LSHIFT);
        is_alt_tab_active = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_GITCON:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(ES_MORD);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(ES_MORD);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

void alt_tab_encoder(bool clockwise) {
    if (clockwise) {
            is_alt_tab_active = true;
            unregister_code(KC_LSHIFT);
            register_code(KC_LALT);
    } else {
            is_alt_tab_active = true;
            register_code(KC_LALT);
            register_code(KC_LSHIFT);
    }
    alt_tab_timer = timer_read();
    tap_code(KC_TAB);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        alt_tab_encoder(clockwise);
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_F3);
        } else {
            tap_code16(S(KC_F3));
        }
    }
    return true;
}

#endif

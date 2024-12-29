/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    BASE,
    NO_NUMPAD,
    NO_MOD,
    NO_KB,
    FN,
};

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    UNDO,
    REDO,
    REVIVE,
    SET_ALL,
    SET_NPD,
    SET_MOD,
    SET_NKB,
};

    // [TRANSPARENT] = LAYOUT_ansi_101(
    //     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,    _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,    _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,  _______,  _______,  _______,    _______,
    //     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,            _______,  _______,  _______,
    //     _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______,            _______,  _______,    _______),

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_101(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,             KC_PSCR,  KC_MPRV,  KC_MPLY,  KC_MNXT,    XXXXXXX,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,    KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_DEL,   KC_P4,    KC_P5,    KC_P6,      KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_F14,   MO(FN),     KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,            KC_P0,    KC_PDOT,    KC_PENT),

    [NO_NUMPAD] = LAYOUT_ansi_101(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______,            XXXXXXX,  XXXXXXX,    XXXXXXX),

    [NO_MOD] = LAYOUT_ansi_101(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            XXXXXXX,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            XXXXXXX,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            XXXXXXX,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            XXXXXXX,  _______,  _______,  _______,    _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  XXXXXXX,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,            _______,  _______,    _______),

    [NO_KB] = LAYOUT_ansi_101(
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            _______,  _______,  _______,  _______,    _______,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            _______,  _______,  _______,  _______,    _______,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            _______,  _______,  _______,  _______,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            _______,  _______,  _______,  _______,    _______,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  _______,            _______,  _______,  _______,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  _______,    XXXXXXX,  _______,  _______,  _______,            _______,  _______,    _______),

    [FN] = LAYOUT_ansi_101(
        XXXXXXX,            KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,     KC_F23,   KC_F24,             XXXXXXX,  PB_1,     PB_2,     PB_3,    XXXXXXX,
        XXXXXXX,  SET_ALL,  SET_NPD,  SET_MOD,  SET_NKB,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            KC_INS,   XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            KC_HOME,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            KC_END,   XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BAT_LVL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EMAIL,                XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                KC_F14,   _______,    REVIVE,   XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = {ENCODER_CCW_CW(UNDO, REDO)},
    [NO_NUMPAD]   = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
    [NO_MOD]   = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
    [NO_KB]   = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
    [FN]   = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
};
#endif // ENCODER_MAP_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EMAIL:
        if (record->event.pressed) {
            SEND_STRING("matthewmanley.97@gmail.com");
        }
        break;

    case UNDO:
        if (record->event.pressed) {
            register_code(KC_LEFT_CTRL);
            tap_code(KC_Z);
            unregister_code(KC_LEFT_CTRL);
        }
        break;

    case REDO:
        if (record->event.pressed) {
            register_code(KC_LEFT_CTRL);
            tap_code(KC_Y);
            unregister_code(KC_LEFT_CTRL);
        }
        break;
    case REVIVE:
        if (record->event.pressed) {
            SEND_STRING_DELAY(
                SS_DOWN(X_LEFT_CTRL)
                SS_TAP(X_UP)
                SS_TAP(X_DOWN)
                SS_TAP(X_RIGHT)
                SS_TAP(X_LEFT)
                SS_TAP(X_UP)
                SS_UP(X_LEFT_CTRL), 20);
        }
        break;
    case SET_ALL:
        if (record->event.pressed) {
            layer_off(NO_NUMPAD);
            layer_off(NO_MOD);
            layer_off(NO_KB);
        }
        break;
    case SET_NPD:
        if (record->event.pressed) {
            layer_on(NO_NUMPAD);
            layer_off(NO_MOD);
            layer_off(NO_KB);
        }
        break;
    case SET_MOD:
        if (record->event.pressed) {
            layer_on(NO_NUMPAD);
            layer_on(NO_MOD);
            layer_off(NO_KB);
        }
        break;
    case SET_NKB:
        if (record->event.pressed) {
            layer_on(NO_NUMPAD);
            layer_on(NO_MOD);
            layer_on(NO_KB);
        }
        break;
    }
    

    return true;
};

// When hitting FN + the three buttons above the keyboard simultaneously, put the kb into flash mode
const uint16_t PROGMEM test_combo1[] = {PB_1, PB_2, PB_3, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_combo1, QK_BOOTLOADER),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (IS_LAYER_ON(FN)) {
        rgb_matrix_set_color(18, RGB_WHITE);
        rgb_matrix_set_color(19, RGB_WHITE);
        rgb_matrix_set_color(20, RGB_WHITE);
        rgb_matrix_set_color(21, RGB_WHITE);
        rgb_matrix_set_color(36, RGB_WHITE);
        rgb_matrix_set_color(81, RGB_WHITE);
        return false;
    }
    bool is_no_kb_on = IS_LAYER_ON(NO_KB);
    bool is_no_mod_on = IS_LAYER_ON(NO_MOD);
    bool is_no_numpad_on = IS_LAYER_ON(NO_NUMPAD);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                if (is_no_kb_on && keymap_key_to_keycode(NO_KB, (keypos_t){col,row}) == XXXXXXX) {
                    rgb_matrix_set_color(index, RGB_RED);
                    continue;
                }
                if (is_no_mod_on && keymap_key_to_keycode(NO_MOD, (keypos_t){col,row}) == XXXXXXX) {
                    rgb_matrix_set_color(index, RGB_RED);
                    continue;
                }
                if (is_no_numpad_on && keymap_key_to_keycode(NO_NUMPAD, (keypos_t){col,row}) == XXXXXXX) {
                    rgb_matrix_set_color(index, RGB_RED);
                    continue;
                }
            }
        }
    }
    
    led_t led_state = host_keyboard_led_state();
    if (!is_no_numpad_on && led_state.num_lock) {
        rgb_matrix_set_color(32, RGB_WHITE);
    }
    if (!is_no_kb_on && led_state.caps_lock) {
        rgb_matrix_set_color(55, RGB_WHITE);
    }
    return false;
}
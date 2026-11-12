// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "color.h"
#include "keycodes.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "send_string_keycodes.h"
#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "sendstring_german.h"

enum LAYERS {
    L_BASE = 0,
    L_SYMBOL_1,
    L_SYMBOL_2,
    L_ARROW,
    L_NUMPAD,
    L_MACROS,
    L_UMLAUT,
    L_GAMING,
    L_DEBUG,
};

enum MACROS {
    M_UPDIR = QK_USER,
    M_CDUPDIR,
    M_THINARR,
    M_THICKARR,
    M_DESKNEXT,
    M_DESKPREV,
    M_GHOSTTY_SPLIT_LEFT,
    M_GHOSTTY_SPLIT_RIGHT,
    M_SCREENMAC,
    M_SPOTLIGHT,
    M_MINECRAFT_CHAT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

// Base
[L_BASE] = LAYOUT_split_4x6_5(
LT(L_DEBUG, KC_ESC), DE_1,   DE_2,    DE_3,    DE_4,    DE_5,                        DE_6,    DE_7,    DE_8,    DE_9,        DE_0,  MO(L_DEBUG),
      KC_ESC,  DE_Q,   DE_W,    DE_F,    DE_P,    DE_G,                        DE_N,    DE_I,    DE_U,    DE_Y,     DE_SCLN,  MO(L_MACROS),
LT(L_NUMPAD, KC_TAB),LSFT_T(DE_A),   DE_R,    LT(L_SYMBOL_2, DE_S),    LT(L_SYMBOL_1, DE_T),    LT(L_ARROW, DE_D),                        DE_H,    LT(L_SYMBOL_1, DE_J),    LT(L_SYMBOL_2, DE_K),    DE_L, RSFT_T(DE_O), MO(L_NUMPAD),
      KC_LSFT, DE_Z,   DE_X,    DE_C,    DE_V,    DE_B, KC_MUTE, KC_CAPS_LOCK, DE_M,    DE_E, DE_COMM,  DE_DOT, DE_SLSH,  KC_RSFT,
                      MO(L_UMLAUT), KC_LALT, KC_LCTL, KC_LGUI, KC_ENT,     KC_SPC, KC_BSPC, KC_RCTL, KC_RALT,   MO(L_UMLAUT)
),

// Base symbol 1
[L_SYMBOL_1] = LAYOUT_split_4x6_5(
      _______,_______,_______,DE_CIRC,S(DE_CIRC),_______,                            _______,DE_CIRC,S(DE_CIRC),_______,_______,_______,
      _______, DE_EQL,DE_MINS,A(DE_8),A(DE_9),DE_COLN,                            DE_COLN,A(DE_8),A(DE_9),DE_MINS, DE_EQL,_______,
      _______,DE_DQUO,DE_QUOT,DE_LPRN,DE_RPRN,DE_SCLN,                            DE_SCLN,DE_LPRN,DE_RPRN,DE_QUOT,DE_DQUO,_______,
      _______,DE_COMM, DE_DOT,A(DE_5),A(DE_6),DE_SLSH,_______,            _______,DE_SLSH,A(DE_5),A(DE_6), DE_DOT,DE_COMM,_______,
                      _______,_______,_______,_______, KC_ESC,             KC_ESC,_______,_______,_______,_______
),

// Base Symbol 2
[L_SYMBOL_2] = LAYOUT_split_4x6_5(
      _______,_______,_______,_______,DE_LABK,_______,                            _______,DE_LABK,_______,_______,_______,_______,
      _______,A(DE_7),DE_UNDS,A(DE_L),DE_AMPR,DE_HASH,                            DE_UNDS,DE_AMPR,A(DE_L),DE_HASH,A(DE_7),_______,
   _______,S(A(DE_7)),A(DE_N),DE_PERC, DE_DLR,DE_ASTR,                            DE_ASTR, DE_DLR,DE_PERC,A(DE_N),S(A(DE_7)),_______,
      _______,_______, DE_GRV,DE_EXLM,DE_SLSH,DE_QUES,_______,            _______,DE_QUES,DE_SLSH,DE_EXLM, DE_GRV,_______,_______,
                      _______,_______,_______,_______, KC_ESC,             KC_ESC,_______,_______,_______,_______
),

// Arrow Keys
[L_ARROW] = LAYOUT_split_4x6_5(
      _______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                            KC_LEFT,KC_DOWN,  KC_UP,KC_RIGHT,_______,_______,
      _______,_______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,_______,
                      _______,_______,_______,_______,_______,            _______,_______,_______,_______,_______
),

// F-Keys and Numpad
[L_NUMPAD] = LAYOUT_split_4x6_5(
      _______,_______, KC_F10, KC_F11, KC_F12,_______,                            DE_PLUS,DE_MINS,DE_ASTR,DE_SLSH,_______,_______,
      _______,_______,  KC_F7,  KC_F8,  KC_F9,_______,                            _______,   DE_7,   DE_8,   DE_9,_______,_______,
      _______,_______,  KC_F4,  KC_F5,  KC_F6,_______,                            _______,   DE_4,   DE_5,   DE_6,DE_COMM,_______,
      _______,_______,  KC_F1,  KC_F2,  KC_F3,_______,_______,            _______,   DE_0,   DE_1,   DE_2,   DE_3, DE_DOT,_______,
                      _______,_______,_______,_______,_______,            _______,_______,_______,_______,_______
),

// Macros
[L_MACROS] = LAYOUT_split_4x6_5(
      _______,_______,_______,M_DESKPREV,M_DESKNEXT,_______,                      _______,_______,_______,_______,_______,_______,
      _______,_______,_______,M_GHOSTTY_SPLIT_LEFT,M_GHOSTTY_SPLIT_RIGHT,_______,                            _______,_______,_______,_______,_______,_______,
      _______,_______,_______,M_THICKARR,M_THINARR,_______,                       _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,_______,
                      _______,_______,_______,M_CDUPDIR,M_UPDIR,        M_SCREENMAC,M_SPOTLIGHT,_______,_______,_______
),

// Umlaute
[L_UMLAUT] = LAYOUT_split_4x6_5(
      _______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                            _______,_______,DE_UDIA,_______,_______,_______,
      _______,DE_ADIA,_______,  DE_SS,_______,_______,                            _______,_______,_______,_______,DE_ODIA,_______,
      _______,_______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,_______,
                      KC_LSFT,_______,_______,_______,_______,            _______,_______,_______,_______,KC_LSFT
),

// Gaming (Minecraft)
[L_GAMING] = LAYOUT_split_4x6_5(
      _______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,_______,
      _______,   DE_Q,   DE_F,   DE_W,   DE_E,_______,                            _______,_______,_______,_______,_______,_______,
      _______,KC_LSFT,   DE_A,   DE_S,   DE_D,_______,                            _______,M_MINECRAFT_CHAT,_______,_______,_______,_______,
      _______,KC_LCTL,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,_______,
                      _______,_______,_______,_______,KC_SPACE,           _______,_______,_______,_______,_______
),

// Boot/Debug/Misc
[L_DEBUG] = LAYOUT_split_4x6_5(
QK_BOOTLOADER,_______,_______,_______,_______, EE_CLR,                             EE_CLR,_______,_______,_______,_______,QK_BOOTLOADER,
      _______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,_______,
                      _______,_______,_______,TG(L_GAMING),_______,       _______,_______,_______,_______,_______
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool minecraft_inside_chat = false;

    switch (keycode) {
        case M_UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
        case M_CDUPDIR:
            if (record->event.pressed) {
                SEND_STRING("cd ../");
            }
            return false;
        case M_DESKNEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_RIGHT))));
            }
            return false;
        case M_DESKPREV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_LEFT))));
            }
            return false;
        case M_GHOSTTY_SPLIT_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_LEFT))));
            }
            return false;
        case M_GHOSTTY_SPLIT_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_RIGHT))));
            }
            return false;
        case M_THINARR:
            if (record->event.pressed) {
                SEND_STRING("-" SS_LSFT("^") SS_TAP(X_BACKSPACE));
            }
            return false;
        case M_THICKARR:
            if (record->event.pressed) {
                SEND_STRING("=" SS_LSFT("^") SS_TAP(X_BACKSPACE));
            }
            return false;
        case M_SCREENMAC:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_LSFT("4"))));
            }
            return false;
        case M_SPOTLIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_LGUI(" ")));
            }
            return false;
        case M_MINECRAFT_CHAT:
            if (record->event.pressed) {
                SEND_STRING("t");
                layer_off(L_GAMING);
                minecraft_inside_chat = true;
            }
            return false;
        case KC_ENTER:
            if (minecraft_inside_chat) {
                minecraft_inside_chat = false;
                SEND_STRING(SS_TAP(X_ENTER));
                layer_on(L_GAMING);
                return false;
            }
            return true;
        case KC_ESC:
        case LT(L_DEBUG, KC_ESC):
            // Holding the layer-tap key should still activate L_DEBUG, only its tap is an Escape
            if (keycode != KC_ESC && !record->tap.count) {
                return true;
            }
            if (minecraft_inside_chat) {
                minecraft_inside_chat = false;
                SEND_STRING(SS_TAP(X_ESCAPE));
                layer_on(L_GAMING);
                return false;
            }
            return true;
        case TG(L_GAMING):
            minecraft_inside_chat = false;
            return true;
    }
    return true;
}

#if defined(ENCODER_MAP_ENABLE)
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP)},
    [L_SYMBOL_1] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [L_SYMBOL_2] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [L_ARROW] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [L_NUMPAD] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [L_MACROS] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [L_UMLAUT] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [L_GAMING] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [L_DEBUG] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
};
// clang-format on
#endif

#ifdef RGB_MATRIX_ENABLE
// clang-format off
const uint8_t layer_colors[][3] = {
    {RGB_OFF}, // Layer 0 (default) - no color
    {RGB_BLUE}, // Layer 1 (Symbol 1)
    {RGB_CYAN}, // Layer 2 (Symbol 2)
    {RGB_GREEN}, // Layer 3 (Arrow)
    {RGB_PURPLE}, // Layer 4 (Numpad)
    {RGB_YELLOW}, // Layer 5 (Macros)
    {RGB_WHITE}, // Layer 6 (Umlaut)
    {RGB_GREEN}, // Layer 7 (Gaming)
    {RGB_RED}, // Layer 8 (Debug)
};
// clang-format on

// L_BASE - off
// L_SYMBOL_1 - blue
// L_SYMBOL_2 - cyan
// L_ARROW - green
// L_NUMPAD - purple
// L_MACROS - yellow
// L_UMLAUT - white
// L_GAMING - white
// L_DEBUG - red
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    if (layer > 0 && layer < (sizeof(layer_colors) / sizeof(layer_colors[0]))) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                    uint16_t active = keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS;
                    if (active) {
                        rgb_matrix_set_color(index, layer_colors[layer][0], layer_colors[layer][1], layer_colors[layer][2]);
                    } else {
                        rgb_matrix_set_color(index, RGB_OFF);
                    }
                }
            }
        }
    }
    return false;
}
#endif // RGB_MATRIX_ENABLE

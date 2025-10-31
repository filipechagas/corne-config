/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <stdint.h>

#define DEFAULT_HUE 0
#define DEFAULT_SAT 255
#define DEFAULT_VAL RGBLIGHT_LIMIT_VAL
#define DEFAULT_SPI 0
#define LAYER_SWITCHED_MODE 5
#define DEFAULT_MODE 13

uint16_t hue = DEFAULT_HUE;
uint16_t sat = DEFAULT_SAT;
uint16_t val = DEFAULT_VAL;
uint16_t spi = DEFAULT_SPI;
uint16_t mod = DEFAULT_MODE;

// Custom space bar state tracking
static bool     space_pressed     = false;
static bool     other_key_pressed = false;
static uint16_t space_timer       = 0;

// Custom keycodes
enum custom_keycodes {
    DASH_ARROW = SAFE_RANGE,
    EQUAL_ARROW,
    TAB_GRAVE,
    LPAR_LT,
    RPAR_GT,
    ZMK_SPC,
};

// Custom keycode processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DASH_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case EQUAL_ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case TAB_GRAVE:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL))) {
                    tap_code(KC_GRAVE);
                } else {
                    tap_code(KC_TAB);
                }
            }
            break;
        case LPAR_LT:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                    tap_code16(KC_LT);
                } else {
                    tap_code16(KC_LPRN);
                }
            }
            break;
        case RPAR_GT:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                    tap_code16(KC_GT);
                } else {
                    tap_code16(KC_RPRN);
                }
            }
            break;
        case ZMK_SPC:
            if (record->event.pressed) {
                space_pressed     = true;
                other_key_pressed = false;
                space_timer       = timer_read();
            } else {
                if (space_pressed) {
                    if (other_key_pressed) {
                        // Another key was pressed during hold - do nothing (GUI already sent)
                    } else {
                        // No other key pressed - send space
                        tap_code(KC_SPC);
                    }
                    space_pressed = false;
                }
            }
            return false; // Prevent normal processing
    }

    // Track if any other key is pressed while space is held
    if (space_pressed && keycode != ZMK_SPC) {
        if (record->event.pressed && !other_key_pressed) {
            other_key_pressed = true;
            // Send GUI modifier
            register_mods(MOD_BIT(KC_LGUI));
        }
    }

    return true;
}

// Per-key tapping term for space bar
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_SPC):
            return 400; // Match ZMK's 400ms for space bar
        default:
            return TAPPING_TERM;
    }
}

// Per-key hold on other key press - space bar should NOT use this
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Space bar should return false to use normal mod-tap behavior
    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: QWERTY (Base Layer) - ZMK Port
    [QWERTY_L] = LAYOUT_split_3x6_3(TAB_GRAVE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, MT(MOD_LCTL, KC_ESC), MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), KC_G, KC_H, MT(MOD_RSFT, KC_J), MT(MOD_RGUI, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RCTL, KC_SCLN), KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, LT(NAV_L, KC_ESC), LT(NUM_L, KC_TAB), ZMK_SPC, KC_ENT, LT(SYM_L, KC_QUOT), LT(ADJ_L, KC_BSPC)),

    // Layer 1: Navigation (NAV_L) - ZMK Port
    [NAV_L] = LAYOUT_split_3x6_3(KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_LCBR), LGUI(KC_RCBR), KC_TRNS, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(FUN_L)),

    // Layer 2: Symbols (SYM_L) - ZMK Port
    [SYM_L] = LAYOUT_split_3x6_3(KC_GRAVE, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_ESC, KC_MINS, KC_DLR, KC_PERC, KC_CIRC, KC_PIPE, KC_TRNS, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS, KC_TRNS, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_GRAVE, KC_UNDS, KC_TRNS, KC_TRNS, KC_TRNS),

    // Layer 3: Adjustment (ADJ_L) - ZMK Port
    [ADJ_L] = LAYOUT_split_3x6_3(KC_GRAVE, KC_TRNS, KC_CAPS, CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, CW_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, MO(FUN_L), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // Layer 4: Numbers (NUM_L) - ZMK Port
    [NUM_L] = LAYOUT_split_3x6_3(LGUI(KC_GRAVE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_BSPC, KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_MINS, KC_4, KC_5, KC_6, KC_PLUS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_COMM, KC_1, KC_2, KC_3, KC_BSLS, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_DOT),

    // Layer 5: Function (FUN_L) - ZMK Port
    [FUN_L] = LAYOUT_split_3x6_3(KC_GRAVE, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, QK_BOOT, KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

#include "combos.c"

#ifdef RGBLIGHT_ENABLE
#    include "rgb.c"
#endif

#ifdef OLED_ENABLE
#    include "oled.c"
#endif
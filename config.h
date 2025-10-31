/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

// #define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// ZMK port timing settings
#define QUICK_TAP_TERM 175
#define TAPPING_TERM 280
#define PERMISSIVE_HOLD
#define REQUIRE_PRIOR_IDLE_MS 50

// Space bar behavior matching ZMK "tap-unless-interrupted"
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM_PER_KEY

// Layer definitions matching ZMK
#define QWERTY_L 0
#define NAV_L 1
#define SYM_L 2
#define ADJ_L 3
#define NUM_L 4
#define FUN_L 5

// Enable caps word
#define CAPS_WORD_IDLE_TIMEOUT 5000

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 16
#    define RGBLIGHT_SAT_STEP 16
#    define RGBLIGHT_VAL_STEP 12
#endif

// #define RETRO_TAPPING
// #define PERMISSIVE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

// Combo settings matching ZMK timing
#define COMBO_TERM 25

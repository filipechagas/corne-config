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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌───────────────────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬─────┐   ┌─────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬──────┐
//        │        tab        │        q        │        w        │        e        │        r        │  t  │   │  y  │        u        │        i        │        o        │        p        │ bspc │
//        ├───────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤   ├─────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼──────┤
//        │ MT(MOD_LCTL, esc) │ MT(MOD_LCTL, a) │ MT(MOD_LALT, s) │ MT(MOD_LGUI, d) │ MT(MOD_LSFT, f) │  g  │   │  h  │ MT(MOD_RSFT, j) │ MT(MOD_RGUI, k) │ MT(MOD_LALT, l) │ MT(MOD_RCTL, ;) │  '   │
//        ├───────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤   ├─────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼──────┤
//        │       lsft        │        z        │        x        │        c        │        v        │  b  │   │  n  │        m        │        ,        │        .        │        /        │ rsft │
//        └───────────────────┴─────────────────┴─────────────────┼─────────────────┼─────────────────┼─────┤   ├─────┼─────────────────┼─────────────────┼─────────────────┴─────────────────┴──────┘
//                                                                │   LT(3, esc)    │   LT(2, tab)    │ spc │   │ ent │    LT(1, ')     │   LT(4, bspc)   │
//                                                                └─────────────────┴─────────────────┴─────┘   └─────┴─────────────────┴─────────────────┘
[0] = LAYOUT_split_3x6_3(
      KC_TAB               , KC_Q               , KC_W               , KC_E               , KC_R               , KC_T   ,     KC_Y   , KC_U               , KC_I               , KC_O               , KC_P                  , KC_BSPC,
      MT(MOD_LCTL, KC_ESC) , MT(MOD_LCTL, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LGUI, KC_D) , MT(MOD_LSFT, KC_F) , KC_G   ,     KC_H   , MT(MOD_RSFT, KC_J) , MT(MOD_RGUI, KC_K) , MT(MOD_LALT, KC_L) , MT(MOD_RCTL, KC_SCLN) , KC_QUOT,
      KC_LSFT              , KC_Z               , KC_X               , KC_C               , KC_V               , KC_B   ,     KC_N   , KC_M               , KC_COMM            , KC_DOT             , KC_SLSH               , KC_RSFT,
                                                                       LT(3, KC_ESC)      , LT(2, KC_TAB)      , KC_SPC ,     KC_ENT , LT(1, KC_QUOT)     , LT(4, KC_BSPC)
),

//        ┌─────┬───┬───┬────┬───┬───┐   ┌─────┬──────┬──────┬──────┬──────┬──────┐
//        │  `  │ { │ & │ *  │ ( │ } │   │     │      │      │      │      │ bspc │
//        ├─────┼───┼───┼────┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┼──────┤
//        │ esc │ - │ $ │ %  │ ^ │ | │   │     │ rsft │ rgui │ lalt │ rctl │      │
//        ├─────┼───┼───┼────┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┼──────┤
//        │     │ ~ │ ! │ @  │ # │ ) │   │     │      │      │      │      │      │
//        └─────┴───┴───┼────┼───┼───┤   ├─────┼──────┼──────┼──────┴──────┴──────┘
//                      │ no │ ` │ _ │   │     │      │      │
//                      └────┴───┴───┘   └─────┴──────┴──────┘
[1] = LAYOUT_split_3x6_3(
      KC_GRV  , KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_BSPC,
      KC_ESC  , KC_MINS , KC_DLR  , KC_PERC , KC_CIRC , KC_PIPE ,     KC_TRNS , KC_RSFT , KC_RGUI , KC_LALT , KC_RCTL , KC_TRNS,
      KC_TRNS , KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_RPRN ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                    XXXXXXX , KC_GRV  , KC_UNDS ,     KC_TRNS , _______ , KC_TRNS
),

//        ┌─────────┬──────┬──────┬──────┬──────┬─────┐   ┌─────┬───┬───┬───┬───┬──────┐
//        │ LGUI(`) │      │      │      │      │     │   │  [  │ 7 │ 8 │ 9 │ ] │ bspc │
//        ├─────────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼───┼───┼───┼───┼──────┤
//        │   esc   │ lctl │ lalt │ lgui │ lsft │     │   │  -  │ 4 │ 5 │ 6 │ + │  =   │
//        ├─────────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼───┼───┼───┼───┼──────┤
//        │         │      │      │      │      │     │   │  ,  │ 1 │ 2 │ 3 │ \ │  /   │
//        └─────────┴──────┴──────┼──────┼──────┼─────┤   ├─────┼───┼───┼───┴───┴──────┘
//                                │      │      │     │   │     │ 0 │ . │
//                                └──────┴──────┴─────┘   └─────┴───┴───┘
[2] = LAYOUT_split_3x6_3(
      LGUI(KC_GRV) , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_LBRC , KC_7 , KC_8   , KC_9 , KC_RBRC , KC_BSPC,
      KC_ESC       , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_TRNS ,     KC_MINS , KC_4 , KC_5   , KC_6 , KC_PLUS , KC_EQL ,
      KC_TRNS      , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_COMM , KC_1 , KC_2   , KC_3 , KC_BSLS , KC_SLSH,
                                         KC_TRNS , _______ , KC_TRNS ,     KC_TRNS , KC_0 , KC_DOT
),

//        ┌─────┬──────┬──────┬──────┬──────┬─────┐   ┌──────┬─────────┬─────────┬──────┬────┬──────┐
//        │  `  │  1   │  2   │  3   │  4   │  5  │   │  6   │  home   │   end   │  9   │ 0  │ bspc │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├──────┼─────────┼─────────┼──────┼────┼──────┤
//        │ esc │ lctl │ lalt │ lgui │ lsft │     │   │ left │  down   │   up    │ rght │ no │  no  │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├──────┼─────────┼─────────┼──────┼────┼──────┤
//        │     │      │      │      │      │     │   │      │ LGUI({) │ LGUI(}) │      │ no │  no  │
//        └─────┴──────┴──────┼──────┼──────┼─────┤   ├──────┼─────────┼─────────┼──────┴────┴──────┘
//                            │      │      │     │   │      │         │  MO(5)  │
//                            └──────┴──────┴─────┘   └──────┴─────────┴─────────┘
[3] = LAYOUT_split_3x6_3(
      KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,     KC_6    , KC_HOME       , KC_END        , KC_9    , KC_0    , KC_BSPC,
      KC_ESC  , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_TRNS ,     KC_LEFT , KC_DOWN       , KC_UP         , KC_RGHT , XXXXXXX , XXXXXXX,
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , LGUI(KC_LCBR) , LGUI(KC_RCBR) , KC_TRNS , XXXXXXX , XXXXXXX,
                                    _______ , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS       , MO(5)
),

//        ┌─────────┬─────────┬─────┬─────────┬─────────┬─────────┐   ┌──────┬──────────────┬──────┬─────┬─────┬─────────┐
//        │ RALT(`) │         │     │ RALT(e) │         │         │   │      │              │      │     │     │         │
//        ├─────────┼─────────┼─────┼─────────┼─────────┼─────────┤   ├──────┼──────────────┼──────┼─────┼─────┼─────────┤
//        │   no    │ RALT(~) │ no  │   no    │ RALT(^) │   no    │   │ mute │ AUDIO_VOL_DOWN │ volu │ no  │ no  │ CW_TOGG │
//        ├─────────┼─────────┼─────┼─────────┼─────────┼─────────┤   ├──────┼──────────────┼──────┼─────┼─────┼─────────┤
//        │   no    │   no    │ no  │ RALT(,) │   no    │   no    │   │  no  │      no      │  no  │ no  │ no  │  caps   │
//        └─────────┴─────────┴─────┼─────────┼─────────┼─────────┤   ├──────┼──────────────┼──────┼─────┴─────┴─────────┘
//                                  │  MO(5)  │ RALT(`) │ RALT(') │   │      │              │      │
//                                  └─────────┴─────────┴─────────┘   └──────┴──────────────┴──────┘
[4] = LAYOUT_split_3x6_3(
      RALT(KC_GRV) , KC_TRNS       , KC_TRNS , RALT(KC_E)    , KC_TRNS       , KC_TRNS       ,     KC_TRNS       , KC_TRNS         , KC_TRNS         , KC_TRNS , KC_TRNS , KC_TRNS,
      XXXXXXX      , RALT(KC_TILD) , XXXXXXX , XXXXXXX       , RALT(KC_CIRC) , XXXXXXX       ,     KC_AUDIO_MUTE , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , XXXXXXX , XXXXXXX , CW_TOGG,
      XXXXXXX      , XXXXXXX       , XXXXXXX , RALT(KC_COMM) , XXXXXXX       , XXXXXXX       ,     XXXXXXX       , XXXXXXX         , XXXXXXX         , XXXXXXX , XXXXXXX , KC_CAPS,
                                               MO(5)         , RALT(KC_GRV)  , RALT(KC_QUOT) ,     KC_TRNS       , _______         , KC_TRNS
),

//        ┌─────┬──────┬──────┬──────┬──────┬─────┐   ┌─────┬─────┬─────┬────┬─────┬─────────┐
//        │  `  │      │      │      │      │     │   │     │ f7  │ f8  │ f9 │ f10 │ QK_BOOT │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼─────┼─────┼────┼─────┼─────────┤
//        │ esc │ lctl │ lalt │ lgui │ lsft │     │   │     │ f4  │ f5  │ f6 │ f11 │         │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼─────┼─────┼────┼─────┼─────────┤
//        │     │      │      │      │      │     │   │     │ f1  │ f2  │ f3 │ f12 │         │
//        └─────┴──────┴──────┼──────┼──────┼─────┤   ├─────┼─────┼─────┼────┴─────┴─────────┘
//                            │      │      │     │   │     │     │     │
//                            └──────┴──────┴─────┘   └─────┴─────┴─────┘
[5] = LAYOUT_split_3x6_3(
      KC_GRV  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_F7   , KC_F8   , KC_F9 , KC_F10 , QK_BOOT,
      KC_ESC  , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_TRNS ,     KC_TRNS , KC_F4   , KC_F5   , KC_F6 , KC_F11 , KC_TRNS,
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_F1   , KC_F2   , KC_F3 , KC_F12 , KC_TRNS,
                                    _______ , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , _______
)
};

#define L_BASE 0
#define L_SYM 1
#define L_NUM 2
#define L_NAV 3
#define L_ADJ 4
#define L_FUN 5

void reset_hsv(void) {
   rgblight_sethsv(hue, sat, val);
}

void fetch_rgb_values(void) {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
    spi = rgblight_get_speed();
    mod = rgblight_get_mode();
}

void matrix_init_user() {
    rgblight_mode(DEFAULT_MODE);
    rgblight_enable();
    reset_hsv();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    fetch_rgb_values();

    switch (get_highest_layer(state)) {
        case L_FUN:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(255, sat, val);
            break;
        case L_ADJ:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(7, sat, val);
            break;
        case L_NAV:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(120, sat, val);
            break;
        case L_NUM:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(79, sat, val);
            break;
        case L_SYM:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(175, sat, val);
            break;
        default: // for any other layers, or the default layer
            rgblight_mode(DEFAULT_MODE);
            rgblight_sethsv(hue, sat, val);
            break;
    }

    return state;
};

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
//        ┌───────────────────┬───┬───┬──────┬───────┬─────┐   ┌─────────────┬───────┬──────┬───┬───┬──────┐
//        │        tab        │ q │ w │  e   │   r   │  t  │   │      y      │   u   │  i   │ o │ p │ bspc │
//        ├───────────────────┼───┼───┼──────┼───────┼─────┤   ├─────────────┼───────┼──────┼───┼───┼──────┤
//        │ MT(MOD_LCTL, esc) │ a │ s │  d   │   f   │  g  │   │      h      │   j   │  k   │ l │ ; │  '   │
//        ├───────────────────┼───┼───┼──────┼───────┼─────┤   ├─────────────┼───────┼──────┼───┼───┼──────┤
//        │       lsft        │ z │ x │  c   │   v   │  b  │   │      n      │   m   │  ,   │ . │ / │ rsft │
//        └───────────────────┴───┴───┼──────┼───────┼─────┤   ├─────────────┼───────┼──────┼───┴───┴──────┘
//                                    │ lgui │ MO(1) │ spc │   │ RGUI_T(ent) │ MO(2) │ ralt │
//                                    └──────┴───────┴─────┘   └─────────────┴───────┴──────┘
[0] = LAYOUT_split_3x6_3(
      KC_TAB               , KC_Q , KC_W , KC_E    , KC_R  , KC_T   ,     KC_Y           , KC_U  , KC_I    , KC_O   , KC_P    , KC_BSPC,
      MT(MOD_LCTL, KC_ESC) , KC_A , KC_S , KC_D    , KC_F  , KC_G   ,     KC_H           , KC_J  , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
      KC_LSFT              , KC_Z , KC_X , KC_C    , KC_V  , KC_B   ,     KC_N           , KC_M  , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                                           KC_LGUI , MO(1) , KC_SPC ,     RGUI_T(KC_ENT) , MO(2) , KC_RALT
),

//        ┌──────┬──────┬──────┬──────┬──────┬─────┐   ┌──────┬───────┬───────────────┬───────────────┬────┬──────┐
//        │ tab  │  1   │  2   │  3   │  4   │  5  │   │  6   │   7   │       8       │       9       │ 0  │ bspc │
//        ├──────┼──────┼──────┼──────┼──────┼─────┤   ├──────┼───────┼───────────────┼───────────────┼────┼──────┤
//        │      │ lgui │ lalt │ lsft │ lctl │ no  │   │ left │ down  │      up       │     rght      │ no │  no  │
//        ├──────┼──────┼──────┼──────┼──────┼─────┤   ├──────┼───────┼───────────────┼───────────────┼────┼──────┤
//        │ lsft │  no  │  no  │  no  │  no  │ no  │   │  no  │  no   │ LGUI(LSFT([)) │ LGUI(LSFT(])) │ no │  no  │
//        └──────┴──────┴──────┼──────┼──────┼─────┤   ├──────┼───────┼───────────────┼───────────────┴────┴──────┘
//                             │      │      │     │   │      │ MO(3) │               │
//                             └──────┴──────┴─────┘   └──────┴───────┴───────────────┘
[1] = LAYOUT_split_3x6_3(
      KC_TAB  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,     KC_6    , KC_7    , KC_8                , KC_9                , KC_0    , KC_BSPC,
      KC_TRNS , KC_LGUI , KC_LALT , KC_LSFT , KC_LCTL , XXXXXXX ,     KC_LEFT , KC_DOWN , KC_UP               , KC_RIGHT            , XXXXXXX , XXXXXXX,
      KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , LGUI(LSFT(KC_LBRC)) , LGUI(LSFT(KC_RBRC)) , XXXXXXX , XXXXXXX,
                                    KC_TRNS , _______ , KC_TRNS ,     KC_TRNS , MO(3)   , KC_TRNS
),

//        ┌──────┬──────┬──────┬──────┬───────┬─────┐   ┌─────┬─────┬─────┬───┬───┬──────┐
//        │ tab  │  !   │  @   │  #   │   $   │  %  │   │  ^  │  &  │  *  │ ( │ ) │ bspc │
//        ├──────┼──────┼──────┼──────┼───────┼─────┤   ├─────┼─────┼─────┼───┼───┼──────┤
//        │      │ lgui │ lalt │ lsft │ lctl  │ no  │   │  -  │  =  │  [  │ ] │ \ │  `   │
//        ├──────┼──────┼──────┼──────┼───────┼─────┤   ├─────┼─────┼─────┼───┼───┼──────┤
//        │ lsft │  no  │  no  │  no  │  no   │ no  │   │  _  │  +  │  {  │ } │ | │  ~   │
//        └──────┴──────┴──────┼──────┼───────┼─────┤   ├─────┼─────┼─────┼───┴───┴──────┘
//                             │      │ MO(3) │     │   │     │     │     │
//                             └──────┴───────┴─────┘   └─────┴─────┴─────┘
[2] = LAYOUT_split_3x6_3(
      KC_TAB  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC,
      KC_TRNS , KC_LGUI , KC_LALT , KC_LSFT , KC_LCTL , XXXXXXX ,     KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
      KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                    KC_TRNS , MO(3)   , KC_TRNS ,     KC_TRNS , _______ , KC_TRNS
),

//        ┌─────────┬─────────┬─────────┬─────────┬─────┬─────┐   ┌─────┬──────┬──────┬────┬────┬────┐
//        │ QK_BOOT │   no    │   no    │   no    │ no  │ no  │   │ no  │  no  │  no  │ no │ no │ no │
//        ├─────────┼─────────┼─────────┼─────────┼─────┼─────┤   ├─────┼──────┼──────┼────┼────┼────┤
//        │ RGB_TOG │ RGB_HUI │ RGB_SAI │ RGB_VAI │ no  │ no  │   │ no  │ vold │ volu │ no │ no │ no │
//        ├─────────┼─────────┼─────────┼─────────┼─────┼─────┤   ├─────┼──────┼──────┼────┼────┼────┤
//        │ RGB_MOD │ RGB_HUD │ RGB_SAD │ RGB_VAD │ no  │ no  │   │ no  │ mute │  no  │ no │ no │ no │
//        └─────────┴─────────┴─────────┼─────────┼─────┼─────┤   ├─────┼──────┼──────┼────┴────┴────┘
//                                      │         │     │     │   │     │      │      │
//                                      └─────────┴─────┴─────┘   └─────┴──────┴──────┘
[3] = LAYOUT_split_3x6_3(
      QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX           , XXXXXXX         , XXXXXXX , XXXXXXX , XXXXXXX,
      RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , XXXXXXX , XXXXXXX , XXXXXXX,
      RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_AUDIO_MUTE     , XXXXXXX         , XXXXXXX , XXXXXXX , XXXXXXX,
                                    KC_TRNS , _______ , KC_TRNS ,     KC_TRNS , _______           , KC_TRNS
)
};

#define L_BASE 0
#define L_LOWER 1
#define L_RAISE 2
#define L_ADJUST 3

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
        case L_ADJUST:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(7, sat, val);
            break;
        case L_RAISE:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(175, sat, val);
            break;
        case L_LOWER:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(79, sat, val);
            break;
        default: // for any other layers, or the default layer
            rgblight_mode(DEFAULT_MODE);
            rgblight_sethsv(hue, sat, val);
            break;
    }

    return state;
};

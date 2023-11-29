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
//        │       rsft        │        z        │        x        │        c        │        v        │  b  │   │  n  │        m        │        ,        │        .        │        /        │ rsft │
//        └───────────────────┴─────────────────┴─────────────────┼─────────────────┼─────────────────┼─────┤   ├─────┼─────────────────┼─────────────────┼─────────────────┴─────────────────┴──────┘
//                                                                │      MO(4)      │      MO(1)      │ spc │   │ ent │      MO(2)      │      MO(3)      │
//                                                                └─────────────────┴─────────────────┴─────┘   └─────┴─────────────────┴─────────────────┘
[0] = LAYOUT_split_3x6_3(
      KC_TAB               , KC_Q               , KC_W               , KC_E               , KC_R               , KC_T   ,     KC_Y   , KC_U               , KC_I               , KC_O               , KC_P                  , KC_BSPC,
      MT(MOD_LCTL, KC_ESC) , MT(MOD_LCTL, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LGUI, KC_D) , MT(MOD_LSFT, KC_F) , KC_G   ,     KC_H   , MT(MOD_RSFT, KC_J) , MT(MOD_RGUI, KC_K) , MT(MOD_LALT, KC_L) , MT(MOD_RCTL, KC_SCLN) , KC_QUOT,
      KC_RSFT              , KC_Z               , KC_X               , KC_C               , KC_V               , KC_B   ,     KC_N   , KC_M               , KC_COMM            , KC_DOT             , KC_SLSH               , KC_RSFT,
                                                                       MO(4)              , MO(1)              , KC_SPC ,     KC_ENT , MO(2)              , MO(3)
),

//        ┌──────┬──────┬──────┬──────┬──────┬────┐   ┌───────────────┬─────────┬─────────┬───────────┬─────────┬──────┐
//        │ tab  │  no  │  no  │  no  │  no  │ no │   │ LGUI(LSFT(z)) │ LGUI(v) │ LGUI(c) │  LGUI(x)  │ LGUI(z) │      │
//        ├──────┼──────┼──────┼──────┼──────┼────┤   ├───────────────┼─────────┼─────────┼───────────┼─────────┼──────┤
//        │ esc  │ lctl │ lalt │ lgui │ lsft │ no │   │     left      │  down   │   up    │   rght    │   no    │ caps │
//        ├──────┼──────┼──────┼──────┼──────┼────┤   ├───────────────┼─────────┼─────────┼───────────┼─────────┼──────┤
//        │ lsft │  no  │  no  │  no  │  no  │ no │   │      ins      │  home   │ pAGE_UP │ pAGE_DOWN │   end   │      │
//        └──────┴──────┴──────┼──────┼──────┼────┤   ├───────────────┼─────────┼─────────┼───────────┴─────────┴──────┘
//                             │  no  │      │ no │   │               │   no    │   no    │
//                             └──────┴──────┴────┘   └───────────────┴─────────┴─────────┘
[1] = LAYOUT_split_3x6_3(
      KC_TAB  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     LGUI(LSFT(KC_Z)) , LGUI(KC_V) , LGUI(KC_C) , LGUI(KC_X)   , LGUI(KC_Z) , KC_TRNS,
      KC_ESC  , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , XXXXXXX ,     KC_LEFT          , KC_DOWN    , KC_UP      , KC_RIGHT     , XXXXXXX    , KC_CAPS,
      KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_INS           , KC_HOME    , KC_PAGE_UP , KC_PAGE_DOWN , KC_END     , KC_TRNS,
                                    XXXXXXX , _______ , XXXXXXX ,     KC_TRNS          , XXXXXXX    , XXXXXXX
),

//        ┌──────┬───┬───┬───┬───┬───┐   ┌────┬──────┬──────┬──────┬──────┬──────┐
//        │  `   │ { │ & │ * │ ( │ } │   │ no │  (   │  )   │  -   │  =   │ bspc │
//        ├──────┼───┼───┼───┼───┼───┤   ├────┼──────┼──────┼──────┼──────┼──────┤
//        │  -   │ : │ $ │ % │ ^ │ + │   │ -  │ rsft │ rgui │ ralt │ rctl │  `   │
//        ├──────┼───┼───┼───┼───┼───┤   ├────┼──────┼──────┼──────┼──────┼──────┤
//        │ lsft │ ~ │ ! │ @ │ # │ | │   │ _  │  +   │  {   │  }   │  |   │  ~   │
//        └──────┴───┴───┼───┼───┼───┤   ├────┼──────┼──────┼──────┴──────┴──────┘
//                       │ ( │ ) │ _ │   │ no │      │  no  │
//                       └───┴───┴───┘   └────┴──────┴──────┘
[2] = LAYOUT_split_3x6_3(
      KC_GRAVE , KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,     XXXXXXX , KC_LPRN , KC_RPRN , KC_MINS , KC_EQL  , KC_BSPC,
      KC_MINS  , KC_COLN , KC_DLR  , KC_PERC , KC_CIRC , KC_PLUS ,     KC_MINS , KC_RSFT , KC_RGUI , KC_RALT , KC_RCTL , KC_GRV ,
      KC_LSFT  , KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_PIPE ,     KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                     KC_LPRN , KC_RPRN , KC_UNDS ,     XXXXXXX , _______ , XXXXXXX
),

//        ┌─────────┬─────────┬─────────┬─────────┬────┬─────┐   ┌─────┬──────┬──────┬────┬────┬────┐
//        │ QK_BOOT │   no    │   no    │   no    │ no │ no  │   │ no  │  no  │  no  │ no │ no │ no │
//        ├─────────┼─────────┼─────────┼─────────┼────┼─────┤   ├─────┼──────┼──────┼────┼────┼────┤
//        │ RGB_TOG │ RGB_HUI │ RGB_SAI │ RGB_VAI │ no │ no  │   │ no  │ vold │ volu │ no │ no │ no │
//        ├─────────┼─────────┼─────────┼─────────┼────┼─────┤   ├─────┼──────┼──────┼────┼────┼────┤
//        │ RGB_MOD │ RGB_HUD │ RGB_SAD │ RGB_VAD │ no │ no  │   │ no  │ mute │  no  │ no │ no │ no │
//        └─────────┴─────────┴─────────┼─────────┼────┼─────┤   ├─────┼──────┼──────┼────┴────┴────┘
//                                      │         │ no │     │   │     │  no  │      │
//                                      └─────────┴────┴─────┘   └─────┴──────┴──────┘
[3] = LAYOUT_split_3x6_3(
      QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX           , XXXXXXX         , XXXXXXX , XXXXXXX , XXXXXXX,
      RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , XXXXXXX , XXXXXXX , XXXXXXX,
      RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_AUDIO_MUTE     , XXXXXXX         , XXXXXXX , XXXXXXX , XXXXXXX,
                                    KC_TRNS , XXXXXXX , KC_TRNS ,     KC_TRNS , XXXXXXX           , _______
),

//        ┌─────┬──────┬──────┬──────┬──────┬────┐   ┌───┬───┬───┬───┬───┬──────┐
//        │     │  no  │  no  │  no  │  no  │ no │   │ [ │ 7 │ 8 │ 9 │ ] │ bspc │
//        ├─────┼──────┼──────┼──────┼──────┼────┤   ├───┼───┼───┼───┼───┼──────┤
//        │ esc │ lctl │ lalt │ lgui │ lsft │ no │   │ = │ 4 │ 5 │ 6 │ ; │ ent  │
//        ├─────┼──────┼──────┼──────┼──────┼────┤   ├───┼───┼───┼───┼───┼──────┤
//        │ no  │  no  │  no  │  no  │  no  │ no │   │ ` │ 1 │ 2 │ 3 │ \ │  no  │
//        └─────┴──────┴──────┼──────┼──────┼────┤   ├───┼───┼───┼───┴───┴──────┘
//                            │      │  no  │ no │   │ - │ 0 │ . │
//                            └──────┴──────┴────┘   └───┴───┴───┘
[4] = LAYOUT_split_3x6_3(
      KC_TRNS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_LBRC , KC_7 , KC_8   , KC_9 , KC_RBRC , KC_BSPC,
      KC_ESC  , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , XXXXXXX ,     KC_EQL  , KC_4 , KC_5   , KC_6 , KC_SCLN , KC_ENT ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_GRV  , KC_1 , KC_2   , KC_3 , KC_BSLS , XXXXXXX,
                                    _______ , XXXXXXX , XXXXXXX ,     KC_MINS , KC_0 , KC_DOT
)
};

#ifdef RGBLIGHT_ENABLE
#    include "rgb.c"
#endif

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

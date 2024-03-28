// enum combos {
//   MC_LBRACKET,
//   CD_RBRACKET,
// };
//
// const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};
//
// combo_t key_combos[] = {
//   [MC_LBRACKET] = COMBO(mc_combo, KC_LBRC),
//   [CD_RBRACKET] = COMBO(cd_combo, KC_RBRC),
// };

const uint16_t PROGMEM test_combo1[] = {KC_X, KC_C, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_ESC),
};

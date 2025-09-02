enum combos {
  MC_LBRACKET,
  CD_RBRACKET,
  UI_LPAR,
  IO_RPAR,
};

const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
  [MC_LBRACKET] = COMBO(mc_combo, KC_LBRC),
  [CD_RBRACKET] = COMBO(cd_combo, KC_RBRC),
  [UI_LPAR] = COMBO(ui_combo, KC_LPRN),
  [IO_RPAR] = COMBO(io_combo, KC_RPRN),
};


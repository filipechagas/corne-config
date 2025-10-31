enum combos {
    // Left hand top row
    RE_LPAR,   // LT1 LT2: R+E = (
    EW_LBKT,   // LT2 LT3: E+W = [
    RW_LBRACE, // LT1 LT3: R+W = {

    // Left hand bottom row
    VC_UNDER,       // LB1 LB2: V+C = _
    CX_ARROW_RIGHT, // LB2 LB3: C+X = ->
    VX_PLUS,        // LB1 LB3: V+X = +

    // Right hand top row
    UI_RPAR,   // RT1 RT2: U+I = )
    IO_RBKT,   // RT2 RT3: I+O = ]
    OP_EQUAL,  // RT3 RT4: O+P = =
    UO_RBRACE, // RT1 RT3: U+O = }

    // Right hand bottom row
    M_COMM_PIPE,          // RB1 RB2: M+, = |
    COMM_DOT_ARROW_EQUAL, // RB2 RB3: ,+. = =>
    DOT_SLSH_BSLH,        // RB3 RB4: .+/ = backslash
    M_DOT_MINUS,          // RB1 RB3: M+. = -
};

const uint16_t PROGMEM re_combo[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM ew_combo[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM rw_combo[] = {KC_R, KC_W, COMBO_END};

const uint16_t PROGMEM vc_combo[] = {KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM cx_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM vx_combo[] = {KC_V, KC_X, COMBO_END};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM uo_combo[] = {KC_U, KC_O, COMBO_END};

const uint16_t PROGMEM m_comm_combo[]   = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dot_slsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM m_dot_combo[]    = {KC_M, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    // Left hand top row
    [RE_LPAR]   = COMBO(re_combo, KC_LPRN),
    [EW_LBKT]   = COMBO(ew_combo, KC_LBRC),
    [RW_LBRACE] = COMBO(rw_combo, KC_LCBR),

    // Left hand bottom row
    [VC_UNDER]       = COMBO(vc_combo, KC_UNDS),
    [CX_ARROW_RIGHT] = COMBO(cx_combo, DASH_ARROW),
    [VX_PLUS]        = COMBO(vx_combo, KC_PLUS),

    // Right hand top row
    [UI_RPAR]   = COMBO(ui_combo, KC_RPRN),
    [IO_RBKT]   = COMBO(io_combo, KC_RBRC),
    [OP_EQUAL]  = COMBO(op_combo, KC_EQL),
    [UO_RBRACE] = COMBO(uo_combo, KC_RCBR),

    // Right hand bottom row
    [M_COMM_PIPE]          = COMBO(m_comm_combo, KC_PIPE),
    [COMM_DOT_ARROW_EQUAL] = COMBO(comm_dot_combo, EQUAL_ARROW),
    [DOT_SLSH_BSLH]        = COMBO(dot_slsh_combo, KC_BSLS),
    [M_DOT_MINUS]          = COMBO(m_dot_combo, KC_MINS),
};

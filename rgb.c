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
        case L_SYM:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(175, sat, val);
            break;
        case L_NAV:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(79, sat, val);
            break;
        case L_NUMBER:
            rgblight_mode(LAYER_SWITCHED_MODE);
            rgblight_sethsv(225, sat, val);
            break;
        default: // for any other layers, or the default layer
            rgblight_mode(DEFAULT_MODE);
            rgblight_sethsv(hue, sat, val);
            break;
    }

    return state;
};

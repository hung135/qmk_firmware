#include QMK_KEYBOARD_H
// refer here
// https://beta.docs.qmk.fm/features/feature_macros
enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // This has to be here
    NEXT_WORD,
    BACK_WORD,
    CUT_MAC,
    COPY_MAC,
    PASTE_MAC,
    DELETE_LINE_MAC,
    SELECT_LINE_MAC,
    YANK_LINE

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_60_ansi(
  KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, LT(1, KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT, MO(1), KC_RCTL),

[1] = LAYOUT_60_ansi(
  KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RESET, 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, YANK_LINE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_INC, BL_TOGG, 
  KC_CAPS, SELECT_LINE_MAC, KC_TRNS, DELETE_LINE_MAC, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGUP, KC_PGDN, KC_TRNS, 
  KC_LSFT, KC_Z, CUT_MAC, COPY_MAC, PASTE_MAC, KC_B, NEXT_WORD, BACK_WORD, BACK_WORD, KC_TRNS, KC_TRNS, KC_RSFT, 
  KC_LCTL, KC_TRNS, KC_LGUI, KC_TRNS, KC_RGUI, KC_TRNS, KC_TRNS, KC_RCTL)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NEXT_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LALT));
                // selects all and copies
            }
            break;
        case BACK_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LALT));
            }
            break;
        case CUT_MAC:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("x"));
                // selects all and copies
            }
            break;

        case COPY_MAC:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("c"));
                // selects all and copies
            }
            break;
        case PASTE_MAC:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("v"));
                // selects all and copies
            }
            break;
        case YANK_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a") SS_DOWN(X_LSHIFT) SS_LCTRL("e") SS_UP(X_LSHIFT) SS_LGUI("c") );
                // selects all and copies
            }

            break;
        case SELECT_LINE_MAC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a") SS_DOWN(X_LSHIFT) SS_LCTRL("e") SS_UP(X_LSHIFT));
                // selects all and copies
            }

            break;
        case DELETE_LINE_MAC:  // Line Delete
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a") SS_DOWN(X_LSHIFT) SS_LCTRL("e") SS_UP(X_LSHIFT));
                // SEND_STRING(SS_TAP(X_BSPACE));
                SEND_STRING(SS_LGUI("x"));
            }
            break;
    }
    return true;
};

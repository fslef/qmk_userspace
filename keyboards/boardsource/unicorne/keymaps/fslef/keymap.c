// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_BOOT,
};

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
    _CODE
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define CODE    MO(_CODE)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LALT_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K LALT_T(KC_K)
#define HOME_L RCTL_T(KC_L)
#define HOME_SLN RGUI_T(KC_SCLN)

// Layer Keymaps
// Keycodes list is available at: https://docs.qmk.fm/#/keycodes
// https://www.keyboard-layout-editor.com/#/gists/963e2a6a5ace882b9ed85b874318cb16
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        KC_LCTL, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                   KC_LGUI, RAISE,   KC_SPC,  KC_ENT,  CODE,    LOWER
    ),
    [_RAISE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, KC_VOLU, KC_DEL ,
        XXXXXXX, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, RGB_MOD, TD(TD_BOOT), QK_GESC,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_LOWER] = LAYOUT(
        XXXXXXX, KC_CIRC, KC_7,    KC_8,    KC_9,   KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,   KC_MINS, XXXXXXX, KC_RSFT, KC_LALT, KC_RCTL, KC_RGUI, XXXXXXX,
        XXXXXXX, KC_AMPR, KC_1,    KC_2,    KC_3,   KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   KC_0,    KC_DOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_CODE] = LAYOUT(
        KC_HASH, KC_EXLM, KC_DLR,  KC_UNDS, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F5,   KC_F8,   KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX, KC_RSFT, KC_LALT, KC_RCTL, KC_RGUI, XXXXXXX,
        XXXXXXX, KC_F10,  KC_F11,  KC_F12,  KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

// Tap Dance function for bootloader
void dance_boot_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_FN(dance_boot_finished),
};


/* ────── LED INDEX MAP ── Boardsource Unicorne ────────────────
 * Only switch-backlight LEDs (underglow omitted)
 *
 * ── LEFT HALF ── rows 1-3 (matrix rows 1-3)
 *         C0   C1   C2   C3   C4   C5
 * Row 1 : 25   22   19   16   11    8
 * Row 2 : 26   21   20   15   12    7
 * Row 3 :  –    –    –   14   13    6
 *
 * ── RIGHT HALF ── rows 1-4 (matrix rows 4-7)
 *         C0   C1   C2   C3   C4   C5
 * Row 1 : 51   50   45   44   37   36
 * Row 2 : 52   49   46   43   38   35
 * Row 3 : 53   48   47   42   39   34
 * Row 4 :  –    –    –   41   40   33
 *
 * ─────────────────────────────────────────────────────────────
 * Colors are available here https://docs.qmk.fm/features/rgblight#colors*/


bool rgb_matrix_indicators_user(void) {
    // Apply LED_MATRIX_ALPHAS_MODS by default for all layers
    if (!rgb_matrix_is_enabled()) {
        return false;
    }

    // Check if the LOWER layer is active
    if (IS_LAYER_ON(_LOWER)) {
        // Correct key IDs for KC_0 to KC_9 based on the matrix layout
        rgb_matrix_set_color(14, RGB_GREEN); // KC_0
        rgb_matrix_set_color(20, RGB_GREEN); // KC_1
        rgb_matrix_set_color(15, RGB_GREEN); // KC_2
        rgb_matrix_set_color(12, RGB_GREEN); // KC_3
        rgb_matrix_set_color(19, RGB_GREEN); // KC_4
        rgb_matrix_set_color(16, RGB_GREEN); // KC_5
        rgb_matrix_set_color(11, RGB_GREEN); // KC_6
        rgb_matrix_set_color(10, RGB_GREEN); // KC_7
        rgb_matrix_set_color(17, RGB_GREEN); // KC_8
        rgb_matrix_set_color(18, RGB_GREEN); // KC_9
        rgb_matrix_set_color(40, RGB_GREEN); // CODE
        rgb_matrix_set_color(13, RGB_GREEN); // KC_DOT
    }

    // Check if the RAISE layer is active
    if (IS_LAYER_ON(_RAISE)) {
        // Correct key IDs for KC_MPRV, KC_MPLY, and KC_MNXT based on the matrix layout
        rgb_matrix_set_color(49, RGB_YELLOW); // KC_LEFT
        rgb_matrix_set_color(46, RGB_YELLOW); // KC_DOWN
        rgb_matrix_set_color(43, RGB_YELLOW); // KC_RIGHT
        rgb_matrix_set_color(45, RGB_YELLOW); // KC_UP
        rgb_matrix_set_color(13, RGB_YELLOW); // RAISE
    }

    return false; // Ensure LED_MATRIX_ALPHAS_MODS remains active
}

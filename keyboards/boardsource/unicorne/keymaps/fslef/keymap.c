// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

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
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SLN RCTL_T(KC_SCLN)

enum combos {
  QW_EXCL,
  WE_AT,
  ER_HASH,
  YU_CARET,
  IO_LPAREN,
  OP_RPAREN,
  RT_DOLLAR};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};

combo_t key_combos[] = {
  [QW_EXCL] = COMBO(qw_combo, KC_EXLM),  // q and w = !
  [WE_AT] = COMBO(we_combo, KC_AT),      // w and e = @
  [ER_HASH] = COMBO(er_combo, KC_HASH),  // e and r = #
  [YU_CARET] = COMBO(yu_combo, KC_CIRC), // y and u = ^
  [IO_LPAREN] = COMBO(io_combo, KC_LPRN),// i and o = (
  [OP_RPAREN] = COMBO(op_combo, KC_RPRN), // o and p = )
  [RT_DOLLAR] = COMBO(rt_combo, KC_DLR) // r and t = $
};


// Layer Keymaps
// Keycodes list is available at: https://docs.qmk.fm/#/keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                                   KC_LGUI, RAISE,   KC_SPC,  KC_ENT,  LOWER,   CODE
    ),
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, KC_UP,   KC_DOWN, KC_DEL,
        _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, KC_PPLS, KC_PIPE,
        _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, KC_MINS, _______,
                                   _______, _______, _______, _______, _______, _______
    ),
    [_LOWER] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_EQL,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
                                   _______, _______, _______, _______, _______, KC_MNXT
    ),
    [_CODE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_VOLU, KC_GRV,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAG(KC_M), XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX
    ),
};

/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
  _DVORAK = 0,
  _MODS1,
  _NUMS,
  _MODS2
};

#define MODS MO(_MODS1)
#define NUMS MO(_NUMS)

#undef KC_P1
#undef KC_P2

#define KC_A1 OSM(MOD_LALT)
#define KC_A2 OSM(MOD_RALT)
#define KC_B1 KC_BSPACE
#define KC_B2 KC_BRK
#define KC_C1 OSM(MOD_LCTL)
#define KC_C2 OSM(MOD_RCTL)
#define KC_D1 KC_DEL
#define KC_D2 KC_D1
#define KC_E1 KC_ENTER
#define KC_E2 KC_ESCAPE
#define KC_F1 KC_F
#define KC_F2 KC_F
#define KC_G1 KC_G
#define KC_G2 KC_G
#define KC_H1 KC_LEFT
#define KC_H2 KC_HOME
#define KC_I1 KC_INS
#define KC_I2 KC_I1
#define KC_J1 KC_DOWN
#define KC_J2 KC_PGDN
#define KC_K1 KC_UP
#define KC_K2 KC_PGUP
#define KC_L1 KC_RIGHT
#define KC_L2 KC_END
#define KC_M1 KC_M
#define KC_M2 KC_M
#define KC_N1 KC_N
#define KC_N2 KC_N
#define KC_O1 KC_O
#define KC_O2 KC_O
#define KC_P1 KC_PSCREEN
#define KC_P2 KC_LOCK
#define KC_Q1 KC_Q
#define KC_Q2 KC_Q
#define KC_R1 KC_R
#define KC_R2 KC_SYSREQ
#define KC_S1 OSM(MOD_LSFT)
#define KC_S2 KC_SCROLLLOCK
#define KC_T1 KC_TAB
#define KC_T2 KC_T1
#define KC_U1 KC_CAPS
#define KC_U2 KC_U1
#define KC_V1 KC_V
#define KC_V2 KC_V
#define KC_W1 OSM(MOD_LGUI)
#define KC_W2 OSM(MOD_RGUI)
#define KC_X1 KC_X
#define KC_X2 KC_X
#define KC_Y1 KC_Y
#define KC_Y2 KC_Y
#define KC_Z1 KC_Z
#define KC_Z2 KC_Z
#define KC_QUOT1 KC_QUOT
#define KC_QUOT2 KC_QUOT
#define KC_COMM1 KC_COMM
#define KC_COMM2 KC_COMM
#define KC_DOT1 KC_DOT
#define KC_DOT2 KC_DOT
#define KC_SCLN1 KC_SCLN
#define KC_SCLN2 KC_SCLN



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT_ortho_4x12( \
    XXXXXXX, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    XXXXXXX, \
    XXXXXXX, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    XXXXXXX, \
    XXXXXXX, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, MODS,    XXXXXXX, KC_LSFT, XXXXXXX, KC_SPC,  NUMS,    XXXXXXX, XXXXXXX, XXXXXXX \
),
[_MODS1] = LAYOUT_ortho_4x12( \
    _______, KC_QUOT1, KC_COMM1, KC_DOT1,  KC_P1,    KC_Y1,    KC_F1,    KC_G1,    KC_C1,    KC_R1,    KC_L1,    _______, \
    _______, KC_A1,    KC_O1,    KC_E1,    KC_U1,    KC_I1,    KC_D1,    KC_H1,    KC_T1,    KC_N1,    KC_S1,    _______, \
    _______, KC_SCLN1, KC_Q1,    KC_J1,    KC_K1,    KC_X1,    KC_B1,    KC_M1,    KC_W1,    KC_V1,    KC_Z1,    _______, \
    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  NUMS,     _______,  _______,  _______ \
),
[_MODS2] = LAYOUT_ortho_4x12( \
    _______, KC_QUOT2, KC_COMM2, KC_DOT2,  KC_P2,    KC_Y2,    KC_F2,    KC_G2,    KC_C2,    KC_R2,    KC_L2,    _______, \
    _______, KC_A2,    KC_O2,    KC_E2,    KC_U2,    KC_I2,    KC_D2,    KC_H2,    KC_T2,    KC_N2,    KC_S2,    _______, \
    _______, KC_SCLN2, KC_Q2,    KC_J2,    KC_K2,    KC_X2,    KC_B2,    KC_M2,    KC_W2,    KC_V2,    KC_Z2,    _______, \
    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______ \
),
[_NUMS] = LAYOUT_ortho_4x12( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, _______, KC_GRV,  KC_LBRC, KC_RBRC, KC_F11,  KC_F12,  KC_EQL,  KC_MINS, KC_SLSH, KC_BSLS, _______, \
    _______, _______, _______, MODS,    _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _MODS1, _NUMS, _MODS2);
}


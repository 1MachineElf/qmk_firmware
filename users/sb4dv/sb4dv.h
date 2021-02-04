#pragma once

#include "quantum.h"

/*
// This typically goes into the keymap.c instead.
enum layers {
  _DVORAK = 0,
  _MODS1,
  _NUMS,
  _MODS2
};
*/

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
#define KC_P1 KC_PSCR
#define KC_P2 KC_LOCK
#define KC_Q1 KC_Q
#define KC_Q2 KC_Q
#define KC_R1 KC_R
#define KC_R2 KC_SYSREQ
#define KC_S1 OSM(MOD_LSFT)
#define KC_S2 KC_SCROLLLOCK
#define KC_T1 KC_TAB
#define KC_T2 KC_T1
#define KC_U1 KC_U
#define KC_U2 KC_CAPS
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


// Layer 0 (Dvorak), Left Side Inner Keys
#define __DVORAK_INNER_LEFT_R2__ KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y
#define __DVORAK_INNER_LEFT_R3__ KC_A,    KC_O,    KC_E,    KC_U,    KC_I
#define __DVORAK_INNER_LEFT_R4__ KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X

// Layer 0 (Dvorak), Right Side Inner Keys
#define __DVORAK_INNER_RIGHT_R2__ KC_F,    KC_G,    KC_C,    KC_R,    KC_L 
#define __DVORAK_INNER_RIGHT_R3__ KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define __DVORAK_INNER_RIGHT_R4__ KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

// Layer 1 (Mods1), Left Side Inner Keys
#define __MODS1_INNER_LEFT_R2__ KC_QUOT1, KC_COMM1, KC_DOT1,  KC_P1,    KC_Y1
#define __MODS1_INNER_LEFT_R3__ KC_A1,    KC_O1,    KC_E1,    KC_U1,    KC_I1
#define __MODS1_INNER_LEFT_R4__ KC_SCLN1, KC_Q1,    KC_J1,    KC_K1,    KC_X1

// Layer 1 (Mods1), Right Side Inner Keys
#define __MODS1_INNER_RIGHT_R2__ KC_F1,    KC_G1,    KC_C1,    KC_R1,    KC_L1 
#define __MODS1_INNER_RIGHT_R3__ KC_D1,    KC_H1,    KC_T1,    KC_N1,    KC_S1
#define __MODS1_INNER_RIGHT_R4__ KC_B1,    KC_M1,    KC_W1,    KC_V1,    KC_Z1

// Layer 2 (Mods2), Left Side Inner Keys
#define __MODS2_INNER_LEFT_R2__ KC_QUOT2, KC_COMM2, KC_DOT2,  KC_P2,    KC_Y2
#define __MODS2_INNER_LEFT_R3__ KC_A2,    KC_O2,    KC_E2,    KC_U2,    KC_I2
#define __MODS2_INNER_LEFT_R4__ KC_SCLN2, KC_Q2,    KC_J2,    KC_K2,    KC_X2

// Layer 2 (Mods2), Right Side Inner Keys
#define __MODS2_INNER_RIGHT_R2__ KC_F2,    KC_G2,    KC_C2,    KC_R2,    KC_L2 
#define __MODS2_INNER_RIGHT_R3__ KC_D2,    KC_H2,    KC_T2,    KC_N2,    KC_S2
#define __MODS2_INNER_RIGHT_R4__ KC_B2,    KC_M2,    KC_W2,    KC_V2,    KC_Z2

// Layer 3 (Nums), Left Side Inner Keys
#define __NUMS_INNER_LEFT_R2__ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __NUMS_INNER_LEFT_R3__ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __NUMS_INNER_LEFT_R4__ _______, KC_GRV,  KC_LBRC, KC_RBRC, KC_F11

// Layer 3 (Nums), Right Side Inner Keys
#define __NUMS_INNER_RIGHT_R2__ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define __NUMS_INNER_RIGHT_R3__ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __NUMS_INNER_RIGHT_R4__ KC_F12,  KC_EQL,  KC_MINS, KC_SLSH, KC_BSLS

// Layer 3 (WASD), Left Side Inner Keys
#define __WASD_INNER_LEFT_R2__ KC_NO,    KC_UP,   KC_NO,   KC_NO,   KC_NO
#define __WASD_INNER_LEFT_R3__ KC_LEFT,  KC_DOWN, KC_RIGHT,KC_NO,   KC_NO
#define __WASD_INNER_LEFT_R4__ KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO

// Layer 4 (WASD), Right Side Inner Keys
#define __WASD_INNER_RIGHT_R2__ KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO   
#define __WASD_INNER_RIGHT_R3__ KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT
#define __WASD_INNER_RIGHT_R4__ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   

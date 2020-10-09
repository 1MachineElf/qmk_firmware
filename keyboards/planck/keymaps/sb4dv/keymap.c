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

#include "sb4dv.h"


// Use an expanded macro with VA_ARGS to ensure that the common
// rows get expanded out before getting passed to the LAYOUT
// macro.

#define LAYOUT_wrapper(...) LAYOUT_planck_2x2u(__VA_ARGS__)

// Planck Light

#define LAYOUT_planck_1x2uC( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34,    k35,   k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b }, \
    { k30, k31, k32, k33, k34, k35, k35, k37, k38, k39, k3a, k3b } \
}

#define LAYOUT_ortho_4x12( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b } \
}

// Planck Rev6

#define LAYOUT_planck_1x2uC( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34,    k36,   k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04, k05   }, \
    { k10, k11, k12, k13, k14, k15   }, \
    { k20, k21, k22, k23, k24, k25   }, \
    { k30, k31, k32, k39, k3a, k3b   }, \
    { k06, k07, k08, k09, k0a, k0b   }, \
    { k16, k17, k18, k19, k1a, k1b   }, \
    { k26, k27, k28, k29, k2a, k2b   }, \
    { k36, k37, k38, k33, k34, KC_NO } \
}

#define LAYOUT_planck_1x2uR( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35,   k37,    k38, k39, k3a, k3b \
) \
{ \
    { k00,   k01, k02, k03, k04, k05 }, \
    { k10,   k11, k12, k13, k14, k15 }, \
    { k20,   k21, k22, k23, k24, k25 }, \
    { k30,   k31, k32, k39, k3a, k3b }, \
    { k06,   k07, k08, k09, k0a, k0b }, \
    { k16,   k17, k18, k19, k1a, k1b }, \
    { k26,   k27, k28, k29, k2a, k2b }, \
    { KC_NO, k37, k38, k33, k34, k35 } \
}

#define LAYOUT_planck_1x2uL( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33,   k35,    k36, k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04,   k05 }, \
    { k10, k11, k12, k13, k14,   k15 }, \
    { k20, k21, k22, k23, k24,   k25 }, \
    { k30, k31, k32, k39, k3a,   k3b }, \
    { k06, k07, k08, k09, k0a,   k0b }, \
    { k16, k17, k18, k19, k1a,   k1b }, \
    { k26, k27, k28, k29, k2a,   k2b }, \
    { k36, k37, k38, k33, KC_NO, k35 } \
}

#define LAYOUT_planck_2x2u( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33,   k35,      k37,    k38, k39, k3a, k3b \
) \
{ \
    { k00,   k01, k02, k03, k04,   k05 }, \
    { k10,   k11, k12, k13, k14,   k15 }, \
    { k20,   k21, k22, k23, k24,   k25 }, \
    { k30,   k31, k32, k39, k3a,   k3b }, \
    { k06,   k07, k08, k09, k0a,   k0b }, \
    { k16,   k17, k18, k19, k1a,   k1b }, \
    { k26,   k27, k28, k29, k2a,   k2b }, \
    { KC_NO, k37, k38, k33, KC_NO, k35 } \
}

#define LAYOUT_ortho_4x12( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, k11, k12, k13, k14, k15 }, \
    { k20, k21, k22, k23, k24, k25 }, \
    { k30, k31, k32, k39, k3a, k3b }, \
    { k06, k07, k08, k09, k0a, k0b }, \
    { k16, k17, k18, k19, k1a, k1b }, \
    { k26, k27, k28, k29, k2a, k2b }, \
    { k36, k37, k38, k33, k34, k35 } \
}

// The ortho_4x12 layout from drashna

#define LAYOUT_ortho_4x12_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_4x12_wrapper( \
    KC_ESC,  K01,    K02,     K03,      K04,     K05,     K06,     K07,     K08,     K09,     K0A,     KC_DEL, \
    LALT_T(KC_TAB), K11, K12, K13,      K14,     K15,     K16,     K17,     K18,     K19,     K1A, RALT_T(KC_QUOT), \
    KC_MLSF, CTL_T(K21), K22, K23,      K24,     K25,     K26,     K27,     K28,     K29, RCTL_T(K2A), KC_ENT,  \
    BACKLIT, OS_LCTL, OS_LALT, OS_LGUI, PLNK_1,  PLNK_2,  PLNK_3,  PLNK_4,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  )
#define LAYOUT_ortho_4x12_base_wrapper(...)       LAYOUT_ortho_4x12_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12_base_wrapper(
    

extern keymap_config_t keymap_config;

enum layers {
  _DVORAK = 0,
  _MODS1,
  _NUMS,
  _MODS2,
  _WASD
};

#define TEHS MT(MOD_RSFT, KC_ENT)

#define TEHW LT(_WASD, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT_wrapper( \
    KC_TAB,              __DVORAK_INNER_LEFT_R2__,             __DVORAK_INNER_RIGHT_R2__,             KC_BSPC, \
    TEHW,                __DVORAK_INNER_LEFT_R3__,             __DVORAK_INNER_RIGHT_R3__,             KC_ENT,  \
    KC_LSFT,             __DVORAK_INNER_LEFT_R4__,             __DVORAK_INNER_RIGHT_R4__,             TEHS   , \
    KC_LCTL, KC_LGUI, KC_LALT, MODS,             KC_LSFT,         KC_SPC,  NUMS,    KC_RALT, KC_RGUI, KC_RCTL  \
),
[_MODS1] = LAYOUT_wrapper( \
    _______,             __MODS1_INNER_LEFT_R2__,              __MODS1_INNER_RIGHT_R2__,              _______, \
    _______,             __MODS1_INNER_LEFT_R3__,              __MODS1_INNER_RIGHT_R3__,              _______, \
    _______,             __MODS1_INNER_LEFT_R4__,              __MODS1_INNER_RIGHT_R4__,              _______, \
    _______, _______, _______, _______,          _______,         _______, NUMS,    _______, _______, _______  \
),
[_MODS2] = LAYOUT_wrapper( \
    _______,             __MODS2_INNER_LEFT_R2__,              __MODS2_INNER_RIGHT_R2__,              _______, \
    _______,             __MODS2_INNER_LEFT_R3__,              __MODS2_INNER_RIGHT_R3__,              _______, \
    _______,             __MODS2_INNER_LEFT_R4__,              __MODS2_INNER_RIGHT_R4__,              _______, \
    _______, _______, _______, _______,          _______,         _______, _______, _______, _______, _______  \
),
[_NUMS] = LAYOUT_wrapper( \
    _______,             __NUMS_INNER_LEFT_R2__,               __NUMS_INNER_RIGHT_R2__,               _______, \
    _______,             __NUMS_INNER_LEFT_R3__,               __NUMS_INNER_RIGHT_R3__,               _______, \
    _______,             __NUMS_INNER_LEFT_R4__,               __NUMS_INNER_RIGHT_R4__,               _______, \
    _______, _______, _______, MODS,             _______,         _______, _______, _______, _______, _______  \
),
[_WASD] = LAYOUT_wrapper( \
    _______,             __WASD_INNER_LEFT_R2__,               __WASD_INNER_RIGHT_R2__,               _______, \
    _______,             __WASD_INNER_LEFT_R3__,               __WASD_INNER_RIGHT_R3__,               _______, \
    _______,             __WASD_INNER_LEFT_R4__,               __WASD_INNER_RIGHT_R4__,               _______, \
    _______, _______, _______, _______,          _______,         _______, _______, _______, _______, _______  \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _MODS1, _NUMS, _MODS2);
}


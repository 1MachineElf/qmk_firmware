/* Copyright 2021
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

#include "sb4dv.h"

// Use an expanded macro with VA_ARGS to ensure that the common
// rows get expanded out before getting passed to the LAYOUT
// macro.

extern keymap_config_t keymap_config;

// Based on the ortho_4x12 layout from drashna

// Use an expanded macro with VA_ARGS to ensure that the common
// rows get expanded out before getting passed to the LAYOUT
// macro.

#define LAYOUT_ortho_4x12_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_planck_grid( \
    KC_ESC,  K01,     K02,     K03,     K04,      K05,      K06,      K07,     K08,     K09,     K0A,     KC_BSPC, \
    TEHW,    K11,     K12,     K13,     K14,      K15,      K16,      K17,     K18,     K19,     K1A,     TEHM, \
    KC_LSFT, K21,     K22,     K23,     K24,      K25,      K26,      K27,     K28,     K29,     K2A,     TEHS,  \
    KC_LCTL, KC_LGUI, KC_LALT, MODS,    _______,  KC_SPC,   _______,  KC_LSFT, NUMS,    KC_RALT, KC_RGUI, KC_RCTL  \
  )
#define LAYOUT_ortho_4x12_base_wrapper(...)       LAYOUT_ortho_4x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT_ortho_4x12_base_wrapper( \
                 __DVORAK_INNER_LEFT_R2__,             __DVORAK_INNER_RIGHT_R2__,             \
                 __DVORAK_INNER_LEFT_R3__,             __DVORAK_INNER_RIGHT_R3__,             \
                 __DVORAK_INNER_LEFT_R4__,             __DVORAK_INNER_RIGHT_R4__              \
),
[_MODS1] = LAYOUT_ortho_4x12_base_wrapper( \
                 __MODS1_INNER_LEFT_R2__,              __MODS1_INNER_RIGHT_R2__,              \
                 __MODS1_INNER_LEFT_R3__,              __MODS1_INNER_RIGHT_R3__,              \
                 __MODS1_INNER_LEFT_R4__,              __MODS1_INNER_RIGHT_R4__               \
),
[_MODS2] = LAYOUT_ortho_4x12_base_wrapper( \
                 __MODS2_INNER_LEFT_R2__,              __MODS2_INNER_RIGHT_R2__,              \
                 __MODS2_INNER_LEFT_R3__,              __MODS2_INNER_RIGHT_R3__,              \
                 __MODS2_INNER_LEFT_R4__,              __MODS2_INNER_RIGHT_R4__               \
),
[_NUMS] = LAYOUT_ortho_4x12_base_wrapper( \
                 __NUMS_INNER_LEFT_R2__,               __NUMS_INNER_RIGHT_R2__,               \
                 __NUMS_INNER_LEFT_R3__,               __NUMS_INNER_RIGHT_R3__,               \
                 __NUMS_INNER_LEFT_R4__,               __NUMS_INNER_RIGHT_R4__                \
),
[_WASD] = LAYOUT_ortho_4x12_base_wrapper( \
                 __WASD_INNER_LEFT_R2__,               __WASD_INNER_RIGHT_R2__,               \
                 __WASD_INNER_LEFT_R3__,               __WASD_INNER_RIGHT_R3__,               \
                 __WASD_INNER_LEFT_R4__,               __WASD_INNER_RIGHT_R4__                \
)
};


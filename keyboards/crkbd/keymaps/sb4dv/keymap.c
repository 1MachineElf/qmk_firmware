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

#define LAYOUT_split_3x6_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_split_3x6_3( \
    KC_TAB,  K01,    K02,     K03,     K04,     K05,                      K06,     K07,     K08,     K09,     K0A,     KC_BSPC, \
    TEHW,    K11,    K12,     K13,     K14,     K15,                      K16,     K17,     K18,     K19,     K1A,     TEHM,    \
    KC_LSFT, K21,    K22,     K23,     K24,     K25,                      K26,     K27,     K28,     K29,     K2A,     TEHS,    \
                                       MODS, KC_SPC,  KC_BTN1, KC_BTN2,  KC_LSFT, NUMS                                          \
  )
#define LAYOUT_split_3x6_base_wrapper(...)       LAYOUT_split_3x6_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT_split_3x6_base_wrapper( \
                 __DVORAK_INNER_LEFT_R2__,             __DVORAK_INNER_RIGHT_R2__,             \
                 __DVORAK_INNER_LEFT_R3__,             __DVORAK_INNER_RIGHT_R3__,             \
                 __DVORAK_INNER_LEFT_R4__,             __DVORAK_INNER_RIGHT_R4__              \
),
[_MODS1] = LAYOUT_split_3x6_base_wrapper( \
                 __MODS1_INNER_LEFT_R2__,              __MODS1_INNER_RIGHT_R2__,              \
                 __MODS1_INNER_LEFT_R3__,              __MODS1_INNER_RIGHT_R3__,              \
                 __MODS1_INNER_LEFT_R4__,              __MODS1_INNER_RIGHT_R4__               \
),
[_MODS2] = LAYOUT_split_3x6_base_wrapper( \
                 __MODS2_INNER_LEFT_R2__,              __MODS2_INNER_RIGHT_R2__,              \
                 __MODS2_INNER_LEFT_R3__,              __MODS2_INNER_RIGHT_R3__,              \
                 __MODS2_INNER_LEFT_R4__,              __MODS2_INNER_RIGHT_R4__               \
),
[_NUMS] = LAYOUT_split_3x6_base_wrapper( \
                 __NUMS_INNER_LEFT_R2__,               __NUMS_INNER_RIGHT_R2__,               \
                 __NUMS_INNER_LEFT_R3__,               __NUMS_INNER_RIGHT_R3__,               \
                 __NUMS_INNER_LEFT_R4__,               __NUMS_INNER_RIGHT_R4__                \
),
[_WASD] = LAYOUT_split_3x6_base_wrapper( \
                 __WASD_INNER_LEFT_R2__,               __WASD_INNER_RIGHT_R2__,               \
                 __WASD_INNER_LEFT_R3__,               __WASD_INNER_RIGHT_R3__,               \
                 __WASD_INNER_LEFT_R4__,               __WASD_INNER_RIGHT_R4__                \
)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE

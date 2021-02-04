#include "sb4dv.h"

#include QMK_KEYBOARD_H

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _MODS1, _NUMS, _MODS2);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_QUOT && record->event.pressed) {
        bool rc = true;
        uint8_t mods = 0;
        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
            unregister_mods(mods);
            rc = false;
        }
        if ((mods = get_oneshot_locked_mods())) {
            clear_oneshot_locked_mods();
            unregister_mods(mods);
            rc = false;
        }
        if (is_oneshot_layer_active()) {
            layer_clear();
            rc = false;
        }
        return rc;
    }
    return true;
}

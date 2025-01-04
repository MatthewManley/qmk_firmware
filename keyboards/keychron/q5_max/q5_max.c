/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software : you can redistribute it and /or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see < http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "keychron_task.h"
#ifdef ENCODER_ENABLE
    #include "keychron_common.h"
#endif


// #ifdef DIP_SWITCH_ENABLE
// bool dip_switch_update_kb(uint8_t index, bool active) {
//     if (index == 0) {
//         default_layer_set(1UL << (active ? 2 : 0));
//     }
//     dip_switch_update_user(index, active);

//     return true;
// }
// #endif

void keyboard_post_init_kb(void) {

#ifdef ENCODER_ENABLE
    encoder_cb_init();
#endif

    keyboard_post_init_user();
}

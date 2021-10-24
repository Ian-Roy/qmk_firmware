/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
 * 
 * 
 * qmk compile -kb moonlander -km mine
 * ./wally
 */



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    DPAD, // navigational layer 
    SCRL,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// Tap Dance declarations
enum {
    TD_C_X,
    TD_1_F1,
    TD_2_F2 ,
    TD_3_F3 ,
    TD_4_F4,
    TD_5_F5 ,
    TD_6_F6 ,
    TD_7_F7  ,
    TD_8_F8 ,
    TD_9_F9 ,
    TD_0_F10 ,
    TD_EQ_F11 ,
    TD_PIPE_F12 ,
    };

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_C_X] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C),LCTL(KC_X)),
    [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1 ,KC_F1),
    [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2 ,KC_F2),
    [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3 ,KC_F3),
    [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4 ,KC_F4),
    [TD_5_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5 ,KC_F5),
    [TD_6_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6 ,KC_F6),
    [TD_7_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7 ,KC_F7),
    [TD_8_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8 ,KC_F8),
    [TD_9_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9 ,KC_F9),
    [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0 ,KC_F10),
    [TD_EQ_F11] = ACTION_TAP_DANCE_DOUBLE(KC_EQL ,KC_F11),
    [TD_PIPE_F12] = ACTION_TAP_DANCE_DOUBLE(KC_PIPE ,KC_F12)


};

// Add tap dance item to your keymap in place of a keycode

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
          KC_ESC,TD(TD_1_F1),TD(TD_2_F2),TD(TD_3_F3),TD(TD_4_F4), TD(TD_5_F5),    TD(TD_EQ_F11),           TD(TD_PIPE_F12), TD(TD_6_F6),TD(TD_7_F7),TD(TD_8_F8),TD(TD_9_F9),TD(TD_0_F10),   KC_MINS,
          KC_DEL, KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,           KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
LT(DPAD,KC_BSPC), KC_A,  KC_S,    KC_D,    KC_F,    KC_G,  KC_LPRN,           KC_RPRN,  KC_H,    KC_J,    KC_K,    KC_L,    LT(SCRL, KC_SCLN), LT(DPAD, KC_QUOT),
  LCTL(KC_Y), LCTL_T(KC_Z),KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), LT(SYMB,KC_TILDE),
 LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),RGB_M_K, TG(DPAD),  LCTL(KC_Z),    TD(TD_C_X),          RGB_TOG,   RGB_TOG, DM_REC2, DM_REC1, DM_RSTP,
                                    LSFT_T(KC_SPC),  KC_BSPC, KC_DEL,           LCTL(KC_V),     KC_ENT,      RSFT_T(KC_TAB)

    ),
    // [ORIG] = LAYOUT_moonlander(
    //     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //     KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
    //     KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    // LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
    //                                         KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    // ),
    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        DM_PLY1, KC_EXLM, KC_AT,   KC_HASH, KC_DLR , KC_PERC, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_CIRC, KC_AMPR,  KC_ASTR, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_LT, KC_GT, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [SCRL] = LAYOUT_moonlander(
        _______,_______,_______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_PGUP, KC_MS_WH_UP, KC_PGDOWN, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MS_BTN4, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_MS_BTN5,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,                   _______, _______, _______,
    ),
    [DPAD] = LAYOUT_moonlander(
        _______,_______,_______, _______, _______, _______, _______,           KC_PIPE, _______, _______, _______, _______, _______, RESET,
        DM_PLY2, _______, KC_PGUP, KC_UP, KC_PGDOWN, _______, _______,           KC_EQL ,KC_7,    KC_8,    KC_9,KC_ASTR, _______, _______,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, _______,           KC_DEL ,KC_4,    KC_5,    KC_6,KC_PLUS, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                            KC_1,    KC_2,    KC_3, KC_MINS, _______, _______,
        _______, _______, _______, _______, _______,         _______,            KC_BSPC,         KC_DOT, KC_0, KC_MUTE, _______, TG(BASE),
                                            _______, _______, _______,           KC_COMM, KC_ENT , KC_TAB
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

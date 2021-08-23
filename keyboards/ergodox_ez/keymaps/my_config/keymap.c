#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // dpad
#define NPAD 2 // media keys
#define RHAND 3 // right hand only mode
#define MACL 4 // macro layer
enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,
  IPDB,
  ATTPA,
  DCQ,
  WLEN
};

enum unicode_names {
    BANG,
    IRONY,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  Keymap 0: Basic layer

[BASE] = LAYOUT_ergodox(
  // left hand
  GRAVE_ESC,       KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_EQL,
  KC_TAB , KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_LPRN,
  KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  LALT(KC_TAB),         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    KC_LBRACKET,
  LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), TG(NPAD), TG(RHAND),
                                                           ALT_T(KC_APP), KC_LGUI,
                                                                          KC_DEL,
                                                         LSFT_T(KC_SPC), KC_TAB, KC_BSPC,
  // right hand
  KC_PIPE,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_RPRN,      KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
                KC_H,    KC_J,    KC_K,    KC_L,    LT(NPAD, KC_SCLN), LT(SYMB,KC_QUOT),
  KC_RBRACKET , KC_N,    KC_M,    KC_COMM, KC_DOT,            CTL_T(KC_SLSH), LT(MACL,KC_TILDE),
  KC_UP,        KC_DOWN, KC_LBRC, DYN_REC_START1, DYN_REC_STOP,
  LCTL(KC_C), LCTL(KC_V),
  LCTL(KC_X),
  LCTL(KC_F), KC_ENT, RSFT_T(KC_SPC)
),
//  Keymap 1: Symbol Layer

[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F2,   KC_F4,   KC_F6,   KC_F8,   KC_F10,   KC_F12,
  KC_TRNS, KC_EXLM, KC_PGUP,   KC_UP, KC_PGDOWN, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HOME, KC_LEFT,  KC_DOWN, KC_RGHT, KC_END,
  KC_TRNS, LCTL(KC_Z), LCTL(KC_1), LCTL(KC_GRAVE), LCTL(KC_2), KC_TILD, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_LSFT, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_EQL,  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
//  Keymap 2: Number Pad

[NPAD] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, X(SNEK), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_PEQL, KC_PAST, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_PPLS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_PMNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_DOT, KC_0, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TAB
),


//  Keymap 3: right hand only mode

[RHAND] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  LCTL(KC_C), KC_PAST, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TAB, LCTL(LSFT(KC_F10)), KC_UP, KC_9, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
  LSFT( KC_TAB), KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_DOT, KC_0, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TAB
),

// macro layer
[MACL] = LAYOUT_ergodox(
  // left hand
 // left hand
  KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  DYN_MACRO_PLAY1, IPDB, ATTPA, WLEN, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         LALT(LSFT(KC_D)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TAB
)

};


// LEADER_EXTERNS();

// void matrix_scan_user(void) {
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();

//     SEQ_ONE_KEY(KC_F) {
//       // Anything you can do in a macro.
//       SEND_STRING("QMK is awesome.");
//     }
//   }
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        break;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        break;
      case IPDB:
        SEND_STRING("import ipdb; ipdb.set_trace()");
        break;
      case ATTPA:
        SEND_STRING("@tpastream.com");
        break;
      // case DCQ:// crawl safe quit command 
      //   SEND_STRING(SS_LCTL("d") SS_DELAY(2000) "c" SS_TAP(X_ENT) SS_DELAY(2000) "q" SS_TAP(X_ENT));
      //   return false;
      case WLEN:
        SEND_STRING(SS_TAP(X_HOME)"len("SS_TAP(X_END)")");
        break;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

//  Triggered when you start recording a macro
void dynamic_macro_record_start_user(void) {
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    // ergodox_right_led_1_off();
    // ergodox_right_led_2_off();
    // ergodox_right_led_3_off();

}

void dynamic_macro_record_end_user(int8_t direction){
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();

}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

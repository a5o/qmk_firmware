/* Copyright 2020 umbynos
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
		_FN,
		_FN2,
		_ADJUST
};

enum custom_keycodes {
  EGRAVE=SAFE_RANGE,
  EACU,
  AGRAVE,
  UGRAVE,
  IGRAVE,
  OGRAVE,
};


enum combo_events {
	JK_ESC
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[JK_ESC] = COMBO(jk_combo, KC_ESC)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BASE: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
     * |----------------------------------------------------------------|
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _FL: Function Layer
     * ,----------------------------------------------------------------.
     * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
     * |----------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |Hme |
     * |----------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |End |
     * |----------------------------------------------------------------|
     * |        |   |   |  |   |   |   |   |   |   |   |       |   |    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |   |   |    |   |   |    |
     * `----------------------------------------------------------------'
     */
    [_FN] = LAYOUT_65_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
        _______, _______, _______, EGRAVE, _______, _______, _______, UGRAVE, IGRAVE, OGRAVE, _______, _______, _______, _______, KC_HOME,
        _______, AGRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_END,
        MO(_FN2),          KC_BRID, KC_BRIU, _______, _______, _______,  _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______, _______, _______,                            MO(_ADJUST),                   _______, _______, _______, KC_MUTE, KC_VOLD, KC_MNXT
    ),

    [_FN2] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, EACU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,  _______,  AG_SWAP, AG_NORM, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
};


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EGRAVE:
      if (record->event.pressed) {
      SEND_STRING("`e");
      }
      break;
    case EACU:
      if (record->event.pressed) {
      SEND_STRING("'e");
      }
      break;
    case AGRAVE:
      if (record->event.pressed) {
      SEND_STRING("`a");
      }
      break;
    case UGRAVE:
      if (record->event.pressed) {
      SEND_STRING("`u");
      }
      break;
    case IGRAVE:
      if (record->event.pressed) {
      SEND_STRING("`i");
      }
      break;
    case OGRAVE:
      if (record->event.pressed) {
      SEND_STRING("`o");
      }
      break;
  }
  return true;
}


/* Copyright 2020 Titoepfx <titoepfx@gmail.com>
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0   |  | \  |
 * |---------+------+------+------+------+-----|                              |------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T   |                              |   Y  |   U  |   I  |   O  |   P  |   +=   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | SHIFT  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  : ; |  '"    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CTRL   |   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  |  , < |  . > |  /?  |  sq    |
 * |--------+------+------+------+------+------+------+------\  /-------------|------+------+------+------+------+--------|
 *                        |Volume| NO  | Alt  | Space| Lower |  | Raise |Enter| BKSP |  NO  |LED/Layer |
 *                        '----------------------------------'  `--------------------------------------'
 *
 *
 *
 */
    [_QWERTY] = LAYOUT( 
      KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                                 KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSLS,
      KC_TAB ,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                 KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_EQL,
      KC_LSFT,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                 KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_MINS,
      KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                                 KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_GRAVE,
                 KC_MUTE,KC_NO , KC_LGUI, KC_LALT, LT(_LOWER, KC_SPC),                           LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL,  KC_NO, BL_TOGG
    ),
 /*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0   |  | \  |
 * |---------+------+------+------+------+-----|                              |------+------+------+------+------+--------|
 * | TAB   |   Q  |   W  |   E  |   R  |   T   |                              |   Y  |   U  |   I  |   O  |   P  |   +=   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  : ; |  '"    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | SHIFT  |   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  |  , < |  . > |  /?  |  '"    |
 * |--------+------+------+------+------+------+------+------\  /-------------|------+------+------+------+------+--------|
 *                        |Volume| NO  | Alt  | Space| Lower |  | Raise |Enter| BKSP |  NO  |LED/Layer |
 *                        '----------------------------------'  `--------------------------------------'
 */
    [_LOWER] = LAYOUT(
      KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                                 KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSLS,
      KC_TAB ,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                 KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_EQL,
      KC_LSFT,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                 KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_MINS,
      KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                                 KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_GRAVE,
                 KC_MUTE,KC_NO , KC_LGUI, KC_LALT, LT(_LOWER, KC_SPC),                           LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL,  KC_NO, BL_TOGG
    ),
/*
 *
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                                 KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSLS,
      KC_TAB ,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                 KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_EQL,
      KC_LSFT,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                 KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_MINS,
      KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                                 KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_GRAVE,
                 KC_MUTE,KC_NO , KC_LGUI, KC_LALT, LT(_LOWER, KC_SPC),                           LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL,  KC_NO, BL_TOGG
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
 //   [_ADJUST] = LAYOUT(
//      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
//      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
//      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}
#endif
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { /* Second encoder */  
    if (clockwise) {
      tap_code16(BL_INC);
    } else {
      tap_code16(BL_DEC);
    }
  }
}
#endif

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
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0   |  | \  |
 * |---------+------+------+------+------+-----|                              |------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   +=   |
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
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                 KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_MINS,
      KC_LALT,   KC_Z,   KC_X,   KC_C,   KC_V	,  KC_B,                                                 KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_GRAVE,
                 KC_MUTE,KC_MUTE , KC_LGUI, KC_LSFT, LT(_LOWER, KC_SPC),                           LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL,  BL_TOGG, BL_TOGG
    ),
 /*
 * Lower Layer: Symbols
 *
 * ,----------------------------------------Z---.                              ,-------------------------------------------.
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
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                 KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_MINS,
      KC_LALT,   KC_Z,   KC_X,   KC_C,   KC_V	,  KC_B,                                                 KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_GRAVE,
                 KC_MUTE,KC_MUTE , KC_LGUI, KC_LSFT, LT(_LOWER, KC_SPC),                           LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL,  BL_TOGG, BL_TOGG
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
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                 KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_MINS,
      KC_LALT,   KC_Z,   KC_X,   KC_C,   KC_V	,  KC_B,                                                 KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_GRAVE,
                 KC_MUTE,KC_MUTE , KC_LGUI, KC_LSFT, LT(_LOWER, KC_SPC),                           LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL,  BL_TOGG, BL_TOGG
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
   [_ADJUST] = LAYOUT(
      KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                                 KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSLS,
      KC_TAB ,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                 KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_EQL,
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                 KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_MINS,
      KC_LALT,   KC_Z,   KC_X,   KC_C,   KC_V	,  KC_B,                                                 KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_GRAVE,
                 KC_MUTE,KC_MUTE , KC_LGUI, KC_LSFT, LT(_LOWER, KC_SPC),                           LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL,  BL_TOGG, BL_TOGG
    ),
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
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }	

void oled_task_user(void) {
    static const char PROGMEM font_logo[] = {
// 'grid', 32x128px
0x10, 0x92, 0xd2, 0x7f, 0x11, 0x11, 0x00, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x00, 0x86, 0x88, 0x83, 
0x44, 0x30, 0x0f, 0x00, 0x84, 0xc4, 0x7f, 0x84, 0x84, 0x7c, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 
0x00, 0x00, 0x40, 0x38, 0x10, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 
0x00, 0x10, 0x10, 0x10, 0x10, 0x90, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0x84, 0xc4, 0x23, 0x20, 0xc0, 0x00, 0x00, 0x04, 0x04, 0x04, 0x02, 0x01, 
0x80, 0x04, 0x04, 0x04, 0x02, 0x01, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x83, 0xc4, 0x44, 0x44, 0x64, 0x24, 0x33, 0x18, 0x08, 0x0e, 0x1e, 0x1f, 0x1f, 0x1f, 
0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x1c, 0x0c, 0x18, 0x30, 0x20, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 
0x1e, 0x3f, 0x61, 0x61, 0xe0, 0x60, 0x3c, 0x06, 0x80, 0x80, 0xe0, 0x11, 0x09, 0x08, 0x08, 0x0a, 
0x0e, 0x0a, 0x08, 0x89, 0x93, 0xe2, 0x80, 0x00, 0x1e, 0x30, 0x60, 0xc0, 0x61, 0x73, 0x3e, 0x00, 
0x00, 0x00, 0xf0, 0x08, 0x0b, 0x0c, 0x38, 0x08, 0x08, 0x08, 0x0c, 0x13, 0x20, 0x20, 0x20, 0xc0, 
0x40, 0x20, 0x27, 0x28, 0x58, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x03, 0xbc, 0x08, 0xf8, 0x00, 
0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x06, 0x04, 0x04, 0x04, 0x04, 0x07, 
0x04, 0x08, 0x08, 0x08, 0x08, 0x06, 0x04, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xff, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x70, 0x50, 0x50, 0x50, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x75, 0x25, 0x27, 0x25, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xfe, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x58, 0x54, 0x54, 0xd4, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0xe0, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xba, 0x2b, 0x3b, 0x2a, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xe0, 0xe0, 0xe0, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x3b, 0x21, 0x39, 0x09, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x40, 0xff, 0xff, 0xff, 0x18, 0xff, 0xff, 0xff, 0xfe, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0xae, 0xa8, 0xee, 0xa8, 0xae, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0x03, 0x1f, 0xff, 0xff, 0xe3, 0x6f, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 
0x88, 0x88, 0x88, 0xa8, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfd, 0xf8, 0xf8, 0x3f, 0x1f, 0x00, 0x00, 
0xae, 0xaa, 0xea, 0xaa, 0xae, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x80, 0x80, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80
        };
      oled_write_raw_P(font_logo, sizeof(font_logo));
}

#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
  } else if (index == 1) { /* Second encoder */  
    if (clockwise) {
      backlight_increase();
    } else {
      backlight_decrease();
    }
  }
}
#endif

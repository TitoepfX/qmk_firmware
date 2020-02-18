/*
Copyright  2020 Titoepfx <titoepfx@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0526
#define DEVICE_VER      0x0001
#define MANUFACTURER    Ene6
#define PRODUCT         Cheka
#define DESCRIPTION     Split 48 percent ergonomic keyboard

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring
#define MATRIX_ROW_PINS { F4, D4, D7, E6, B4 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { C6 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE  3

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2

#define RGB_DI_PIN D3
#define RGBLED_SPLIT { 15, 15 }
#define RGBLED_NUM 30
/* BACKLIGHT PIN */
#define BACKLIGHT_PIN B5
#define BACKLIGHT_LEVELS 3
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 6
#define BACKLIGHT_ON_STATE 1	
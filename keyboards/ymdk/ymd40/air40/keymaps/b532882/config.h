/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* Select hand configuration */
#define COMBO_SHOULD_TRIGGER
#define COMBO_COUNT 13
#define COMBO_TERM 20

/* shift feature */
//#define AUTO_SHIFT_TIMEOUT_PER_KEY
#define AUTO_SHIFT_TIMEOUT 200
#define AUTO_SHIFT_REPEAT
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_SPECIAL

//#define NO_ACTION_TAPPING

//#define TAPPING_TERM_PER_KEY
//#define RETRO_TAPPING_PER_KEY
//#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//#define QUICK_TAP_TERM_PER_KEY
//#define PERMISSIVE_HOLD_PER_KEY

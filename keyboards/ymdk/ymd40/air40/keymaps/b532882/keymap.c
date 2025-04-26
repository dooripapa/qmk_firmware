/* Copyright 2022 Dennis Kruyt (dennis@kruyt.org)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12_2x2u(
KC_TAB          , KC_Q      , KC_W        , KC_E         , KC_R        , KC_T         , KC_Y         , KC_U        , KC_I          , KC_O         , KC_P    , KC_BSPC ,
LCTL_T(KC_ESC)  , LT(6,KC_A), KC_S        , KC_D         , LT(5,KC_F)  , KC_G         , KC_H         , KC_J        , KC_K          , KC_L         , KC_SCLN , KC_ENT  ,
KC_LSFT         , KC_Z      , KC_X        , KC_C         , KC_V        , KC_B         , KC_N         , KC_M        , KC_COMM       , KC_DOT       , KC_SLSH , KC_RSFT ,
                  KC_LCTL   , KC_LGUI     , KC_LALT      , KC_SPC      , MO(1)        , LT(2,KC_SPC) , MO(2)       , KC_RALT       , MO(3)        , QK_BOOT
),
[1] = LAYOUT_ortho_4x12_2x2u( //CW_TOGG
    _______  , KC_NO  , KC_NO  , C(S(KC_TAB)) , C(KC_TAB)     , KC_NO   , KC_HOME   , C(KC_PGUP)    , C(KC_PGDN)     , KC_NO   , KC_PGUP  , _______      ,
    _______  , KC_NO  , KC_NO  , KC_LSFT      , KC_LCTL       , KC_NO   , KC_LEFT   , KC_DOWN       , KC_UP          , KC_RGHT , KC_NO    , C(S(KC_ENT)) ,
    _______  , KC_NO  , KC_NO  , G(C(KC_LEFT)), G(C(KC_RIGHT)), KC_NO   , KC_END    , G(A(KC_LEFT)) , G(A(KC_RIGHT)) , KC_NO   , KC_PGDN  , _______      ,
               _______, _______,  _______     , _______       , _______ , KC_NO     , LCTL(KC_INS)  , LSFT(KC_INS)   , _______ , _______ 
),
[2] = LAYOUT_ortho_4x12_2x2u(
    _______ , S(KC_1)   , S(KC_2)  , S(KC_3)   , S(KC_4)   , S(KC_5)    , S(KC_6)    , S(KC_7)    , S(KC_8)    , S(KC_9)  , S(KC_0)    , _______ ,
    _______ , KC_GRV    , S(KC_GRV), KC_LCBR   , KC_RCBR   , S(KC_BSLS) , KC_EQL     , KC_MINS    , S(KC_QUOT) , KC_QUOT  , S(KC_SCLN) , _______ ,
    _______ , KC_NO     , KC_NO    , KC_LBRC   , KC_RBRC   , KC_BSLS    , S(KC_EQL)  , S(KC_MINS) , S(KC_COMM) , S(KC_DOT), S(KC_SLSH) , _______ ,
               _______, _______,  _______     , _______       , _______ , _______   , _______       , _______   , _______ , _______
),
[3] = LAYOUT_ortho_4x12_2x2u(
                        //change signature //rename //run            //debug   //unit test for current cursor position.
                        //stop                                                             //generate
    _______ , KC_NO   , KC_NO   , C(KC_F6)         , S(KC_F6), C(S(KC_F10))  , S(KC_F9)  , C(S(KC_F10)), A(KC_INS), KC_NO   , KC_NO   , _______ ,
    _______ , KC_NO   , C(KC_F2), KC_NO            , KC_NO   , KC_NO         , KC_NO     , KC_NO       , KC_NO    , KC_NO   , KC_NO   , _______ ,
                                                               //debug spot    //inline    //extract function
    _______ , KC_NO   , KC_NO   , KC_NO            , KC_NO   , C(KC_F8)      , C(A(KC_N)), C(A(KC_M))  , KC_NO    , KC_NO   , KC_NO   , _______ ,
               _______, _______,  _______     , _______       , _______ , _______   , _______       , _______        , _______ , _______
),
/*Game layout*/
[4] = LAYOUT_ortho_4x12_2x2u(
    KC_TAB   , KC_Q     , KC_W   , KC_E     , KC_R     , KC_T      , KC_Y      , KC_U         , KC_I      , KC_O      , KC_P    , KC_BSPC ,
    KC_LSFT  , KC_A     , KC_S   , KC_D     , KC_F     , KC_G      , KC_H      , KC_J         , KC_K      , KC_L      , KC_SCLN , KC_ENT  ,
    KC_LCTL  , KC_Z     , KC_X   , KC_C     , KC_V     , KC_B      , KC_N      , KC_M         , KC_COMM   , KC_DOT    , KC_SLSH , KC_RSFT ,
               _______,  _______, _______   , KC_SPC   , KC_SPC    , KC_RALT   , KC_ESC       , _______   , _______   , _______
),
[5] = LAYOUT_ortho_4x12_2x2u(
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO        , KC_7      , KC_8      , KC_9      , KC_0    , _______ ,
    _______  , KC_NO    , KC_NO  , KC_NO    , _______  , KC_NO     , KC_DOT       , KC_4      , KC_5      , KC_6      , KC_NO   , _______ ,
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_COMM      , KC_1      , KC_2      , KC_3      , KC_SLSH , _______ ,
               _______  , _______,  _______ , _______  , MO(1)     , LT(2,KC_SPC) , _______   , _______   , _______   , _______
),
[6] = LAYOUT_ortho_4x12_2x2u(
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO     , KC_F7        , KC_F8     , KC_F9      , KC_F10 , _______ ,
    _______  , _______  , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO     , KC_F4        , KC_F5     , KC_F6      , KC_F11 , _______ ,
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO     , KC_F1        , KC_F2     , KC_F3      , KC_F12 , _______ ,
               _______  , _______,  _______ , _______  , MO(1)     , LT(2,KC_SPC) , _______   , _______   , _______   , _______
)
};

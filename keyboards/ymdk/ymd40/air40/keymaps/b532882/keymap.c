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
LCTL_T(KC_ESC)  , LT(5,KC_A), KC_S        , KC_D         , LT(4,KC_F)  , KC_G         , KC_H         , KC_J        , KC_K          , KC_L         , KC_SCLN , KC_ENT  ,
KC_LSFT         , KC_Z      , KC_X        , KC_C         , KC_V        , KC_B         , KC_N         , KC_M        , KC_COMM       , KC_DOT       , KC_SLSH , KC_RSFT ,
                  C(KC_PGUP), C(KC_PGDN)  , KC_LGUI      , KC_LALT     , MO(1)        , LT(2,KC_SPC) , KC_RALT     , MO(3)         , G(A(KC_LEFT)), G(A(KC_RIGHT))
),
[1] = LAYOUT_ortho_4x12_2x2u( //CW_TOGG
    _______  , KC_NO  , KC_NO  , C(S(KC_TAB)) , C(KC_TAB)     , KC_NO   , KC_HOME   , C(KC_PGUP)    , C(KC_PGDN)     , KC_NO   , KC_PGUP  , _______      ,
    _______  , KC_NO  , KC_NO  , KC_LSFT      , KC_LCTL       , KC_NO   , KC_LEFT   , KC_DOWN       , KC_UP          , KC_RGHT , KC_NO    , C(S(KC_ENT)) ,
    _______  , KC_NO  , KC_NO  , G(C(KC_LEFT)), G(C(KC_RIGHT)), KC_NO   , KC_END    , G(A(KC_LEFT)) , G(A(KC_RIGHT)) , KC_NO   , KC_PGDN  , _______      ,
               _______, _______,  _______     , _______       , _______ , KC_NO     , LCTL(KC_INS)  , LSFT(KC_INS)   , _______ , QK_BOOT 
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
[4] = LAYOUT_ortho_4x12_2x2u(
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO        , KC_7      , KC_8      , KC_9      , KC_0    , _______ ,
    _______  , KC_NO    , KC_NO  , KC_NO    , _______  , KC_NO     , KC_DOT       , KC_4      , KC_5      , KC_6      , KC_NO   , _______ ,
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_COMM      , KC_1      , KC_2      , KC_3      , KC_SLSH , _______ ,
               _______  , _______,  _______ , _______  , MO(1)     , LT(2,KC_SPC) , _______   , _______   , _______   , _______
),
[5] = LAYOUT_ortho_4x12_2x2u(
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO     , KC_F7        , KC_F8     , KC_F9      , KC_F10 , _______ ,
    _______  , _______  , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO     , KC_F4        , KC_F5     , KC_F6      , KC_F11 , _______ ,
    _______  , KC_NO    , KC_NO  , KC_NO    , KC_NO    , KC_NO     , KC_NO     , KC_F1        , KC_F2     , KC_F3      , KC_F12 , _______ ,
               _______  , _______,  _______ , _______  , MO(1)     , LT(2,KC_SPC) , _______   , _______   , _______   , _______
)
};

#if 1

enum combs {
    PRN,    // ( )
    CBR,    // { }
    BRC,    // [ ]
    CWT,
	LEADER,
    PASSWRD1,
    PASSWRD2,
    PASSWRD3,
    GAME
};

const uint16_t PROGMEM prn_combo     [] = {KC_E   , KC_R       , COMBO_END}; // ( )
const uint16_t PROGMEM cbr_combo     [] = {KC_D   , LT(4,KC_F) , COMBO_END}; // { }
const uint16_t PROGMEM brc_combo     [] = {KC_C   , KC_V       , COMBO_END}; // [ ]
const uint16_t PROGMEM pass1_combo   [] = {KC_W   , KC_E       , COMBO_END}; //
const uint16_t PROGMEM pass2_combo   [] = {KC_S   , KC_D       , COMBO_END}; //
const uint16_t PROGMEM pass3_combo   [] = {KC_X   , KC_C       , COMBO_END}; //
const uint16_t PROGMEM game_combo    [] = {KC_TAB , KC_BSPC    , COMBO_END}; // game layout

/*
COMBO( big_combo , CW_TOGG ),
COMBO_ACTION( esc_combo      ),
*/
combo_t key_combos[COMBO_COUNT] = {
    [PRN]        = COMBO_ACTION( prn_combo      ),
    [CBR]        = COMBO_ACTION( cbr_combo      ),
    [BRC]        = COMBO_ACTION( brc_combo      ),
    [PASSWRD1]   = COMBO_ACTION( pass1_combo    ),
    [PASSWRD2]   = COMBO_ACTION( pass2_combo    ),
    [PASSWRD3]   = COMBO_ACTION( pass3_combo    ),
    [GAME]       = COMBO_ACTION( game_combo     ),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case PRN:  // ( )
        case CBR:  // { }
        case BRC:  // [ ]
        case PASSWRD1:
        case PASSWRD2:
        case PASSWRD3:
            if (layer_state_is(4)) {
                return false;
            }
        default:
            break;
    }

    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {

    switch(combo_index) {
        case PRN:
            if (pressed) {
                tap_code16(KC_LPRN);
                tap_code16(KC_RPRN);
            }
            break;
        case CBR:
            if (pressed) {
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
            }
            break;
        case BRC:
            if (pressed) {
                tap_code16(KC_LBRC);
                tap_code16(KC_RBRC);
            }
            break;
        case PASSWRD1:
            if (pressed) {
                SEND_STRING("krx12345!");
            }
            break;
        case PASSWRD2:
            if (pressed) {
                SEND_STRING("Rlqkstkdnjf4!");
            }
            break;
        case PASSWRD3:
            if (pressed) {
                SEND_STRING("Bursa2021!");
            }
            break;
    }
}
#endif


/////////////////////////////////////////////////////////////////////////////////
//  shfit feature
/////////////////////////////////////////////////////////////////////////////////
#if 1
uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
	int timeout=0;
    switch(keycode) {
		case KC_HOME:
		case KC_END:
            timeout=500;
			break;
		default:
            timeout=400;
			break;
    }
    return timeout;
}
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
		case KC_HOME:
		case KC_END:
            return true;
        default:
            return false;
    }
}
void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_HOME:
            register_code16((!shifted) ? KC_HOME: S(KC_HOME));
            break;
		case KC_END:
            register_code16((!shifted) ? KC_END: S(KC_END));
			break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_HOME:
            unregister_code16((!shifted) ? KC_HOME: S(KC_HOME));
            break;
		case KC_END:
            unregister_code16((!shifted) ? KC_END: S(KC_END));
			break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
/////////////////////////////////////////////////////////////////////////////////
//  end shfit feature
/////////////////////////////////////////////////////////////////////////////////
#endif

/////////////////////////////////////////////////////////////////////////////////
//  key detail controls
/////////////////////////////////////////////////////////////////////////////////
/*
 * #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY 
 * 설정 되어 있어야 한다.
 *                          TAPPING_TERM
  +---------------------------|--------+
  | +-------------+           |        |
  | | LT(2, KC_A) |           |        |
  | +-------------+           |        |
  |   +------------------+    |        |
  |   | KC_L(layer2, ->) |    |        |
  |   +------------------+    |        |
  +---------------------------|--------+
  -> TERM안에 일반적으로 A, L 키가 입력됨.
  -> get_hold_on_other_key_press 에 설정된 키는
  -> TERM무시하고 즉시 A, -> 입력이 됨
 */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LCTL_T(KC_ESC):
			return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
/*
 *                         TAPPING_TERM   
  +---------------------------|--------+
  | +----------------------+  |        |
  | | LT(2, KC_A)          |  |        |
  | +----------------------+  |        |
  |   +------------------+    |        |
  |   | KC_L(layer2, ->) |    |        |
  |   +------------------+    |        |
  +---------------------------|--------+
  이럴 경우, 일반적으로 TERM이내 이므로, A,L 이나
  permissive로 설정되어 있다면, A, -> 가 된다.
 */

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_SPC):
			return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

/*
 * tap, hold 개별 설정을 함.
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LT(4,KC_F):
		case LT(5,KC_A):
            return 230;
        default:
            return 170;
    }
}

/* 
 * LT(2,KC_SPC) 한번 누른 후, 두번 째 hold 했을 경우
 * 연속키가 자동으로 입력된다. 그 간격을 조정하는 함수.
 * 그 간격 값이 작을 경우, 빠른 입력이 repeat가 발생됨
 * 이 키는 hold보다 우선 한다.
 */
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_SPC):
            return 110;
        default:
            return 180;
    }
}

/* 
 * LT(0,X) 키 형식을 retro로 지정하면 안된다
 * 이 함수의 기능은, hold한 후 제2의 키를 입력하지 않는다면, 
 * 해당키가 즉시 입력된다.
 * LT(1,KC_SPC) 라고하면, KC_SPC키가 바로 입력된다.
 */
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LT(4,KC_F): 
		case LT(5,KC_A): 
        case LT(2,KC_SPC):
		case LCTL_T(KC_ESC):
            return true;
        default:
            return false;
    }
}
/////////////////////////////////////////////////////////////////////////////////
//  key detail controls
/////////////////////////////////////////////////////////////////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {


    uint8_t mod_state;
    static bool delkey_registered ,ctrlbrace_registered ,ctrlt_registered;

    /**
     * KC_BSPC 는 shift키를 누르면, KC_DEL로 작동하는 로직
     */
    switch (keycode) {
        // Store the current modifier state in the variable for later reference
        case KC_BSPC:
            mod_state = get_mods(); // Initialize a boolean variable that keeps track // of the delete key status: registered or not?
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
			break;
        //ctrl + , 누르면 ctrl + t로 대응함.
        case KC_COMM:
            mod_state = get_mods();
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    register_code(KC_T);
                    ctrlt_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (ctrlt_registered) {
                    unregister_code(KC_T);
                    ctrlt_registered = false;
                    return false;
                }
            }
			break;
            //ctrl + . 누르면 ctrl + ]로 대응함.
        case KC_DOT:
            mod_state = get_mods();
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    register_code(KC_RBRC);
                    ctrlbrace_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (ctrlbrace_registered) {
                    unregister_code(KC_RBRC);
                    ctrlbrace_registered = false;
                    return false;
                }
            }
			break;
        default:
            break;
    }
    return true;
}

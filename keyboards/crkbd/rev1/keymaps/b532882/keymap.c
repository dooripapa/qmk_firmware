/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum {
    TD_CBR,
    TD_BRC
};

void line_selected(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        tap_code16(KC_HOME);
        tap_code16(S(KC_END));
        reset_tap_dance(state);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_CBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x6_3(
    KC_TAB   , KC_Q      , KC_W   , KC_E    , KC_R       , KC_T         , KC_Y         , KC_U    , KC_I     , KC_O     , KC_P    , KC_BSPC      ,
    KC_LCTL  , KC_A      , KC_S   , KC_D    , KC_F       , KC_G         , KC_H         , KC_J    , KC_K     , KC_L     , KC_SCLN , KC_ENT       ,
    KC_LSFT  , KC_Z      , KC_X   , KC_C    , KC_V       , KC_B         , KC_N         , KC_M    , KC_COMM  , KC_DOT   , KC_SLSH , KC_RSFT      ,
                                    KC_LGUI , KC_LALT    , MO(1)        , LT(2,KC_SPC) , KC_RALT , MO(3)
),

[1] = LAYOUT_split_3x6_3( //CW_TOGG
    _______  , KC_NO  , KC_NO  , C(S(KC_TAB)) , C(KC_TAB)     , KC_NO   , KC_HOME   , C(KC_PGUP)    , C(KC_PGDN)     , KC_NO   , KC_PGUP  , _______   ,
    _______  , KC_NO  , KC_NO  , KC_LSFT      , KC_LCTL       , KC_NO   , KC_LEFT   , KC_DOWN       , KC_UP          , KC_RGHT , KC_NO    , _______   ,
    _______  , KC_NO  , KC_NO  , G(C(KC_LEFT)), G(C(KC_RIGHT)), KC_NO   , KC_END    , G(A(KC_LEFT)) , G(A(KC_RIGHT)) , KC_NO   , KC_PGDN  , _______   ,
                                 _______      , _______       , _______ , KC_NO     , LCTL(KC_INS)  , LSFT(KC_INS)
),

[2] = LAYOUT_split_3x6_3(
    _______ , S(KC_1)   , S(KC_2)  , S(KC_3)   , S(KC_4)   , S(KC_5)    , S(KC_6)    , S(KC_7)    , S(KC_8)    , S(KC_9)  , S(KC_0)    , _______ ,
    _______ , KC_GRV    , S(KC_GRV), KC_LCBR   , KC_RCBR   , S(KC_BSLS) , KC_EQL     , KC_MINS    , S(KC_QUOT) , KC_QUOT  , S(KC_SCLN) , _______ ,
    _______ , KC_NO     , KC_NO    , KC_LBRC   , KC_RBRC   , KC_BSLS    , S(KC_EQL)  , S(KC_MINS) , S(KC_COMM) , S(KC_DOT), S(KC_SLSH) , _______ ,
                                     _______   , _______   , _______    , _______    , _______    , _______
),


[3] = LAYOUT_split_3x6_3(
		                        //change signature //rename //run           //debug
    _______ , KC_NO   , KC_NO   , C(KC_F6)         , S(KC_F6), C(S(KC_F10))  , S(KC_F9)  , KC_NO     , A(KC_INS), KC_NO   , KC_NO   , _______ ,
	                    //stop                                                                         //generate
    _______ , KC_NO   , C(KC_F2), KC_NO            , KC_NO   , KC_NO         , KC_NO     , KC_NO     , KC_NO    , KC_NO   , KC_NO   , _______ ,
	                                                           //debug spot    //inline    //extract function
    _______ , KC_NO   , KC_NO   , KC_NO            , KC_NO   , C(KC_F8)      , C(A(KC_N)), C(A(KC_M)), KC_NO    , KC_NO   , KC_NO   , _______ ,
                                 _______           , _______ , KC_SPC        , KC_SPC    , KC_NO     , _______
),                                                           
/*Game layout*/
[4] = LAYOUT_split_3x6_3(
    KC_TAB  , KC_Q  , KC_W   , KC_E     , KC_R     , KC_T     , KC_Y      , KC_U     , KC_I     , KC_O     , KC_P    , KC_BSPC ,
    KC_LSFT , KC_A  , KC_S   , KC_D     , KC_F     , KC_G     , KC_H      , KC_J     , KC_K     , KC_L     , KC_SCLN , KC_ENT  ,
    KC_LCTL , KC_Z  , KC_X   , KC_C     , KC_V     , KC_B     , KC_N      , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH , KC_RSFT ,
                               _______  , _______  , KC_SPC   , KC_SPC    , KC_RALT  , KC_ESC
),

[5] = LAYOUT_split_3x6_3(
    _______  , KC_NO      , KC_NO      , KC_NO      , KC_NO     , KC_NO        , KC_NO        , KC_7      , KC_8      , KC_9   , KC_0       , _______ ,
    _______  , KC_NO      , KC_NO      , KC_NO      , KC_NO     , KC_NO        , KC_DOT       , KC_4      , KC_5      , KC_6   , KC_NO      , _______ ,
    _______  , KC_NO      , KC_NO      , KC_NO      , KC_NO     , KC_NO        , KC_COMM      , KC_1      , KC_2      , KC_3   , KC_SLSH    , _______ ,
                                           _______  , _______   , MO(1)        , LT(2,KC_SPC) , _______   , _______
),

[6] = LAYOUT_split_3x6_3(
    _______  , KC_NO     , KC_NO  , KC_NO   , KC_NO    , KC_NO    , KC_NO          , KC_F7    , KC_F8    , KC_F9  , KC_F10   , _______ ,
    _______  , KC_NO     , KC_NO  , KC_NO   , KC_NO    , KC_NO    , KC_NO          , KC_F4    , KC_F5    , KC_F6  , KC_F11   , _______ ,
    _______  , KC_NO     , KC_NO  , KC_NO   , KC_NO    , KC_NO    , KC_NO          , KC_F1    , KC_F2    , KC_F3  , KC_F12   , _______ ,
                                    _______ , _______  , MO(1)    , LT(2,KC_SPC)   , _______ , _______
),

};


#if 1

enum combs {
    ESC,
    PRN,  // ( )
    CBR,  // { }
    BRC,  // [ ]
    CWT,
	LEADER,
    PASSWRD1,
    PASSWRD2,
    PASSWRD3,
    GAME
};

const uint16_t PROGMEM esc_combo     [] = {KC_J   , KC_K       , COMBO_END};
const uint16_t PROGMEM prn_combo     [] = {KC_E   , KC_R       , COMBO_END}; // ( )
const uint16_t PROGMEM cbr_combo     [] = {KC_D   , KC_F       , COMBO_END}; // { }
const uint16_t PROGMEM brc_combo     [] = {KC_C   , KC_V       , COMBO_END}; // [ ]
const uint16_t PROGMEM cw_togg_combo [] = {KC_U   , KC_I       , COMBO_END}; // ==
const uint16_t PROGMEM leader_combo  [] = {KC_M   , KC_COMM    , COMBO_END}; // ==
const uint16_t PROGMEM pass1_combo   [] = {KC_W   , KC_E       , COMBO_END}; //
const uint16_t PROGMEM pass2_combo   [] = {KC_S   , KC_D       , COMBO_END}; //
const uint16_t PROGMEM pass3_combo   [] = {KC_X   , KC_C       , COMBO_END}; //
const uint16_t PROGMEM game_combo    [] = {KC_TAB , KC_BSPC    , COMBO_END}; // game layout

/*
COMBO( big_combo , CW_TOGG ),
COMBO_ACTION( esc_combo      ),
*/
combo_t key_combos[COMBO_COUNT] = {
    [ESC]        = COMBO_ACTION( esc_combo      ),
    [PRN]        = COMBO_ACTION( prn_combo      ),
    [CBR]        = COMBO( cbr_combo    , MO(5)  ),
    [BRC]        = COMBO( brc_combo    , MO(6)  ),
    [CWT]        = COMBO(cw_togg_combo , CW_TOGG),
    [LEADER]     = COMBO(leader_combo  , QK_LEAD),
    [PASSWRD1]   = COMBO_ACTION( pass1_combo    ),
    [PASSWRD2]   = COMBO_ACTION( pass2_combo    ),
    [PASSWRD3]   = COMBO_ACTION( pass3_combo    ),
    [GAME]       = COMBO_ACTION( game_combo     ),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case ESC:
        case PRN:  // ( )
        case CBR:  // { }
        case BRC:  // [ ]
        case CWT:
        case LEADER:
        case PASSWRD1:
        case PASSWRD2:
        case PASSWRD3:
            if (layer_state_is(4)) {
                return false;
            }
        case GAME:
        default:
            break;
    }

    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {

    switch(combo_index) {
        case ESC:
            if (pressed) {
                tap_code16(KC_ESC);
            }
            break;
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
                SEND_STRING("Rlqksvkfdnjf8!");
            }
            break;
        case PASSWRD3:
            if (pressed) {
                SEND_STRING("Bursa2021!");
            }
            break;
        case GAME:
            if (pressed) {
                SEND_STRING("switch");
                layer_invert(4);
            }
            break;
    }
}
#endif


#define TIMEOUT_MS 200  // Timeout in milliseconds.
#define RECENT_SIZE 2    // Number of keys in `recent` buffer.

static uint16_t recent[RECENT_SIZE] = {KC_NO};
static uint16_t deadline = 0;

static void clear_recent_keys(void) {
    memset(recent, 0, sizeof(recent));  // Set all zeros (KC_NO).
}

#if 0
// Handles one event. Returns true if the key was appended to `recent`.
static bool update_recent_keys(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) { return false; }
    if (((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT) != 0) {
        clear_recent_keys();  // Avoid interfering with hotkeys.
        return false;
    }

    // Handle tap-hold keys.
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) { return false; }
            keycode &= 0xff;  // Get tapping keycode.
    }

    switch (keycode) {
/* jk -> esc 키맵핑 취소
        case KC_J:
        case KC_K:
            break;
*/

        case KC_LSFT:  // These keys don't type anything on their own.
        case KC_RSFT:
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
            return false;

        default:  // Avoid acting otherwise, particularly on navigation keys.
            clear_recent_keys();
            return false;
    }

    // Slide the buffer left by one element.
    memmove(recent, recent + 1, (RECENT_SIZE - 1) * sizeof(*recent));

    recent[RECENT_SIZE - 1] = keycode;
    deadline = record->event.time + TIMEOUT_MS;
    return true;
}
#endif

void matrix_scan_user(void) {
    if (recent[RECENT_SIZE - 1] && timer_expired(timer_read(), deadline)) {
        clear_recent_keys();  // Timed out; clear the buffer.
    }
}

#if 0
static bool process_tap_or_long_press_key(
    keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) {  // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false;  // Skip default handling.
    }
    return true;  // Continue default handling.
}
#endif

/////////////////////////////////////////////////////////////////////////////////
//  shfit feature
/////////////////////////////////////////////////////////////////////////////////
#if 1
uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
	int timeout=0;
    switch(keycode) {
		/*
        case AUTO_SHIFT_NUMERIC:
            return get_generic_autoshift_timeout();
        case AUTO_SHIFT_SPECIAL:
            return get_generic_autoshift_timeout() * 2;
        case AUTO_SHIFT_ALPHA:
            timeout=200;
			break;
		*/
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
//  leader key
/////////////////////////////////////////////////////////////////////////////////
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    // Intellij 함수생성
    if (leader_sequence_two_keys(KC_N, KC_F)) {
        tap_code16( A(S(KC_ENT)) );
    }
        // Intellij 함수단위테스트 실행
    else if (leader_sequence_two_keys(KC_F, KC_T)) {
        tap_code16( C(S(KC_F10)) );
    }
        // Intellij Debugging BreakPoint
    else if (leader_sequence_one_key(KC_B)) {
        tap_code16( C(KC_F8) );
    }
        // Intellij Run Build
    else if (leader_sequence_two_keys(KC_R,KC_B)) {
        tap_code16( C(KC_F9) );
    }
        // Intellij Run
    else if (leader_sequence_one_key(KC_E)) {
        tap_code16( S(KC_F10) );
    }
        // Intellij Run Debugging
    else if (leader_sequence_one_key(KC_D)) {
        tap_code16( S(KC_F9) );
    }
        // 스텝
    else if (leader_sequence_one_key(KC_I)) {
        tap_code16( KC_F8 );
    }
        // into
    else if (leader_sequence_one_key(KC_U)) {
        tap_code16( KC_F7 );
    }
        // 만날때까지
    else if (leader_sequence_one_key(KC_O)) {
        tap_code16( KC_F9 );
    }
        // 디버깅 중단
    else if (leader_sequence_one_key(KC_COMM)) {
        tap_code16( C(KC_F2) );
    }
}
/////////////////////////////////////////////////////////////////////////////////
//  leader key end
/////////////////////////////////////////////////////////////////////////////////
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }
    return rotation;
}

#    define L_BASE      0
#    define L_LOWER     2
#    define L_RAISE     4
#    define L_ADJUST    8
#    define L_FUNC_KEY  16
#    define L_GAME      32

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Direction"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Sign"), false);
            break;
        case L_ADJUST:
            oled_write_ln_P(PSTR("0~9 pad"), false);
            break;
        case L_FUNC_KEY:
            oled_write_ln_P(PSTR("F1~F12 pad"), false);
            break;
        case L_GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
//        case L_ADJUST:
//        case L_ADJUST | L_LOWER:
//        case L_ADJUST | L_RAISE:
//        case L_ADJUST | L_LOWER | L_RAISE:
//            oled_write_ln_P(PSTR("Adjust"), false);
//            break;
    };
}

char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

/*Rolling key*/
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //case LT(2,KC_SPC):
            // Immediately select the hold action when another key is pressed.
            //return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_SPC):
        case LT(2,KC_SPC):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_CBR):
        case TD(TD_BRC):
            return 200;
		case LT(0,KC_ENT):
            return 200;
        case LT(2,KC_SPC):
            return 150;
		case LT(6,KC_A):
		case LT(5,KC_F):
            return 230;
        default:
            return 180;
    }
}

/* 
 * LT(2,KC_SPC) 한번 누른 후, 두번 째 hold 했을 경우
 * 연속키가 자동으로 입력된다. 그 간격을 조정하는 함수.
 */
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_SPC):
            return 150;
        default:
            return 180;
    }
}

/* 
 * LT(0,X) 키 형식을 retro로 지정하면 안된다
 * 이 함수의 기능은, hold한 후 제2의 키를 입력하지 않는다면, 
 * LT(1,KC_SPC) 라고하면, KC_SPC키가 바로 입력된다.
 */
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LT(6,KC_A):
		case LT(5,KC_F):
        case LT(1,KC_SPC):
        case LT(2,KC_SPC):
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {


    uint8_t mod_state;
    static bool delkey_registered ,ctrlbrace_registered ,ctrlt_registered;

    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

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
		case LT(0, KC_ENT):
			if (!record->tap.count && record->event.pressed) {
                tap_code16( C(S(KC_ENT)) ); // Intercept hold function to send Ctrl-X
                return false;
            }
			break;
        default:
            break;
    }
    return true;
}
#endif // OLED_ENGAME

/* Copyright 2021 Ben Roesner (keycapsss.com)
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
#include <stdio.h>

// Tap Dance declarations
enum {
    TD_SLASH_LAYERS,
};

enum layers {
    _NUMPAD,
    _WINDOWS,
    _MEDIA
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SLASH_LAYERS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_KP_SLASH, _WINDOWS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* NUMPAD layer
    * ,-----------------------,
    * |  7  |  8  |  9  |  /  |
    * |-----+-----+-----+-----|
    * |  4  |  5  |  6  |  *  |
    * |-----+-----+-----+-----|
    * |  1  |  2  |  3  |  -  |
    * |-----+-----+-----+-----|
    * |  0  |  .  |  =  |  +  |
    * `-----------------------'
    */
    [_NUMPAD] = LAYOUT_ortho_4x4(
        KC_P7, KC_P8,   KC_P9,    TD(TD_SLASH_LAYERS),
        KC_P4, KC_P5,   KC_P6,    KC_PAST,
        KC_P1, KC_P2,   KC_P3,    KC_PMNS,
        KC_P0, KC_PDOT, KC_PEQL,  KC_PPLS
    ),
    /* Windows layer
    * ,-----------------------,
    * | ALT |LCTL |LCTL |  UP |
    * |  F4 |  W  | F4  |     |
    * |-----+-----+-----+-----|
    * | LCA | MY  |FIND |CALC |
    * | DEL | COMP|     |     |
    * |-----+-----+-----+-----|
    * | ALT |  F2 |  F5 | F12 |
    * | TAB |     |     |     |
    * |-----+-----+-----+-----|
    * |LGUI | PRT | NUM |UNDO |
    * | DOT | SCN | LOCK| (KC)|
    * `-----------------------'
    */
    [_WINDOWS] = LAYOUT_ortho_4x4(
	    LALT(KC_F4),  	      LCTL(KC_W),    LCTL(KC_F4),  TO(_MEDIA),    
        LCA(KC_DELETE),       KC_MYCM,       KC_FIND,      KC_CALC,
        LALT(KC_TAB),         KC_F2,         KC_F5,        KC_F12,
        LGUI(KC_DOT),         KC_PSCREEN,    KC_NLCK,      KC_UNDO
    ),
    /* MEDIA layer
	* ,-----------------------,
    * |PREV |PLAY |NEXT | UP  |
    * |TRACK|PAUSE|TRACK|     |
    * |-----+-----+-----+-----|
    * |VOL  |STOP |VOL  |MUTE |
    * |DOWN |     | UP  |     |
    * |-----+-----+-----+-----|
    * |milk |  F2 |seek |seek |
    * |drop |     |back | fwd |
    * |-----+-----+-----+-----|
    * |rpt  |shuf |next |rmv  |
    * |plist|plist|plist|track|
    * `-----------------------'
    */
    [_MEDIA] = LAYOUT_ortho_4x4(
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, TO(_NUMPAD),
        KC_AUDIO_VOL_DOWN,   KC_MEDIA_STOP,       KC_AUDIO_VOL_UP,     KC_AUDIO_MUTE,
        HYPR(KC_M),          KC_F2,               RCS(KC_LEFT),        RCS(KC_RIGHT),
        RCS(KC_R),           RCS(KC_S),           LCAG(KC_N),          HYPR(KC_DELETE)
    ),

};

#ifdef OLED_ENABLE
void render_space(void) {
  oled_write_P(PSTR("     "), false);
}

// Max Characters Per Line: 21
// Max Lines: 4
static const char PROGMEM raw_logo_top[] = {
        56,254,123, 57, 61, 93,223,240,192,224,224,252,252,224,224,
};
static const char PROGMEM raw_logo_bottom[] = {
       0,  1,  7, 14, 88,208,247,247, 18, 57,127,124, 14,  3,  1,
};

void oled_render_layer_state(void) {
  if(layer_state_is(_MEDIA)) {
    oled_write_ln_P(PSTR("Media"), false);
  } else if(layer_state_is(_WINDOWS)) {
    oled_write_ln_P(PSTR("Windows"), false);
  } else {
    oled_write_ln_P(PSTR("Default (NumPad)"), false);
  }
  oled_set_cursor(18, 2);
  oled_write_raw_P(raw_logo_top, sizeof(raw_logo_top));
  oled_set_cursor(18, 3);
  oled_write_raw_P(raw_logo_bottom, sizeof(raw_logo_bottom));
}

void oled_task_user(void) {
  oled_render_layer_state();
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/*
    ,-----------------------,
    |  E1 |  E2 |  E3 |  E4 |
    |-----+-----+-----+-----|
    |     |     |     |  E3 |
    |-----+-----+-----+-----|
    |     |     |     |  E2 |
    |-----+-----+-----+-----|
    |     |     |     |  E1 |
    `-----------------------'
 */

  // Fourth encoder (E4)
  if (index == 3) {
    if(layer_state_is(_MEDIA) || layer_state_is(_WINDOWS)) {
    // Windows Undo/Redo (Cmd+Y/Z)
    if (clockwise) {
      register_code(KC_LCTL);
      tap_code(KC_Y);
      unregister_code(KC_LCTL);
    } else {
      register_code(KC_LCTL);
      tap_code(KC_Z);
      unregister_code(KC_LCTL);
    }
    } else {
    // MacOS Undo/Redo (Cmd+Y/Z)
    if (clockwise) {
      register_code(KC_LGUI);
      tap_code(KC_Y);
      unregister_code(KC_LGUI);
    } else {
      register_code(KC_LGUI);
      tap_code(KC_Z);
      unregister_code(KC_LGUI);
    }
    }
  }
    return true;
}
#endif

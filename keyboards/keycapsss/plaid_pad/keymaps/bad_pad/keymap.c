#include QMK_KEYBOARD_H
#include <stdio.h>
#ifdef OLED_DRIVER_ENABLE
// Max Characters Per Line: 21
// Max Lines: 4
static const char PROGMEM raw_logo_top[] = {
        56,254,123, 57, 61, 93,223,240,192,224,224,252,252,224,224,
};
static const char PROGMEM raw_logo_bottom[] = {
       0,  1,  7, 14, 88,208,247,247, 18, 57,127,124, 14,  3,  1,
};
void oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default (numpad)\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Windows\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined layer OH SHI-"), false);
    }	
	oled_set_cursor(18, 2);
    oled_write_raw_P(raw_logo_top, sizeof(raw_logo_top));
	oled_set_cursor(18, 3);
    oled_write_raw_P(raw_logo_bottom, sizeof(raw_logo_bottom));
}
#endif

// Tap Dance declarations
enum {
    TD_SLASH_LAYERS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SLASH_LAYERS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_KP_SLASH, 1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
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
[0]=LAYOUT_ortho_4x4(
		KC_P7, KC_P8,   KC_P9,      TD(TD_SLASH_LAYERS),
		KC_P4, KC_P5,   KC_P6,      KC_PAST,
		KC_P1, KC_P2,   KC_P3,      KC_PMNS,
		KC_P0, KC_PDOT, KC_PEQL,    KC_PPLS
),
[1]=LAYOUT_ortho_4x4(
         LALT(KC_F4),  	       LCTL(KC_W),    LCTL(KC_F4),  KC_TRNS,    
         LCA(KC_DELETE),       KC_MYCM,       KC_FIND,      KC_CALC,
         LALT(KC_TAB),         KC_F2,         KC_F5,        KC_DELETE,
         LGUI(KC_DOT),         KC_PSCREEN,    KC_F12,       KC_UNDO      
)
};

// Set led state during powerup
void keyboard_post_init_user(void) {
    writePinHigh(LED_RED);
}

void encoder_update_user(uint8_t index, bool clockwise) {
/*
Rev1.1                      Rev1
,-----------------------,   ,-----------------------,
|  E1 |  E2 |  E3 |  E4 |   |  E1 |     |     |  E2 |
|-----+-----+-----+-----|   |-----+-----+-----+-----|
|     |     |     |  E3 |   |     |     |     |     |
|-----+-----+-----+-----|   |-----+-----+-----+-----|
|     |     |     |  E2 |   |     |     |     |     |
|-----+-----+-----+-----|   |-----+-----+-----+-----|
|     |     |     |  E1 |   |     |     |     |     |
`-----------------------'   `-----------------------'
 */

 
  // Fourth encoder (E4)
  if (index == 3) {
	  switch (get_highest_layer(layer_state)) {
        case 0:
            if (clockwise) {
				register_code(KC_LGUI);
                tap_code(KC_Y);
                unregister_code(KC_LGUI);
			} else {
				register_code(KC_LGUI);
                tap_code(KC_Z);
                unregister_code(KC_LGUI);
			}
            break;
        case 1:
            if (clockwise) {
				register_code(KC_LCTL);
                tap_code(KC_Y);
                unregister_code(KC_LCTL);
			} else {
				register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LCTL);
			}
            break;
        default:
            if (clockwise) {
				register_code(KC_LCTL);
                tap_code(KC_Y);
                unregister_code(KC_LCTL);
			} else {
				register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LCTL);
			}
			break;
    }
  }
}

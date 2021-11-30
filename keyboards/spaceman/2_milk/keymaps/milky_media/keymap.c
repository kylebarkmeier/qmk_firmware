#include QMK_KEYBOARD_H
#include "print.h"

enum tap_dance_codes {
  MEDIA_TD,
  MILKDROP_TD
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap media_dance_state[3];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_media_dance(qk_tap_dance_state_t *state, void *user_data);
void media_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void media_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_media_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count >= 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void media_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    media_dance_state[0].step = dance_step(state);
    switch (media_dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}          

void media_dance_reset(qk_tap_dance_state_t *state, void *user_data) { 
    wait_ms(10);
    switch (media_dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    media_dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [MEDIA_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_media_dance, media_dance_finished, media_dance_reset)
};

// TODO:
// Launch Milkdrop: Shift+ctrl+alt+win+M (global)
// Show track info in mildrop2: F2
// Track seek: left arrow/right arrow (+shift+ctrl for global)
// Normal (Repeat playlist): Shift+ctrl+R
// Shuffle: Shift+ctrl+S
// Delete from playlist: Shift+ctrl+alt+win+DEL (global)
// Next Playlist: Ctrl+alt+win+N (global)

void keyboard_post_init_user(void) {
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3);
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
		  TD(MEDIA_TD),
          LT(1, KC_SPACE)
          ),
	  [1] = LAYOUT(
		  KC_ESC,
          KC_TRNS
          )
};
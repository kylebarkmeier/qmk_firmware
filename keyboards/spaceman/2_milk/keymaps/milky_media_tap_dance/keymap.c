#include QMK_KEYBOARD_H
#include "print.h"

// TODO:
// Launch Milkdrop: Shift+ctrl+alt+win+M (global)
// Show track info in mildrop2: F2
// Track seek: left arrow/right arrow (+shift+ctrl for global)
// Normal (Repeat playlist): Shift+ctrl+R
// Shuffle: Shift+ctrl+S
// Delete from playlist: Shift+ctrl+alt+win+DEL (global)
// Next Playlist: Ctrl+alt+win+N (global)

enum tap_dance_codes {
  MEDIA_TD,
  MILKDROP_TD,
  FOOBAR_TD
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
static tap milkdrop_dance_state[3];
static tap foobar_dance_state[3];

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

void on_milkdrop_dance(qk_tap_dance_state_t *state, void *user_data);
void milkdrop_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void milkdrop_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_milkdrop_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count >= 3) {
        tap_code16(KC_SPACE);
    }
}

void milkdrop_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    milkdrop_dance_state[0].step = dance_step(state);
    switch (milkdrop_dance_state[0].step) {
        case SINGLE_TAP: tap_code16(KC_SPACE); break;
        case SINGLE_HOLD: tap_code16(KC_ESC); break;
        case DOUBLE_TAP: tap_code16(HYPR(KC_M)); tap_code16(KC_F2); /* launch milkdrop2 & show track info */ break;
        case DOUBLE_HOLD: layer_move(1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); break;
    }
}

void milkdrop_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    milkdrop_dance_state[0].step = 0;
}

void on_foobar_dance(qk_tap_dance_state_t *state, void *user_data);
void foobar_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void foobar_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_foobar_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count >= 3) {
        tap_code16(KC_SPACE);
    }
}

void foobar_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    foobar_dance_state[0].step = dance_step(state);
    switch (foobar_dance_state[0].step) {
        case SINGLE_TAP: tap_code16(RCS(KC_R)); /* repeat playlist */ break;
        case DOUBLE_TAP: tap_code16(RCS(KC_S)); /* Shuffle playlist */ break;
        case SINGLE_HOLD: tap_code16(LCAG(KC_N)); /* next playlist */break;
        case DOUBLE_HOLD: tap_code16(HYPR(KC_DELETE)); /* remove track from playlist */ break;
    }
}

void foobar_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    foobar_dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [MEDIA_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_media_dance, media_dance_finished, media_dance_reset),
        [MILKDROP_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_milkdrop_dance, milkdrop_dance_finished, milkdrop_dance_reset),
        [FOOBAR_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_foobar_dance, foobar_dance_finished, foobar_dance_reset),
};

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
    case 1:
#ifdef RGBLIGHT_ENABLE
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb(RGB_PINK);
#endif
        break;
    case 2:
#ifdef RGBLIGHT_ENABLE
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb(RGB_BLUE);
#endif
        break;
    case 3:
#ifdef RGBLIGHT_ENABLE
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb(RGB_PURPLE);
#endif
        break;
    default: //  for any other layers, or the default layer
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
#endif
        break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
		  TD(MEDIA_TD),
          TD(MILKDROP_TD)
          ),
      [1] = LAYOUT(
		  TD(FOOBAR_TD),
          TO(0)
          )
};

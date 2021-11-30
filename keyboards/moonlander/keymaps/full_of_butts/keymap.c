#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_172_255_255,
  HSV_217_253_255,
  HSV_0_255_255,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_DELETE,                                      LGUI(LCTL(KC_SPACE)),KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,      
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_HOME,                                        KC_PGUP,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,      
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_END,                                                                         KC_PGDOWN,      KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_ENTER,       
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,        
    LCTL_T(KC_ESCAPE),LGUI_T(KC_ESCAPE),LALT_T(KC_ESCAPE),KC_LEFT,        KC_RIGHT,       KC_SPACE,                                                                                                       SCMD_T(KC_SPACE),KC_DOWN,        KC_UP,          KC_LBRACKET,    KC_RBRACKET,    TT(1),          
    KC_QUOTE,       KC_MINUS,       KC_EQUAL,                       RGB_MOD,        TD(DANCE_0),    TD(DANCE_1)
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_PSCREEN,     KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_BSPACE,      
    KC_TAB,         MU_TOG,         RGB_VAI,        RGB_SPI,        RGB_HUI,        RGB_SAI,        KC_TRANSPARENT,                                 KC_F11,         KC_KP_PLUS,     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_BSLASH,      
    KC_FIND,        MU_MOD,         RGB_VAD,        RGB_SPD,        RGB_HUD,        RGB_SAD,        KC_TRANSPARENT,                                                                 KC_F12,         KC_KP_MINUS,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_ENTER,       
    KC_LSPO,        AU_TOG,         RGB_SLD,        TOGGLE_LAYER_COLOR,RGB_TOG,        RGB_MOD,                                        KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    KC_RSPC,        
    LCTL_T(KC_ESCAPE),LGUI_T(KC_ESCAPE),LALT_T(KC_ESCAPE),KC_LEFT,        KC_RIGHT,       KC_TRANSPARENT,                                                                                                 WEBUSB_PAIR,    KC_DOWN,        KC_UP,          KC_KP_0,        KC_KP_EQUAL,    KC_TRANSPARENT, 
    HSV_172_255_255,HSV_217_253_255,HSV_0_255_255,                  RGB_MOD,        KC_TRANSPARENT, TO(2)
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LCTRL,       KC_BSPACE,      KC_LALT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255} },

    [2] = { {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_217_253_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(217,253,255);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
  }
  return true;
}

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

static tap dance_state[2];

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


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_F)));
        tap_code16(LGUI(LSFT(KC_F)));
        tap_code16(LGUI(LSFT(KC_F)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_F)));
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_F))); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_R))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_F))); register_code16(LGUI(LSFT(KC_F))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_F))); register_code16(LGUI(LSFT(KC_F)));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_F))); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_R))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_F))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_F))); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_O)));
        tap_code16(LGUI(LSFT(KC_O)));
        tap_code16(LGUI(LSFT(KC_O)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_O)));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_O))); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_O))); register_code16(LGUI(LSFT(KC_O))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_O))); register_code16(LGUI(LSFT(KC_O)));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_O))); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_O))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_O))); break;
    }
    dance_state[1].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};


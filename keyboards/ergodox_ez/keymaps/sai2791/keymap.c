#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

//Tap Dance Config
enum {
  TD_ALT_SCRCAP = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap - Press ALT or press twice for Screen Capture
  [TD_ALT_SCRCAP] = ACTION_TAP_DANCE_DOUBLE(KC_LALT,KC_SCRCAP)
  // Other declarations would go here, separated by commas, if you have them
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  KC_OPENER,
  KC_WOWESC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | TO(3)|   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L0  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|  LGui  |
  * |        +------+Shift +CTRL+  ALT   +------|      |           |      |------| ALT  +Ctrl  +Shift +------+--------|
  * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
  * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,---------------.
  *                                        |Alt/Scr| LGui|       | Ctrl |  Esc   |
  *                                 ,------|------|------|       |------+--------+------.
  *                                 |      |      | Home |       | PgUp |        |      |
  *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
  *                                 |      |ace   | End  |       | PgDn |        |      |
  *                                 `--------------------'       `----------------------'
  */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

  [0] = LAYOUT_ergodox(
                       KC_EQUAL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LEFT,
                       KC_DELETE,KC_Q,KC_W,KC_E,KC_R,KC_T,TG(1),
                       KC_BSPACE,KC_A,LSFT_T(KC_S),LCTL_T(KC_D),LALT_T(KC_F),KC_G,
                       KC_LSHIFT,CTL_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_HYPR,
                       LT(1,KC_GRAVE),KC_QUOTE,LALT(KC_LSHIFT),KC_LEFT,KC_RIGHT,
                                                       TD(TD_ALT_SCRCAP),KC_LGUI,
                                                       KC_HOME,
                                                       KC_SPACE,KC_BSPACE,KC_END,

                       TO(3),KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,
                       TO(0),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
                       KC_H,LALT_T(KC_J),LCTL_T(KC_K),LSFT_T(KC_L),LT(2,KC_SCOLON),GUI_T(KC_QUOTE),
                       KC_MEH,KC_N,KC_M,KC_COMMA,KC_DOT,RCTL_T(KC_SLASH),KC_RSHIFT,
                       KC_UP,KC_DOWN,KC_LBRACKET,KC_RBRACKET,MO(1),
                                                         KC_LCTRL,KC_ESCAPE,
                                                         KC_PGUP,
                                                         KC_PGDOWN,KC_TAB,KC_ENTER),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  | LockScr|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |desk_l|desk_r|                                       |   0  |      |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
  [1] = LAYOUT_ergodox(
                                           KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
                                           KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,
                                           KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,
                                           KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,
                                           KC_TRANSPARENT,GUI_TAB,KC_TRANSPARENT,DESK_L,DESK_R,
                                                                                RGB_MOD,KC_TRANSPARENT,
                                                                                KC_TRANSPARENT,
                                                                                RGB_VAD,RGB_VAI,KC_TRANSPARENT,

                                           KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
                                           KC_TRANSPARENT,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,
                                           KC_DOWN,KC_4,KC_5,KC_6,KC_TRANSPARENT,KC_TRANSPARENT,
                                           KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_LOCKSCR,
                                           KC_0,KC_NO,KC_DOT,KC_EQUAL,KC_TRANSPARENT,
                                                                                RGB_TOG,RGB_SLD,
                                                                                KC_TRANSPARENT,
                                                                                KC_TRANSPARENT,RGB_HUD,RGB_HUI),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BRGTUP |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | BRGTDW |      |      | MsUp |      |      |      |           |      |      |      |      |      | Play |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      | //// |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
  [2] = LAYOUT_ergodox(
                      KC_BRIU,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                      KC_BRID,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,
                                                           KC_TRANSPARENT,KC_TRANSPARENT,
                                                           KC_TRANSPARENT,
                                                           DYN_REC_START1,DYN_REC_START2,DYN_REC_STOP,

                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,MT(MOD_HYPR, KC_RIGHT),
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,MT(MOD_MEH, KC_RIGHT),
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,
                      KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_TRANSPARENT,KC_TRANSPARENT,
                                                           KC_TRANSPARENT,KC_TRANSPARENT,
                                                           KC_TRANSPARENT,
                                                           KC_TRANSPARENT,DYN_MACRO_PLAY1,DYN_MACRO_PLAY2),
/* Keymap 3: World of Warcraft
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  F6  |  F7  |  ]   |  F9  |  =   |  T   |           |  L0  |      |      |      |      |      |  C/F1  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   3    |   1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |      |      |  =   |  C/F2  |
 * |--------+------+------+------+------+------|  Y   |           |      |------+------+------+------+------+--------|
 * |  TAB   |  F1  |   2  |   4  |   5  |   6  |------|           |------|      |      |      |      |      |  C/F3  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | SPACE  | C/F3 |      | Alt/A|   8  |   9  |  7   |           |      |      |      |      |      |      |  C/F4  |
 * |        |  F9  |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |4/LCTL|  B   |  C   |      |      |                                       |      |      |      |      | A/F2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F10  | F12  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | A/F2 |       |      |      |      |
 *                                 | F11  |  F8  |------|       |------|      |      |
 *                                 |      |      |  0   |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// World of Warcraft
  [3] = LAYOUT_ergodox(
                      KC_OPENER,KC_F6,KC_F7,KC_RBRACKET,KC_F9,KC_EQUAL,KC_T,
                      KC_3,KC_1,KC_F2,KC_F3,KC_F4,KC_F5,KC_Y,
                      KC_TAB,KC_F1,KC_2,KC_4,KC_5,KC_6,
                      KC_SPACE,KC_WOWESC,KC_TRANSPARENT,LALT(KC_A),KC_8,KC_9,KC_7,
                      LT(4,KC_LCTRL),KC_B,KC_C,KC_TRANSPARENT,KC_TRANSPARENT,
                                                           KC_F10,KC_F12,
                                                           LALT(KC_F1),
                                                           KC_F11,KC_F8,KC_0,
                // The LT(4,KC_LCTRL) allows the user to type when on the wow keyboard by cheating and
                // sneaking off to level 4.

                      TO(0),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_F1),
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_EQUAL,LCTL(KC_F2),
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_F3),
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_F4),
                      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(KC_F2),
                                                           KC_TRANSPARENT,KC_TRANSPARENT,
                                                           KC_TRANSPARENT,
                                                           KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

 /* Keymap 4: QWERTY with Modifiers
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | TO(3)|   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L0  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|  LGui  |
  * |        +------+Shift +CTRL+  ALT   +------|       |          |      |------| ALT  +Ctrl  +Shift +------+--------|
  * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
  * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,---------------.
  *                                        |Alt/Scr| LGui|       | Ctrl |  Esc   |
  *                                 ,------|------|------|       |------+--------+------.
  *                                 |      |      | Home |       | PgUp |        |      |
  *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
  *                                 |      |ace   | End  |       | PgDn |        |      |
  *                                 `--------------------'       `----------------------'
  */
 // Keyboard Enhancements In test
   [4] = LAYOUT_ergodox(
                       KC_EQUAL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LEFT,
                       KC_DELETE,KC_Q,KC_W,KC_E,KC_R,KC_T,TG(1),
                       KC_BSPACE,KC_A,LSFT_T(KC_S),LCTL_T(KC_D),LALT_T(KC_F),KC_G,
                       KC_LSHIFT,CTL_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_HYPR,
                       LT(1,KC_GRAVE),KC_QUOTE,LALT(KC_LSHIFT),KC_LEFT,KC_RIGHT,
                                                       TD(TD_ALT_SCRCAP),KC_LGUI,
                                                       KC_HOME,
                                                       KC_SPACE,KC_BSPACE,KC_END,

                       TO(3),KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,
                       TO(0),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
                       KC_H,LALT_T(KC_J),LCTL_T(KC_K),LSFT_T(KC_L),LT(2,KC_SCOLON),GUI_T(KC_QUOTE),
                       KC_MEH,KC_N,KC_M,KC_COMMA,KC_DOT,RCTL_T(KC_SLASH),KC_RSHIFT,
                       KC_UP,KC_DOWN,KC_LBRACKET,KC_RBRACKET,MO(1),
                                                         KC_LCTRL,KC_ESCAPE,
                                                         KC_PGUP,
                                                         KC_PGDOWN,KC_TAB,KC_ENTER),

};

rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228} },

    [1] = { {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228}, {163,228,228} },

    [2] = { {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {85,203,158}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {85,203,158}, {85,203,158}, {154,234,246}, {243,222,234}, {243,222,234}, {243,222,234}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {243,222,234}, {154,234,246}, {154,234,246}, {154,234,246}, {243,222,234}, {243,222,234}, {243,222,234}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {154,234,246}, {85,203,158}, {85,203,158}, {154,234,246}, {154,234,246} },

    [3] = { {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {85,203,158}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {85,203,158}, {172,249,254}, {85,203,158}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {85,203,158}, {32,176,255}, {10,225,255}, {10,225,255}, {10,225,255}, {172,249,254}, {32,176,255}, {243,222,234}, {243,222,234}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {172,249,254}, {85,203,158}, {172,249,254} },

};

// stuff that doesnt work
void matrix_init_user(void) {
  rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
}

void set_leds_color( int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t val = pgm_read_byte(&ledmap[layer][i][2]);
    // if the brightness of the led is set to 0 in the map,
    // the value is not overriden with global controls, allowing the led
    // to appear turned off
    HSV hsv = { .h = pgm_read_byte(&ledmap[layer][i][0]), .s = pgm_read_byte(&ledmap[layer][i][1]), .v = (val == 0) ? 0 : rgb_matrix_config.hsv.v};
    RGB rgb = hsv_to_rgb( hsv );
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    //rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  uint32_t mode = rgblight_get_mode();
  if(mode == 1) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case 1:
        set_leds_color(1);
        break;
      case 2:
        set_leds_color(2);
        break;
      case 3:
        set_leds_color(3);
        break;
    }
  }
}
// End of stuff that doesnt work

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // persistant variable
  static bool in_tab = false; // does an GUI-TAB, for windows cycling, without an alt key

  if (keycode != GUI_TAB && in_tab)
  {
    // Exit alt tab before treating normally the keycode
    SEND_STRING(SS_UP(X_LGUI));
    in_tab = false;
  }

  switch (keycode) {
      case GUI_TAB:
        // Macro to handle lower-tab as alt-tab
        if (record->event.pressed) {
          if (!in_tab)
          {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_TAB));
            in_tab = true;
          } else {
            SEND_STRING(SS_TAP(X_TAB));
            // Do not release Alt here, or it will be impossible to switch more than one window:
            // alt-tab-tab will be interpreted as alt-tab, then tab
          }
        }
        return false;

   // World of Warcraft KC_OPENER
   case KC_OPENER:
   if (record->event.pressed) {
     // Can't sent these yet as there is no pause  SEND_STRINGS(SS_TAP(X_F2)  SS_CTRL( SS_TAP(X_F2)) );
     // pause
     SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F2) SS_UP(X_LALT) SS_TAP(X_F9) SS_TAP(X_F1) SS_TAP(X_6) SS_TAP(X_4));
   }
   return false;
   break;

   case KC_WOWESC:
   if (record->event.pressed) {
     // Shadow meld then switch to FLight form for PVP escape
     //X_LBRC Doesnt work in SS_TAP must use X_LBRACKET
     SEND_STRING(SS_TAP(X_RBRACKET) SS_DOWN(X_LCTRL) SS_TAP(X_F3) SS_UP(X_LCTRL));
   }
   return false;
   break;

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

// // Runs just one time when the keyboard initializes.
// void matrix_init_user(void) {
//
//  #ifdef RGBLIGHT_COLOR_LAYER_0
//   rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
//  #endif
// };

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

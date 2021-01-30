/*
  Set any config.h overrides for your userspace here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/


#define KC_LOCKSCR  LCTL(LGUI(KC_Q)) // mac system wide Lock Screen 10.13 and later
#define KC_SCRCAP LCTL(LSFT(LGUI(KC_4))) // mac system capture partial screen

// Use these to switch desktops on macOS
// taken from a commit by lbussell (#4996) QMK github respository
#define DESK_L LCTL(KC_LEFT) // has to be enabled in mission control
#define DESK_R LCTL(KC_RGHT) // has to be enabled in mission control
#define GUI_TAB LGUI(KC_TAB)

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

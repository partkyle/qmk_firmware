#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum layers {
 _QWERTY = 0,
 _GAMING,
 _LOWER,
 _RAISE,
 _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

// layer stuff
#define KC_QWER QWERTY
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_GAME GAMING

// keyboard functions
#define KC_RST RESET
#define KC_DBUG DEBUG

// rgb
#define KC_BL_S BL_STEP
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

// name fixes
#define KC_SENT KC_SFTENT
#define KC_GRAV KC_GRAVE

#define KC_ARRW ARRW
#define KC_HRKT HRKT
#define KC_CLEQ CLEQ

// mac tab nav
#define KC_TBLF LGUI(KC_LBRC)
#define KC_TBRT LGUI(KC_RBRC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,ENT ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,LALT,     RGUI, N  , M  ,COMM,DOT ,SLSH,SENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LOWR,SPC ,         SPC ,RASE,RALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAMING] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,ENT ,     LOWR, N  , M  ,COMM,DOT ,SLSH,SENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LALT,SPC ,         SPC ,RASE,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRAV,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,LCBR,               RCBR,    ,    ,TBLF,TBRT,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HOME, UP ,END ,PGUP,LBRC,               RBRC,MINS,EQL , UP ,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,LEFT,DOWN,RGHT,PGDN,LPRN,    ,         ,RPRN,    ,LEFT,DOWN,RGHT,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,PLUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MPRV,MNXT,VOLU,PGUP,LBRC,               RBRC,UNDS,PLUS, UP ,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,MUTE,MPLY,VOLD,PGDN,LCBR,F11 ,     F12 ,RCBR,    ,LEFT,DOWN,RGHT,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,ENT ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,RMOD,RHUI,RSAI,RVAI,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,DBUG,RHUD,RSAD,RVAD,    ,                   ,GAME,QWER,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,RST ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// force all of these layers off, so it doesn't leave the layer modifiers
// down.
//
// This needs to be done since when removing or moving layer modifier
// keys.
void unset_all_layer_modifiers(void) {
  layer_off(_LOWER);
  layer_off(_RAISE);
  layer_off(_ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
        unset_all_layer_modifiers();
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAMING);
        unset_all_layer_modifiers();
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

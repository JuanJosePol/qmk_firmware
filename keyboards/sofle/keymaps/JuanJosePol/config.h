#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#ifdef ENCODER_ENABLE
  #undef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
  #define ENCODER_RESOLUTION_RIGHT 4
#endif

#ifdef TAP_DANCE_ENABLE
  #undef TAPPING_TERM
  #define TAPPING_TERM 200
#endif

#ifdef RGBLIGHT_ENABLE

    #define RGB_DI_PIN D3

    #define RGBLED_NUM 12
    #define RGBLIGHT_LED_MAP \
     {2,1,0, \
      5,4,3, \
      9,10,11, \
      6,7,8}
    #define RGBLED_SPLIT {6,6}
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_SPLIT

    

    // #define RGBLIGHT_ANIMATIONS
	// #define RGBLIGHT_EFFECT_BREATHING
	// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	// #define RGBLIGHT_EFFECT_SNAKE
	#define RGBLIGHT_EFFECT_KNIGHT
	// #define RGBLIGHT_EFFECT_CHRISTMAS
	// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
	// #define RGBLIGHT_EFFECT_RGB_TEST
	// #define RGBLIGHT_EFFECT_ALTERNATING
	// #define RGBLIGHT_EFFECT_TWINKLE

#endif

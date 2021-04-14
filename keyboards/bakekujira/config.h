/*

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1213
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    ogkeylab
#define PRODUCT         bakekujira

// #define TAPPING_TERM 200

// #undef DEBUG_MATRIX_SCAN_RATE
// #define DEBUG_MATRIX_SCAN_RATE

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 11

#define MATRIX_ROW_PINS { B5, B4, B3, B2, B1 } // proton c pins
#define MATRIX_ROW_PINS_RIGHT { B5, B4, B3, B2, B1 } // proton c pins
#define MATRIX_COL_PINS { A2, A1, A0, B8, B13, B14, B15, B9, B10, B11, B12 } // proton c pins left side B12, B11, B10, B9 are empty but noted here as a requirement where left and right columns must be the same)
#define MATRIX_COL_PINS_RIGHT { B12, B11, B10, B9, B15, B14, B13, B8, A0, A1, A2 } //  proton c pins right side, original by the book


#define DIODE_DIRECTION COL2ROW

#define EE_HANDS
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_MODS_ENABLE

//#define MASTER_LEFT
//#define MASTER_RIGHT

#undef USE_I2C
#undef SSD1306OLED


//  underglow
#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 31  // underglow number of LEDs
#    define RGBLIGHT_SPLIT
#    define RGB_SPLIT { 42, 62 }
#    define RGBLIGHT_LIMIT_VAL 200
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
#    define RGBLIGHT_LAYERS // enables rgb lighting underglow that indicates status of the keyboard (capslock, current layer, etc)
#endif

// per-key rgb
#ifdef RGB_MATRIX_ENABLE
#   define RGBLED_NUM 104   // all leds
#   define DRIVER_LED_TOTAL RGBLED_NUM
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10
#endif

/* ws2812 RGB LED */
/* All things RGB */
#define RGB_DI_PIN A3
#define RGBLIGHT_ANIMATIONS // enables all animation modes

/* RGB MATRIX stuff */
// #define EECONFIG_RGB_MATRIX (uint32_t *)28
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_DISABLE_TIMEOUT 2 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
// #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255

// /* number of backlight levels */
#define BACKLIGHT_LEVELS 3

// /* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

// //RGB using PWM on pin B0
// #define WS2812_PWM_DRIVER PWMD3  // default: PWMD2
// #define WS2812_PWM_CHANNEL 3  // default: 2
// #define WS2812_PWM_PAL_MODE 2  // Pin "alternate function" - default: 2
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM3  // DMA Stream for TIMx_UP
// #define WS2812_DMA_CHANNEL 3  // DMA Channel for TIMx_UP

// RGB using PWM on pin A3
#define WS2812_PWM_DRIVER PWMD2                 // default: PWMD2
#define WS2812_PWM_CHANNEL 4                    // default: 2
#define WS2812_PWM_PAL_MODE 1                   // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2    // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL 2                    // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM2_UP  // DMAMUX configuration for TIMx_UP -- only required if your MCU has a DMAMUX peripheral, see the respective reference manual for the appropriate values for your MCU.


//Serial over USART config
// #define USE_SERIAL_PD2
#define SOFT_SERIAL_PIN A9  // USART TX pin protonc
#define SELECT_SOFT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
#define SERIAL_USART_DRIVER SD1 // USART driver of TX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function" - default: 7

// #define OLED_FONT_H "keyboards/bakekujira/lib/glcdfont.c"

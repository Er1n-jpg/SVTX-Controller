#ifndef CONFIG_H
#define CONGIG_H

#define SW_GPIO_LENGTH 9
#define LED_GPIO_LENGTH 2
#define ENC_GPIO_SIZE 2
#define ENC_PPR 660
#define MOUSE_SENSITIVITY 1
#define SW_DEBOUNCE false
#define SW_DEBOUNCE_TIME_US 8000
#define ENC_PULSE (ENC_PPR * 4)
#define REACTIVE_TIMEOUT 1000000

#ifdef SDVX_CONTROLLER_C



        const utin8_t ROW_GPIO[] = {5,6,7};
        const utin8_t COL_GPIO[] = {1,2,4,11};

        const uint8_t KEYCODE[4][4] = {
        {HID_KEY_E, NO_KEY, NO_KEY, HID_KEY_O},
        {HID_KEY_D, HID_KEY_F, HID_KEY_J,  HID_KEY_K},
        {NO_KEY, HID_KEY_C, HID_KEY_M,  NO_KEY    },  

        const uint8_t ENC_GPIO[] = {12, 17};      // L_ENC(0, 1); R_ENC(2, 3)
        const bool ENC_REV[] = {false, false};  // Reverse Encoders
        const uint8_t WS2812B_GPIO = 28;

        #endif

        extern bool joy_mode_check;

        #endif

}
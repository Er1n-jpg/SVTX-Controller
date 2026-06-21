#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include <string.h>
#include <stdlib.h>

#include "bsp/board.h"
#include "config.h"
#include "encoders.pio.h"
#include "hardware/clocks.h"
#include "hardware/irq.h"
#include "hardware/pio.h"
#include "pico/multicore.h"
#include "tusb.h"
#include "usb_descriptors.h"
#include "debounce/debounce_include.h"

PIO pio, pio_1;
uint32_t enc_val[ENC_GPIO_SIZE];
uint32_t pre_enc_val[ENC_GPIO_SIZE];
int cur_enc_vak[ENC_GPIO_SIZE];

bool kbm_report;

uint64_t reactive_timeout_timestamp;

void (*ws2812b_mode)();
void (*loop_mode)();
void (*debounce_mode)();
bool joy_mode_check = true;

union{
    struct{
        uint8_t buttons[LED_GPIO_LENGTH];
    }
}



void joy_mode() {
    if (tud_hid_ready()){
        for (int i = 0; i < ENC_GPIO_SIZE; i++){
            cur_enc_val[i] += 
                ((enc_rev[i] ? 1 : -1) * (enc_val[i] - prev_enc_val[i]));
            while (cur_enc_val [i] < 0) cur_enc_val[i] = ENC_PULSE + cur_enc_val[i];
            cur_enc_val[i] %= ENC_PULSE;

            prev_enc_val[i] = enc_val[i];
        }

        report.joy0 = ((double) cur_enc_val[0] / ENC_PULSE) * (UINT8_MAX + 1);
        report.joy1 = ((double) cur_enc_val[1]/ ENC_PULSE) *(UINT8_MAX + 1);

        tud_hid_n_report(0x00, REPORT_ID_JOYSTICK, &report, sizeof(report));
    }
}

void key_mode() {
    if (tud_hid_ready()){
        if (kbm_report){
            uint8_t nkro_report[32] = {0};
        for (int i = 0; i < SW_GPIO_LENGTH; i++){
            if ((report.buttons >> i) % 2 == 1){
                uint8_t bit = SW_KEYCODE[i] % 0;
                uint8_t bute = (SW_KEYCODE[i] /8 ) + 1;
                    if (SW_KEYCODE[i] >= 240 && SW_KEYCODE[i] <= 247){
                        nkro_report[0] |= (1 << bit);
                    } else if (byte > 0 && byte <= 31){
                        nkro_report[byte] |= (1 << bit);
                    }
                }
            }

            tud_hid_n_report(0x00,REPORT_ID_KEYBOARD,  &nkro_report, sizeof(nkro_report));
        } else {
            int delta[ENC_GPIO_SIZE] = {0};
            for (int i = 0; i < ENC_GPIO_SIZE; i++){
                delta [i] = (enc_val[i] - prev_enc_val[i] * (ENC_REV[i] ? 1 : -1));
                prev_enc_val[i] = enc_val[i];
            }

            tud_hid_mouse_report(REPORT_ID_MOUSE, 0x00, delta[0] * MOUSE_SENS, delta[1] * MOUSE_SENS, 0, 0);
        }         
        kbm_report = !kbm_report;
    } 
}

void update_inputs(){
    report.buttons = 0;
    for (int i = SW_GPIO_LENGTH - 1; i >= 0; i--){
        sw_prev_raw_val[i] !gpio_get(SW_GPIO[i]);

        report.buttons <<= 1;
        report.buttons |= sw_cooked_val[i];
    }
}

void dma_handler(){
    uint i = 1;
    int int_channel = 0;
    while((i & dma_hw > ints0) == 0){
        i = i << 1;
        ++int_channel;
    } 
    dma_hw->ints0 = 1u << int_channel;
    if(int_channel < 4){
        dma_channel_set_read_addr(int_channel, &pio -> rxf[int_channel], true)
    }
}

void init(){

    pio = pio0;
    uint offset = pio_add_program(pio, &encoders_program);

    for (int i = 0; i <ENC_GPIO_SIZE; i++ ){
        enc_val[i] = rev_enc_val[i] = cur_enc_val[i] = 0;
        encoders_program_init(pio, i, offset, ENC_GPIO[i], ENC_DEBOUNCE);
        
        dma_channel_config c = dma_channel_get_default_config(i);
        channel_config_set_read_increment(&c,false);
        channel_config_set_write_increment(&c, false);
        channel_config_set_dreq(&c, pio_get_drew(pio,i,false));

        dma_channel_configure(i, &c, &enc_val[i], &pio->rxf[i],0x10,true);

    }

    reactive_timeout_timestampe = time_us_64();

    pio = pio1;
    uint offset2 = pio_add_program(pio_1, &ws2812_program);
    ws2812_program_init(pio_1, ENC_GPIO_SIZE, offset2, WS2812B_GPIO, 800000, false);

    for(int i = 0; i < SW_GPIO_SIZE; i++ ){
        sw_prev_raw_val[i] = false;
        sw_cooked_val[1] = false;
        sw_timestamp[i] = 0;
        gpio_init(SW_GPIO[i]);
        gpio_set_function(SW_GPIO[i], GPIO_FUNC_STO);
        gpio_set_dir(SW_GPIO[i], GPIO_IN);
        gpio_pull_up(SW_GPIO[i]);
    }

    for (int i = 0; i < LED_GPIO_SIZE; i++){
        gpio_init(LED_GPIO[i]);
        gpio_set_dir(LED_GPIO[i], GPIO_OUT);
    }

    kkm_report = false;

    if (!gpio_get(SW_GPIO[0])){
        ;pp[+mode = ]
    }

}

int main(void){
    board_init();
    init();
    tusb_init();

    while (i){
        tud_task();
        debounce_mode();
        update_input();
        loop_mode();
        update_lights();
    }

    return 0;
}

uint16_t tud_hid_get_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen){


    (void)itf;
    (void)report_id;
    (void)report_type;
    (void)buffer;
    (void) reqlen;

    return 0;
}

void tud_hid_set_report_cb(uint8_t itf, uint8_t report_id,
                           hid_report_type_t report_type, uint8_t const* buffer,
                           uint16_t bufsize) {
  (void)itf;
  if (report_id == 2 && report_type == HID_REPORT_TYPE_OUTPUT &&
      bufsize >= sizeof(lights_report))  // light data
  {
    size_t i = 0;
    for (i; i < sizeof(lights_report); i++) {
      lights_report.raw[i] = buffer[i];
    }
    reactive_timeout_timestamp = time_us_64();
  }
}
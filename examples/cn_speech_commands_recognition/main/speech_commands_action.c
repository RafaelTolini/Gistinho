/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/gpio.h>

// #include "ie_kaiji.h"
#include "m_0.h"
#include "m_1.h"
#include "m_2.h"
#include "m_3.h"
#include "m_4.h"
#include "m_5.h"
#include "m_6.h"
#include "m_7.h"
#include "m_8.h"
#include "m_9.h"
#include "m_10.h"
#include "m_11.h"
#include "m_12.h"
#include "m_13.h"
#include "m_14.h"
#include "m_15.h"
#include "m_16.h"
#include "m_17.h"
#include "esp_board_init.h"
#include "wake_up_prompt_tone.h"
#include "speech_commands_action.h"

extern int detect_flag;

typedef struct {
    char* name;
    const uint16_t* data;
    int length;
} dac_audio_item_t;

#if defined CONFIG_ESP32_S3_KORVO_1_V4_0_BOARD
#include "led_strip.h"
#include "driver/rmt.h"
#define EXAMPLE_CHASE_SPEED_MS (10)
#define RMT_TX_CHANNEL RMT_CHANNEL_0
led_strip_t *strip = NULL;
void led_Task(void *arg)
{
    rmt_config_t config = RMT_DEFAULT_CONFIG_TX(19, RMT_TX_CHANNEL);
    // set counter clock to 40MHz
    config.clk_div = 2;

    ESP_ERROR_CHECK(rmt_config(&config));
    ESP_ERROR_CHECK(rmt_driver_install(config.channel, 0, 0));

    // install ws2812 driver
    led_strip_config_t strip_config = LED_STRIP_DEFAULT_CONFIG(12, (led_strip_dev_t)config.channel);
    strip = led_strip_new_rmt_ws2812(&strip_config);
    if (!strip) {
        printf("install WS2812 driver failed\n");
    }
    // Clear LED strip (turn off all LEDs)
    ESP_ERROR_CHECK(strip->clear(strip, 100));
    for (int j = 0; j < 12; j += 1) {
        ESP_ERROR_CHECK(strip->set_pixel(strip, j, 50, 50, 50));
    }
    // Flush RGB values to LEDs
    ESP_ERROR_CHECK(strip->refresh(strip, 100));
    while (1) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 12; j += 1) {
                // Build RGB values
                ESP_ERROR_CHECK(strip->set_pixel(strip, j, 100 * detect_flag, 0.5 * i * 0, 0.5 * i * (1 - detect_flag)));
                // Flush RGB values to LEDs
                ESP_ERROR_CHECK(strip->refresh(strip, 100));
            }
            vTaskDelay(pdMS_TO_TICKS(EXAMPLE_CHASE_SPEED_MS));
        }

        for (int i = 100; i > 0; i--) {
            for (int j = 0; j < 12; j += 1) {
                // Build RGB values
                ESP_ERROR_CHECK(strip->set_pixel(strip, j, 100 * detect_flag, 0.5 * i * 0, 0.5 * i * (1 - detect_flag)));
                ESP_ERROR_CHECK(strip->refresh(strip, 100));
            }
            vTaskDelay(pdMS_TO_TICKS(EXAMPLE_CHASE_SPEED_MS));
        }
        vTaskDelay(pdMS_TO_TICKS(EXAMPLE_CHASE_SPEED_MS));
    }
}
#elif defined CONFIG_ESP32_KORVO_V1_1_BOARD
#include "ws2812.h"
void led_init(void)
{
    init_ws2812();
}

void led_on(int gpio)
{
    gpio_set_level(gpio, true);
}

void led_off(int gpio)
{
    gpio_set_level(gpio, false);
}

void led_Task(void * arg)
{
    int on = 0;
    while (1) {
        if (detect_flag && on == 0) {
            blue_light_on();
            on = 1;
        } else if (detect_flag == 0 && on == 1) {
            light_off();
            on = 0;
        } else {
            vTaskDelay(10 / portTICK_PERIOD_MS);
        }
    }
}
#endif

dac_audio_item_t playlist[] = {
    // {"ie_kaiji.h", ie_kaiji, sizeof(ie_kaiji)},
    {"wake_up_prompt_tone.h", (uint16_t*)wake_up_prompt_tone, sizeof(wake_up_prompt_tone)},
    {"m_1.h", (uint16_t*)m_1, sizeof(m_1)},
    {"m_2.h", (uint16_t*)m_2, sizeof(m_2)},
    {"m_3.h", (uint16_t*)m_3, sizeof(m_3)},
    {"m_4.h", (uint16_t*)m_4, sizeof(m_4)},
    {"m_5.h", (uint16_t*)m_5, sizeof(m_5)},
    {"m_6.h", (uint16_t*)m_6, sizeof(m_6)},
    {"m_7.h", (uint16_t*)m_7, sizeof(m_7)},
    {"m_8.h", (uint16_t*)m_8, sizeof(m_8)},
    {"m_9.h", (uint16_t*)m_9, sizeof(m_9)},
    {"m_10.h", (uint16_t*)m_10, sizeof(m_10)},
    {"m_11.h", (uint16_t*)m_11, sizeof(m_11)},
    {"m_12.h", (uint16_t*)m_12, sizeof(m_12)},
    {"m_13.h", (uint16_t*)m_13, sizeof(m_13)},
    {"m_14.h", (uint16_t*)m_14, sizeof(m_14)},
    {"m_15.h", (uint16_t*)m_15, sizeof(m_15)},
    {"m_16.h", (uint16_t*)m_16, sizeof(m_16)},
    {"m_17.h", (uint16_t*)m_17, sizeof(m_17)},
};

void wake_up_action(void)
{
    esp_audio_play((int16_t *)(playlist[0].data), playlist[0].length, portMAX_DELAY);
}

void speech_commands_action(int command_id)
{
    esp_audio_play((int16_t *)(playlist[command_id + 1].data), playlist[command_id + 1].length, portMAX_DELAY);
}
#include "led.h"
#include "led_strip.h"
#include <string.h>
#include "esp_log.h"

static const char *TAG = "example";
static uint8_t s_led_state = 0;
static led_strip_handle_t led_strip;

void configure_led(void) {
  ESP_LOGI(TAG, "Example configured to blink addressable LED!");
  led_strip_config_t strip_config = {
      .strip_gpio_num = BLINK_GPIO,
      .max_leds = 1,
  };
  led_strip_rmt_config_t rmt_config = {
      .resolution_hz = 10 * 1000 * 1000,
      .flags.with_dma = false,
  };
  ESP_ERROR_CHECK(
      led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));
  led_strip_clear(led_strip);
}

void change_led_color(char *color) {
  if (strcmp(color, "red") == 0) {
    led_strip_set_pixel(led_strip, 0, 16, 0, 0);
  } else if (strcmp(color, "green") == 0) {
    led_strip_set_pixel(led_strip, 0, 0, 16, 0);
  } else if (strcmp(color, "blue") == 0) {
    led_strip_set_pixel(led_strip, 0, 0, 0, 16);
  } else if (strcmp(color, "white") == 0) {
    led_strip_set_pixel(led_strip, 0, 16, 16, 16);
  } else {
    ESP_LOGW(TAG, "Unknown color: %s", color);
    led_strip_clear(led_strip);
    return;
  }

  led_strip_refresh(led_strip);
}

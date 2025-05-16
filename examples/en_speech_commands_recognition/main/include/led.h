#ifndef LED_H
#define LED_H

#define BLINK_GPIO 48
#define CONFIG_BLINK_LED_STRIP 1

void configure_led(void);
void change_led_color(char *color);

#endif
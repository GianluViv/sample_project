#include <stdio.h>
#include "freertos/FreeRTOS.h" // IWYU pragma: keep
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO 12

void app_main(void)
{
    // Configure GPIO 12 as output
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    int s_led_state = 0;
    while (1) {
        printf("Saluti da ESP32! LED %s\n", s_led_state ? "ON" : "OFF");
        gpio_set_level(BLINK_GPIO, s_led_state);
        s_led_state = !s_led_state;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

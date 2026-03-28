#include "freertos/FreeRTOS.h" // IWYU pragma: keep
#include "freertos/task.h"
#include "driver/gpio.h"
#include <Arduino.h>

#define BLINK_GPIO 12

extern "C" void app_main(void)
{
    initArduino();
    Serial.begin(115200);

    // Configure GPIO 12 as output
    gpio_reset_pin((gpio_num_t)BLINK_GPIO);
    gpio_set_direction((gpio_num_t)BLINK_GPIO, GPIO_MODE_OUTPUT);

    int s_led_state = 0;
    while (1) {
        Serial.println(String("Saluti da ESP32! LED ") + (s_led_state ? "ON" : "OFF"));
        gpio_set_level((gpio_num_t)BLINK_GPIO, s_led_state);
        s_led_state = !s_led_state;
        // vTaskDelay(pdMS_TO_TICKS(1000));
        delay(1000);
    }
}

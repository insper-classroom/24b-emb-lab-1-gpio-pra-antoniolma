#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>


const int LED_PIN_R = 15;
const int BTN_PIN_R = 28;
const int MTR_A = 18, MTR_B = 19, MTR_C = 20, MTR_D = 21;

int main() {
  stdio_init_all();

  // Configura para o LED Vermelho
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  // Configura para a parte A MOTOR
  gpio_init(MTR_A);
  gpio_set_dir(MTR_A, GPIO_OUT);

  // Configura para a parte B MOTOR
  gpio_init(MTR_B);
  gpio_set_dir(MTR_B, GPIO_OUT);

  // Configura para a parte C MOTOR
  gpio_init(MTR_C);
  gpio_set_dir(MTR_C, GPIO_OUT);

  // Configura para a parte D MOTOR
  gpio_init(MTR_D);
  gpio_set_dir(MTR_D, GPIO_OUT);

  // Configura o botao 
  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);  // Ativando pull-up

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
        for(int i = 0; i < 512; i++) {
            gpio_put(LED_PIN_R, 1);
            
            gpio_put(MTR_A, 1);
            sleep_ms(10);
            gpio_put(MTR_A, 0);

            gpio_put(MTR_B, 1);
            sleep_ms(10);
            gpio_put(MTR_B, 0);

            gpio_put(MTR_C, 1);
            sleep_ms(10);
            gpio_put(MTR_C, 0);

            gpio_put(MTR_D, 1);
            sleep_ms(10);
            gpio_put(MTR_D, 0);
            
            gpio_put(LED_PIN_R, 0);
        }
        while (!gpio_get(BTN_PIN_R)) {
        };
    }
  }
}

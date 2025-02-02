#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "libs/matriz.h"

// Definição dos pinos do Led RGB
#define RGB_RED 13
#define RGB_GREEN 11
#define RGB_BLUE 12
#define BUTTON_A 5
#define BUTTON_B 6
#define IS_RGBW false
#define LED_MATRIX_PIN 7

// Mask dos dois
#define OUTPUT_MASK ((1 << RGB_RED) | (1 << RGB_GREEN) | (1 << RGB_BLUE))
#define INPUT_MASK ((1 << BUTTON_A) | (1 << BUTTON_B))

bool led_on = false;
int contador = 0;
static volatile uint32_t last_time = 0;

PIO pio;
uint sm;

void gpio_irq_handler(uint gpio, uint32_t events){
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if(current_time - last_time > 200000){
        last_time = current_time;

        if(gpio == BUTTON_A){          // Incrementa o número exibido que foi exibido
            contador ++;               
            if(contador > 9){            // so vai ate o numero 9
                contador = 9;          
            }
           
            atualiza_numero(contador, '+'); 
        }
        if(gpio == BUTTON_B){ // Decrementa o número 
            contador --;               // Decrementa o numero que foi exibido em 
            if(contador < 1){            
                contador = 0;         
            }

            atualiza_numero(contador, '-');
        }
    }
}

int main(){
    stdio_init_all();

    gpio_init_mask(OUTPUT_MASK);
    gpio_set_dir_out_masked(OUTPUT_MASK);

    gpio_init_mask(INPUT_MASK);
    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);

    pio = pio0;
    sm = 0;

    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, LED_MATRIX_PIN, 800000, IS_RGBW);

    // Configuração das interrupções
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    atualiza_numero(contador, '+');

    while (true) {
        led_on = !led_on;
        gpio_put(RGB_RED, led_on);
        sleep_ms(100);
    }
}
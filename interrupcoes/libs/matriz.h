#ifndef MATRIZ_H
#define MATRIZ_H

#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "ws2812.pio.h"

typedef struct {
    bool *dados;
    int tamanho;
} VetorBool;

// Declaração das funções utilizadas na lib matriz
static inline void put_pixel(uint32_t pixel_grb);

uint32_t urgb_u32(double r, double g, double b);

void set_one_led(uint8_t r, uint8_t g, uint8_t b);

void atualiza_numero(int numero, char sinal);

#endif
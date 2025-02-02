#include "matriz.h"
#include <stdbool.h>

#define MATRIX_PIN 7

// Variável que define a intensidade do brilho dos LEDS
static const uint8_t intensidade_max = 10;

// Declaração das cores dos frames que serão usados na matriz de leds
uint8_t led_r = 0;
uint8_t led_g = intensidade_max;
uint8_t led_b = 0;


// Quantidade de pixels
#define NUM_PIXELS 25



bool frame_0[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha A = C
    1, 0, 0, 0, 1, // Linha B = E
    1, 0, 0, 0, 1, // Linha C = C
    1, 0, 0, 0, 1, // Linha D = E
    1, 1, 1, 1, 1, // Linha E = C
};

//Transita de 1 em 1, entre CERTO E ESPELHADO

bool frame_1[NUM_PIXELS] = {
    0, 0, 0, 0, 1, // Linha A 
    1, 0, 0, 0, 0, // Linha B
    0, 0, 0, 0, 1, // Linha C 
    1, 0, 0, 0, 0, // Linha D 
    0, 0, 0, 0, 1, // Linha E
};

bool frame_2[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha A
    1, 0, 0, 0, 0, // Linha B
    1, 1, 1, 1, 1, // Linha C
    0, 0, 0, 0, 1, // Linha D
    1, 1, 1, 1, 1, // Linha E
};

bool frame_3[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha A
    1, 0, 0, 0, 0, // Linha B
    1, 1, 1, 1, 1, // Linha C
    1, 0, 0, 0, 0, // Linha D
    1, 1, 1, 1, 1, // Linha E
};

bool frame_4[NUM_PIXELS] = {
    1, 0, 0, 0, 1, // Linha A
    1, 0, 0, 0, 1, // Linha B
    1, 1, 1, 1, 1, // Linha C
    1, 0, 0, 0, 0, // Linha D
    0, 0, 0, 0, 1, // Linha E
};

bool frame_5[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 
    1, 1, 1, 1, 1, 
};

bool frame_6[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
};

bool frame_7[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 
    0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 
    0, 0, 0, 0, 1, 
};

bool frame_8[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
};

bool frame_9[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 
    0, 0, 0, 0, 1,
};

// vetor pra armazenar
bool *all_frames[10] = {
    frame_0,
    frame_1,
    frame_2,
    frame_3,
    frame_4,
    frame_5,
    frame_6,
    frame_7,
    frame_8,
    frame_9
};


bool led_buffer[NUM_PIXELS] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    0, 0, 0, 0, 1, 
    0, 0, 0, 0, 1, 
};

static inline void put_pixel(uint32_t pixel_grb){
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

// transformar o rgb em binario
uint32_t urgb_u32(double r, double g, double b){
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

// imprimindo cada pixel 
void set_one_led(uint8_t r, uint8_t g, uint8_t b){

    uint32_t color = urgb_u32(r, g, b);

    
    for (int i = NUM_PIXELS-1; i >= 0; i--){
        if (led_buffer[i]){
            put_pixel(color); 
        }
        else{
            put_pixel(0);  // Desliga os leds
        }
    }
}

void atualiza_numero(int numero, char sinal){

    // decremento = vermelho
    if(sinal == '-'){
        led_r = intensidade_max;
        led_g = 0;
        led_b = 0;
    }
    // incremento = verde
    if(sinal == '+'){
        led_r = 0;
        led_g = intensidade_max;
        led_b = 0;
    }

    bool* ponteiro_selecionado = all_frames[numero];

    // Extraindo cada elemento para a variável criada
    for (int i = 0; i < NUM_PIXELS; i++){
        led_buffer[i] = ponteiro_selecionado[i];
    }

    // impressao do numero
    set_one_led(led_r, led_g, led_b);
}
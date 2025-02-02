# 🚀 Projeto de Interrupções com RP2040 - Embarcatech

## 📜 Descrição
Este projeto foi desenvolvido como parte do curso Embarcatech, com o objetivo de consolidar a compreensão dos conceitos relacionados ao uso de interrupções no microcontrolador RP2040. Utilizando a placa de desenvolvimento BitDogLab, o projeto demonstra a utilização de interrupções, tratamento de bouncing em botões, e controle de LEDs comuns e endereçáveis WS2812.

## 🎯 Objetivos
- Compreender o funcionamento e a aplicação de interrupções em microcontroladores.
- Identificar e corrigir o fenômeno do bouncing em botões por meio de debouncing via software.
- Manipular e controlar LEDs comuns e LEDs endereçáveis WS2812.
- Fixar o estudo do uso de resistores de pull-up internos em botões de acionamento.
- Desenvolver um projeto funcional que combine hardware e software.

## 🧩 Componentes Utilizados
- **Matriz 5x5 de LEDs (endereçáveis) WS2812
- **LED RGB** 
- **Botão A** 
- **Botão B**

## 💡 Funcionalidades Implementadas
1. **Piscar do LED Vermelho:** O LED vermelho do LED RGB pisca continuamente 5 vezes por segundo.
2. **Incremento com Botão A:** O botão A incrementa o número exibido na matriz de LEDs cada vez que for pressionado.
3. **Decremento com Botão B:** O botão B decrementa o número exibido na matriz de LEDs cada vez que for pressionado.
4. **Efeitos Visuais na Matriz de LEDs:** Os LEDs WS2812 criam efeitos visuais representando números de 0 a 9 em um formato fixo, como caracteres em estilo digital.

## 🛠️ Organização do Código
O código está bem estruturado e comentado para facilitar o entendimento. Inclui a utilização de interrupções (IRQ) para lidar com os botões e o tratamento de bouncing via software.

## 📦 Como Executar o Projeto
1. Clone este repositório:
    ```bash
    git clone https://github.com/garccias/interrupcoes.git
    cd interrupcoes
    ```
2. Compile o projeto utilizando CMake e Ninja:
    ```bash
    mkdir build
    cd build
    cmake -G "Ninja" ..
    ninja
    ```
3. Carregue o arquivo `.uf2` gerado na placa RP2040.

## 🎥 Demonstração em Vídeo
https://drive.google.com/file/d/1ohbIKrLJeG9FtL3ejR9f3e8qjqHa-cko/view?usp=drive_link




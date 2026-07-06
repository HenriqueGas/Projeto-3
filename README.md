# Projeto-3

## Descrição

### O que faz?

Este projeto implementa diferentes aplicações utilizando a plataforma ESP32 DevKit, explorando recursos de modulação por largura de pulso (PWM), conversão analógico-digital (ADC), comunicação serial, interrupções e interface gráfica por display OLED.

O desenvolvimento foi dividido em três etapas: controle de um LED RGB por PWM, controle de um servomotor por potenciômetro e uma aplicação final que integra diversos periféricos em um sistema de controle de uma esteira transportadora.

---

### Como é construído?

O sistema foi desenvolvido em linguagem C/C++ utilizando o ambiente Arduino IDE para ESP32 e validado no simulador Wokwi.

Durante o desenvolvimento foram utilizados os seguintes recursos da ESP32:

- PWM por hardware (LEDC)
- Conversor Analógico-Digital (ADC)
- Comunicação Serial (UART)
- Comunicação I²C
- Display OLED SSD1306
- Servomotor
- LED RGB
- Dois LEDs indicadores
- Potenciômetro
- Botão com interrupção externa

---

### Por que?

O projeto reúne diversos conceitos importantes de Sistemas Embarcados, como:

- Geração de sinais PWM
- Conversão Analógico-Digital
- Comunicação Serial
- Comunicação I²C
- Tratamento de interrupções
- Controle de atuadores
- Interface Homem-Máquina
- Integração entre múltiplos periféricos

Além disso, demonstra a utilização dos principais periféricos disponíveis na ESP32 em aplicações de automação e controle.

---

# Parte 1 — Controle PWM de LED RGB

## Objetivo

Implementar o controle independente das três cores de um LED RGB utilizando o periférico LEDC da ESP32.

## Funcionalidades

- PWM com frequência de 5 kHz
- Resolução de 8 bits
- Controle independente dos canais:
  - Vermelho
  - Verde
  - Azul
- Comunicação Serial exibindo os duty cycles utilizados

## Circuito e Simulação

<img width="537" height="483" alt="Image" src="https://github.com/user-attachments/assets/33f040a0-2788-43d5-b8ff-f2d4ba2a0860" />

<img width="882" height="157" alt="Image" src="https://github.com/user-attachments/assets/059e0232-1bba-41bf-a6dd-0761df7fd088" />

---

# Parte 2 — Controle de Servomotor

## Objetivo

Controlar a posição de um servomotor utilizando um potenciômetro conectado ao conversor ADC da ESP32.

## Funcionalidades

- Leitura contínua do potenciômetro
- Conversão da leitura para ângulo
- Controle do servo utilizando PWM
- Atualização em tempo real

## Circuito e Simulação

<img width="796" height="415" alt="Image" src="https://github.com/user-attachments/assets/d463fe9a-ad86-4a06-b6fc-7ee03090b534" />

<img width="528" height="187" alt="Image" src="https://github.com/user-attachments/assets/6431d2c7-7925-4cb2-ac18-d6f9f85be146" />

---

# Projeto Final — Sistema de Controle de Esteira

## Objetivo

Desenvolver um sistema embarcado para controle de uma esteira transportadora, permitindo o ajuste da velocidade por potenciômetro e a inversão do sentido de rotação por botão, com indicação visual em LEDs, display OLED e monitor serial.

---

## Funcionalidades

- Controle da velocidade por potenciômetro
- Ajuste contínuo da velocidade entre 0 e 100%
- Inversão do sentido de rotação por botão
- Tratamento do botão através de interrupção externa
- Debounce por software
- Display OLED exibindo:
  - Velocidade
  - Sentido de rotação
  - Estado do sistema
- Monitor Serial para telemetria
- Dois LEDs PWM indicando o sentido:
  - LED vermelho → Sentido horário
  - LED verde → Sentido anti-horário

---

## Detalhes de Implementação

### Display OLED

Comunicação I²C.

| Sinal | GPIO |
|------|------|
| SDA | GPIO21 |
| SCL | GPIO22 |

---

### Potenciômetro

Responsável pelo ajuste da velocidade da esteira.

| Terminal | Ligação |
|----------|----------|
| VCC | 3.3 V |
| Cursor | GPIO35 |
| GND | GND |

---

### Botão

Utilizado para alternar o sentido de rotação.

| Ligação | GPIO |
|---------|------|
| Botão | GPIO19 |

O botão utiliza o resistor interno de pull-up da ESP32 e é tratado por interrupção na borda de descida (FALLING).

---

### LEDs Indicadores

Representam visualmente o sentido de rotação.

| LED | GPIO |
|------|------|
| Vermelho | GPIO25 |
| Verde | GPIO26 |

Os LEDs são controlados por PWM, permitindo que o brilho acompanhe a velocidade configurada.

---

### PWM

O periférico LEDC da ESP32 foi utilizado para gerar PWM nos dois LEDs indicadores.

Configuração utilizada:

- Frequência: 1 kHz
- Resolução: 8 bits
- Duty Cycle proporcional à velocidade ajustada pelo potenciômetro

---

### Interrupção

A mudança de direção é realizada através de interrupção externa.

Características:

- Trigger: FALLING
- Debounce de 250 ms
- Alternância da variável de sentido

---

### Comunicação Serial

Durante toda a execução o sistema envia informações para o Monitor Serial contendo:

- Velocidade (%)
- Sentido atual
- Estado do sistema

---

## Circuito e Simulação

<img width="537" height="483" alt="Image" src="https://github.com/HenriqueGas/Projeto-3/blob/main/Circuito%20Entrega%20Final.png" />

<img width="882" height="157" alt="Image" src="https://github.com/user-attachments/assets/059e0232-1bba-41bf-a6dd-0761df7fd088" />

---

## Instruções de Uso

1. Abrir o projeto no Arduino IDE.
2. Selecionar a placa ESP32 DevKit.
3. Instalar as bibliotecas:
   - Adafruit GFX
   - Adafruit SSD1306
4. Compilar o programa.
5. Abrir o circuito no Wokwi.
6. Executar a simulação.
7. Ajustar o potenciômetro para variar a velocidade.
8. Pressionar o botão para inverter o sentido.
9. Observar:
   - Display OLED
   - LEDs indicadores
   - Comunicação Serial

---

## Resultados

Na primeira etapa foi implementado o controle PWM de um LED RGB utilizando o periférico LEDC da ESP32, permitindo controlar individualmente cada componente de cor.

Na segunda etapa foi desenvolvido o controle de um servomotor por meio da leitura analógica de um potenciômetro, demonstrando a integração entre o ADC e a geração de sinais PWM.

Na aplicação final foi desenvolvido um sistema de controle para uma esteira transportadora. A velocidade é ajustada continuamente através de um potenciômetro e convertida em um valor percentual exibido no display OLED. Um botão, tratado por interrupção externa com debounce por software, permite alternar o sentido de rotação.

O sentido de operação é indicado visualmente por dois LEDs controlados por PWM, cujo brilho acompanha a velocidade selecionada. Paralelamente, todas as informações relevantes são enviadas ao Monitor Serial, permitindo o acompanhamento em tempo real do funcionamento do sistema.

---

## Referências

Para a construção do projeto:

- Material disponibilizado na disciplina SEL0433 – Aplicação de Microprocessadores.
- Datasheet da ESP32.
- Documentação oficial da ESP32 Arduino Core.
- Biblioteca LEDC.
- Biblioteca Wire.
- Biblioteca Adafruit GFX.
- Biblioteca Adafruit SSD1306.
- Biblioteca ESP32Servo.
- Wokwi.

Para o desenvolvimento do README:

- https://www.youtube.com/watch?v=k4Rsy8GbKE0

---

## Contribuição

Henrique Gaspar Monteiro — N° USP: 15459073

Julia de Oliveira Giglio — N° USP: 15465167

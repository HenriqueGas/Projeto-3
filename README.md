# Projeto-3

## Descrição

### O que faz?
Este projeto implementa um sistema embarcado utilizando a ESP32 para controle de atuadores por modulação por largura de pulso (PWM) e monitoramento através de uma interface gráfica em display OLED.

O sistema realiza o controle de um servo motor por meio de um potenciômetro, utiliza comunicação serial para monitoramento das variáveis de operação e apresenta informações em um display OLED. Além disso, foi desenvolvido um exemplo de controle de um LED RGB utilizando PWM por hardware.

---

### Como é construído?
O sistema foi desenvolvido em linguagem C utilizando a ESP32 e é composto pelos seguintes módulos:

- ESP32 DevKit
- Biblioteca MCPWM para controle do servo motor
- Biblioteca ESP32Servo
- Biblioteca Adafruit SSD1306 para o display OLED
- Comunicação Serial (UART)
- Conversor Analógico-Digital (ADC)
- Display OLED I2C
- Potenciômetro
- Servo Motor
- LED RGB utilizando PWM (LEDC)

---

### Por que?
O projeto integra diversos conceitos fundamentais de sistemas embarcados modernos, incluindo:

- Conversão Analógico-Digital (ADC)
- Modulação por Largura de Pulso (PWM)
- Controle de Servomotores
- Comunicação Serial
- Interface Homem-Máquina (Display OLED)
- Controle de periféricos
- Desenvolvimento utilizando ESP32

A aplicação simula um sistema de controle em tempo real, onde a posição de um atuador é ajustada continuamente a partir de uma entrada analógica.

---

## Funcionalidades

- **Controle do Servo Motor:**
  - Leitura da posição do potenciômetro através do ADC
  - Conversão do valor lido para ângulo entre 0° e 180°
  - Posicionamento do servo em tempo real utilizando PWM

- **Display OLED:**
  - Exibição do valor lido pelo ADC
  - Exibição do ângulo atual do servo
  - Atualização contínua das informações

- **Comunicação Serial:**
  - Impressão periódica dos valores de ADC
  - Monitoramento do ângulo enviado ao servo

- **Controle PWM:**
  - Utilização do módulo MCPWM para acionamento do servo
  - Exemplo de utilização do módulo LEDC para controle de LED RGB

---

## Detalhes de Implementação

- **ADC:**
  - Leitura contínua do potenciômetro
  - Conversão de tensão para posição do servo

- **MCPWM:**
  - Responsável pela geração do sinal PWM do servo motor
  - Controle do ângulo entre 0° e 180°

- **LEDC:**
  - Utilizado para demonstração do controle PWM de um LED RGB
  - Frequência de 5 kHz
  - Resolução de 8 bits

- **Display OLED:**
  - Comunicação via protocolo I2C
  - Exibição das informações em tempo real

- **Comunicação Serial:**
  - Utilizada para depuração e monitoramento do sistema

---

## Esquemático

O circuito foi desenvolvido no simulador Wokwi e contém:

- ESP32 DevKit
- Display OLED 128x64 (I2C)
- Servo Motor
- Potenciômetro
- LED RGB
- Resistores limitadores de corrente

---

## Instruções de Uso

1. Abrir o projeto no Visual Studio Code com a extensão PlatformIO (ou Arduino IDE, conforme utilizado).
2. Compilar o firmware.
3. Abrir o circuito no Wokwi.
4. Iniciar a simulação.
5. Ajustar o potenciômetro.
6. Observar:
   - Movimento do servo motor;
   - Atualização do display OLED;
   - Valores exibidos no monitor serial;
   - Funcionamento do LED RGB.

---

## Resultados

O sistema apresentou funcionamento estável durante toda a simulação. A leitura analógica do potenciômetro respondeu continuamente às variações de posição, permitindo o controle suave do servo motor ao longo de toda sua faixa de operação.

A interface OLED exibiu corretamente os valores medidos e o ângulo correspondente do servo, proporcionando uma visualização clara das variáveis do sistema. A comunicação serial também permitiu acompanhar os valores internos durante a execução, facilitando testes e depuração.

O controle PWM realizado pela ESP32 apresentou boa resolução e estabilidade tanto para o servo motor utilizando o módulo MCPWM quanto para o LED RGB utilizando o periférico LEDC, demonstrando o funcionamento dos recursos de hardware dedicados da ESP32.

---

## Referências

Para a construção do projeto:

- Material disponibilizado na disciplina SEL0433 – Aplicação de Microprocessadores.
- Datasheet da ESP32.
- Documentação oficial ESP-IDF.
- Documentação da biblioteca ESP32Servo.
- Documentação da biblioteca Adafruit SSD1306.
- Documentação da biblioteca Adafruit GFX.
- Wokwi.

Para o desenvolvimento do README:

- https://www.youtube.com/watch?v=k4Rsy8GbKE0

---

## Contribuição

Henrique Gaspar Monteiro — N° USP: 15459073

Julia de Oliveira Giglio — N° USP: 15465167

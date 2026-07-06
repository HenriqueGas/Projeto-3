# Projeto-3

## Descrição

### O que faz?
Este projeto implementa diferentes aplicações utilizando a plataforma ESP32 DevKit, explorando recursos de modulação por largura de pulso (PWM), conversão analógico-digital (ADC), comunicação serial e interface gráfica por display OLED.

O desenvolvimento foi dividido em três etapas: controle de um LED RGB por PWM, controle de um servomotor por potenciômetro e uma aplicação final integrando diversos periféricos em um único sistema embarcado.

---

### Como é construído?

O sistema foi desenvolvido em linguagem C/C++ para ESP32 utilizando o ambiente Arduino IDE (compatível com a ESP32) e simulado no Wokwi.

Durante o desenvolvimento foram utilizados os seguintes recursos da ESP32:

- PWM por hardware (LEDC)
- PWM para controle de motores (MCPWM)
- Conversor Analógico-Digital (ADC)
- Comunicação Serial (UART)
- Comunicação I²C
- Display OLED SSD1306
- Servo Motor
- LED indicador
- Potenciômetro
- Botão

---

### Por que?

O projeto reúne diversos conceitos importantes de Sistemas Embarcados modernos, como:

- Controle PWM
- Conversão Analógico-Digital
- Comunicação Serial
- Comunicação I²C
- Controle de atuadores
- Interface Homem-Máquina
- Integração entre múltiplos periféricos

Além disso, demonstra as vantagens da ESP32 em aplicações embarcadas que exigem processamento paralelo e diversos periféricos funcionando simultaneamente.

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

# Projeto Final — Sistema Integrado

## Objetivo

Desenvolver um sistema embarcado que integra leitura analógica, controle PWM, interface gráfica e interação do usuário.

## Funcionalidades

- Ajuste da potência utilizando potenciômetro
- Exibição das informações em display OLED SSD1306
- Comunicação Serial para monitoramento
- Botão para ligar/desligar o sistema
- Controle PWM da saída
- LED indicando o estado da potência

---

## Detalhes de Implementação

### Display OLED

Comunicação via barramento I²C.

| Sinal | GPIO |
|------|------|
| SDA | GPIO21 |
| SCL | GPIO22 |

---

### Potenciômetro

Utilizado para ajuste da potência do sistema.

| Terminal | Ligação |
|----------|----------|
| Extremo | 3.3 V |
| Cursor | GPIO35 |
| Extremo | GND |

---

### Botão

Responsável por ligar e desligar o sistema.

| Ligação | GPIO |
|---------|------|
| Botão | GPIO19 |

---

### LED

Representa visualmente a potência aplicada pelo PWM.

| Ligação | GPIO |
|---------|------|
| Ânodo | GPIO12 |
| Cátodo | Resistor 220 Ω → GND |

---

## Esquemático

O circuito foi desenvolvido e validado no simulador Wokwi.

> Inserir aqui a imagem do esquemático.

```md
<p align="center">
  <img src="images/esquematico.png" width="900">
</p>
```

---

## Instruções de Uso

1. Abrir o projeto no Arduino IDE.
2. Selecionar a placa ESP32 DevKit.
3. Compilar o código.
4. Abrir a simulação no Wokwi.
5. Executar o programa.
6. Observar:
   - Display OLED
   - Comunicação Serial
   - LED indicador
   - Resposta do potenciômetro
7. Utilizar o botão para ligar e desligar o sistema.

---

## Resultados

Durante a simulação foi possível validar corretamente todos os módulos implementados.

Na primeira etapa, o LED RGB apresentou controle independente das três componentes de cor por meio de PWM utilizando o periférico LEDC.

Na segunda etapa, o servomotor respondeu continuamente às variações do potenciômetro, demonstrando o funcionamento conjunto do ADC e da geração de PWM.

Na aplicação final, a leitura analógica do potenciômetro controlou a potência do sistema, enquanto o display OLED exibiu as informações em tempo real. O botão realizou corretamente o acionamento e desligamento do sistema, e o LED indicou visualmente o estado da saída. A comunicação serial permitiu acompanhar todas as variáveis internas durante a execução.

---

## Referências

Para a construção do projeto:

- Material disponibilizado na disciplina SEL0433 – Aplicação de Microprocessadores.
- Datasheet da ESP32.
- Documentação oficial da ESP32.
- Biblioteca LEDC.
- Biblioteca MCPWM.
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

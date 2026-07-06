#include <stdio.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//configuração do Display

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const int POT_PIN = 35;
const int BTN_PIN = 19;

const int LED_HORARIO     = 25;
const int LED_ANTIHORARIO = 26;


volatile bool sentidoHorario = true;
volatile unsigned long ultimaInterrupcao = 0;

float velocidadePercentual = 0.0;

// Interrupção do botão
void IRAM_ATTR trataBotao() {

  unsigned long tempoAtual = millis();

  if (tempoAtual - ultimaInterrupcao > 250) {
    sentidoHorario = !sentidoHorario;
    ultimaInterrupcao = tempoAtual;
  }
}


void setup() {

  Serial.begin(115200);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Falha ao inicializar OLED");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Botão
  pinMode(BTN_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), trataBotao, FALLING);

  // LEDs
  pinMode(LED_HORARIO, OUTPUT);
  pinMode(LED_ANTIHORARIO, OUTPUT);

  digitalWrite(LED_HORARIO, HIGH);
  digitalWrite(LED_ANTIHORARIO, LOW);

  Serial.println("Sistema iniciado.");
}


void loop() {
  // Leitura do potenciômetro

  int valorADC = analogRead(POT_PIN);

  velocidadePercentual = (valorADC * 100.0) / 4095.0;

  //indicação do sentido da 'esteira'
  if (sentidoHorario) {

    digitalWrite(LED_HORARIO, HIGH);
    digitalWrite(LED_ANTIHORARIO, LOW);

  } else {

    digitalWrite(LED_HORARIO, LOW);
    digitalWrite(LED_ANTIHORARIO, HIGH);

  }

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.println(" SISTEMA DE ESTEIRA");
  display.println("----------------------");

  display.setCursor(0,20);
  display.print("Velocidade: ");
  display.print(velocidadePercentual,1);
  display.println("%");

  display.setCursor(0,38);
  display.print("Sentido: ");

  if(sentidoHorario)
    display.println("HORARIO");
  else
    display.println("ANTI-HORARIO");

  display.setCursor(0,55);
  display.println("Status: OPERANDO");

  display.display();


//ajudste do monitor serial
  Serial.print("Velocidade: ");
  Serial.print(velocidadePercentual,1);
  Serial.print("% | Sentido: ");

  if(sentidoHorario)
    Serial.println("Horario");
  else
    Serial.println("Anti-Horario");

  delay(100);
}

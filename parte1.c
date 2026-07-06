const int PIN_RED   = 25;
const int PIN_GREEN = 26;
const int PIN_BLUE  = 27;

//config. PWM
const int PWM_FREQ = 5000;  // 5 kHz
const int PWM_RES  = 8;   

//para armazenar o Duty Cycle atual de cada cor
int dutyRed   = 0;
int dutyGreen = 0;
int dutyBlue  = 0;

//taxas de incremento para cada cor 
const int INC_GREEN = 5;             //passo base = 5
const int INC_BLUE  = INC_GREEN * 2; 
const int INC_RED   = INC_GREEN * 3; 

//controle de tempo do print serial 
unsigned long lastPrintTime = 0;
const unsigned long PRINT_INTERVAL = 500;

void setup() {
  //comunicação serial a 115200 baud
  Serial.begin(115200);
  while(!Serial) { delay(10); } 

  Serial.println("--- Inicializando Controle PWM do LED RGB ---");
  Serial.printf("Incrementos definidos -> R: %d | G: %d | B: %d\n", INC_RED, INC_GREEN, INC_BLUE);

  // dos canais LEDC
  ledcAttach(PIN_RED,   PWM_FREQ, PWM_RES);
  ledcAttach(PIN_GREEN, PWM_FREQ, PWM_RES);
  ledcAttach(PIN_BLUE,  PWM_FREQ, PWM_RES);
}

void loop() {
  // atualiza os duty cycles somando o incremento correspondente
  //'%' para voltar a 0 quando chegar em 255)
  dutyRed   = (dutyRed + INC_RED) % 256;
  dutyGreen = (dutyGreen + INC_GREEN) % 256;
  dutyBlue  = (dutyBlue + INC_BLUE) % 256;


  ledcWrite(PIN_RED, dutyRed);
  ledcWrite(PIN_GREEN, dutyGreen);
  ledcWrite(PIN_BLUE, dutyBlue);

  // envia os dados para a UART 
  if (millis() - lastPrintTime >= PRINT_INTERVAL) {
    lastPrintTime = millis();

    Serial.print("[STATUS] ");
    Serial.printf("R_Inc: %d, R_Duty: %d (%d%%) | ", INC_RED, dutyRed, (dutyRed * 100) / 255);
    Serial.printf("G_Inc: %d, G_Duty: %d (%d%%) | ", INC_GREEN, dutyGreen, (dutyGreen * 100) / 255);
    Serial.printf("B_Inc: %d, B_Duty: %d (%d%%)\n", INC_BLUE, dutyBlue, (dutyBlue * 100) / 255);

  delay(100);
}
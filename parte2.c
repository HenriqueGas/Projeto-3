#include <ESP32Servo.h>

const int POT_PIN   = 34; //potenciometro
const int SERVO_PIN = 18; 
Servo meuServo;
void setup() {
  Serial.begin(115200);
  
  //propriedades do servo freq. padrão 50Hz
  meuServo.setPeriodHertz(50); 
  //tempo de pulso max e min
  meuServo.attach(SERVO_PIN, 500, 2400); 
  
  Serial.println("Controle do Servo");
}
void loop() {
  //valor analógico do potenciômetro - 0 a 4095
  int valorADC = analogRead(POT_PIN);
  
  // adc para ângulo - 0 a 180°
  int angulo = map(valorADC, 0, 4095, 0, 180);
  
  //duty cycle em porcentagem
  // 0 graus ~ 2.5% de duty cycle, 180 graus ~ 12% de duty cycle
  float percentualDuty = 2.5 + ((float)angulo / 180.0) * 9.5;
  //servomotor vai para o ângulo calculado
  meuServo.write(angulo);
  
  //exibir dados no monitor serial
  Serial.printf("ADC: %4d | Ângulo: %3d° | Duty Cycle Aprox: %.2f%%\n", valorADC, angulo, percentualDuty);
  
  delay(50);
}

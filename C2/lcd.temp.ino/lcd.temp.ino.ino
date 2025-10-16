#include <LiquidCrystal.h>


LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;   
const int ledPin = 8;       
const int motorPin = 9;     

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.print("Temperatura:");

  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int lectura = analogRead(sensorPin);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperaturaC = (voltaje - 0.5) * 100.0;

  lcd_1.setCursor(0, 1);
  lcd_1.print("Temp: ");
  lcd_1.print(temperaturaC, 1);
  lcd_1.print(" C   "); 

  if (temperaturaC <= 10.0) {
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
 
  else if (temperaturaC > 10.0 && temperaturaC < 26.0) {
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
    delay(1000);
  }
  
  else if (temperaturaC >= 26.0) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
    delay(1000);
  }
}

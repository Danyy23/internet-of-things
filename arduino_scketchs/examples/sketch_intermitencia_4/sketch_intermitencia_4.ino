int led1 = 11; // LED rojo
int led2 = 12; // LED amarillo
int led3 = 13; // LED verde

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(led1, HIGH);
    delay(500);              
    digitalWrite(led1, LOW);
    delay(500);              
  }

  
  for (int i = 0; i < 5; i++) {
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
  }

  for (int i = 0; i < 5; i++) {
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);
  }
}

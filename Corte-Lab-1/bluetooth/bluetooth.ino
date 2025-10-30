#define L1 3  // Define el pin del LED 

void setup() {
  // Código que se ejecuta una sola vez al iniciar
  pinMode(L1, OUTPUT);
  Serial.begin(9600);

  Serial.println("MENU");
  Serial.println("[1] Turn On L1");
  Serial.println("[2] Turn Off L1");
  Serial.print("Press any option: ");
}

void loop() {
  // Código que se ejecuta continuamente
  if (Serial.available() > 0) {
    char opt = Serial.read();

    if (opt == '1') {
      digitalWrite(L1, HIGH);
      Serial.println("\nL1 is ON");
    } 
    else if (opt == '2') {
      digitalWrite(L1, LOW);
      Serial.println("\nL1 is OFF");
    } 
    else {
      Serial.println("\nInvalid option!");
    }

    // Mostrar el menú nuevamente
    Serial.println("\nMENU");
    Serial.println("[1] Turn On L1");
    Serial.println("[2] Turn Off L1");
    Serial.print("Press any option: ");
  }
}

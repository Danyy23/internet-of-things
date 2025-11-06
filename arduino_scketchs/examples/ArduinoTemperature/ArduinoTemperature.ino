#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
#define LED_RED 13

float humidity, temperature;

// Crear la instancia
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LED_RED, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  Serial.println("::Hello to weather station::" );
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Corregir el uso de la variable 'humidity' (en minúsculas)
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", ");
  Serial.print("Temperature: ");
  Serial.println(temperature);

  delay(2000);  // Espera de 2 segundos antes de leer nuevamente
}

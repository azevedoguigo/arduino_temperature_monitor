#include <Thermistor.h>

Thermistor temp(2);

int LED = 2;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(LED, OUTPUT);
}

void loop() {
  int temperature = temp.getTemp();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("ºC");

  digitalWrite(LED, HIGH);
  delay(400);

  digitalWrite(LED, LOW);
  delay(5000);
}

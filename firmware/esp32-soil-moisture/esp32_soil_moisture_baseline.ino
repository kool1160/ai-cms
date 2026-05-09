/*
  AI-CMS V1-M2 — ESP32 Sensor Read Baseline

  Purpose:
  Read one capacitive soil moisture sensor on an ESP32 and print raw analog values
  to the Serial Monitor.

  Wiring / Pin Notes:
  - Sensor VCC  -> ESP32 3.3V
  - Sensor GND  -> ESP32 GND
  - Sensor AO   -> ESP32 GPIO 34

  Notes:
  - GPIO 34 is input-only and works well for analog sensor input.
  - This milestone is firmware-only.
  - No dashboard, cloud, AI analytics, or app features are included.
*/

const int SOIL_MOISTURE_PIN = 34;
const unsigned long READ_INTERVAL_MS = 1000;

unsigned long lastReadTime = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("AI-CMS V1-M2 — ESP32 Sensor Read Baseline");
  Serial.println("Reading one capacitive soil moisture sensor...");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastReadTime >= READ_INTERVAL_MS) {
    lastReadTime = currentTime;

    int rawMoistureValue = analogRead(SOIL_MOISTURE_PIN);

    Serial.print("Raw soil moisture reading: ");
    Serial.println(rawMoistureValue);
  }
}

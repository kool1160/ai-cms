/*
  AI-CMS V1-M3 — Moisture Calibration Rules

  Purpose:
  Read one capacitive soil moisture sensor on an ESP32, print raw analog values,
  and output a basic soil status to the Serial Monitor.

  Wiring / Pin Notes:
  - Sensor VCC  -> ESP32 3.3V
  - Sensor GND  -> ESP32 GND
  - Sensor AO   -> ESP32 GPIO 34

  Calibration Notes:
  - First test the sensor in dry air and record the raw value.
  - Then test the sensor in wet soil and record the raw value.
  - Adjust the threshold values below after comparing dry-air and wet-soil readings.
  - Capacitive sensors commonly read higher when dry and lower when wet, but verify
    with the actual sensor before relying on status labels.

  Notes:
  - GPIO 34 is input-only and works well for analog sensor input.
  - This milestone is firmware-only.
  - No dashboard, cloud, AI analytics, or app features are included.
*/

const int SOIL_MOISTURE_PIN = 34;
const unsigned long READ_INTERVAL_MS = 1000;

// Temporary starting thresholds. Calibrate with real dry-air and wet-soil readings.
const int DRY_THRESHOLD = 3000;
const int WATCH_THRESHOLD = 2400;
const int GOOD_THRESHOLD = 1600;

unsigned long lastReadTime = 0;

String getMoistureStatus(int rawValue) {
  if (rawValue >= DRY_THRESHOLD) {
    return "DRY";
  }

  if (rawValue >= WATCH_THRESHOLD) {
    return "WATCH";
  }

  if (rawValue >= GOOD_THRESHOLD) {
    return "GOOD";
  }

  return "WET";
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("AI-CMS V1-M3 — Moisture Calibration Rules");
  Serial.println("Reading one capacitive soil moisture sensor...");
  Serial.println("Status thresholds: DRY / WATCH / GOOD / WET");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastReadTime >= READ_INTERVAL_MS) {
    lastReadTime = currentTime;

    int rawMoistureValue = analogRead(SOIL_MOISTURE_PIN);
    String moistureStatus = getMoistureStatus(rawMoistureValue);

    Serial.print("Raw soil moisture reading: ");
    Serial.print(rawMoistureValue);
    Serial.print(" | Status: ");
    Serial.println(moistureStatus);
  }
}

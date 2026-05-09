/*
  AI-CMS V1-M4 — Local ESP32 Web Dashboard Shell

  Purpose:
  Read one capacitive soil moisture sensor on an ESP32, print raw analog values,
  output a basic soil status to the Serial Monitor, and serve a simple local
  dashboard page from the ESP32.

  Wiring / Pin Notes:
  - Sensor VCC  -> ESP32 3.3V
  - Sensor GND  -> ESP32 GND
  - Sensor AO   -> ESP32 GPIO 34

  Wi-Fi Notes:
  - Enter your local Wi-Fi name and password below before uploading.
  - After upload, open the Serial Monitor to find the ESP32 local IP address.
  - Visit that IP address from a device on the same Wi-Fi network.

  Calibration Notes:
  - First test the sensor in dry air and record the raw value.
  - Then test the sensor in wet soil and record the raw value.
  - Adjust the threshold values below after comparing dry-air and wet-soil readings.
  - Capacitive sensors commonly read higher when dry and lower when wet, but verify
    with the actual sensor before relying on status labels.

  Guardrails:
  - One sensor only.
  - Local dashboard only.
  - No hourly storage, bar graph, cloud, AI analytics, or mobile app features.
*/

#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const int SOIL_MOISTURE_PIN = 34;
const unsigned long READ_INTERVAL_MS = 1000;

// Temporary starting thresholds. Calibrate with real dry-air and wet-soil readings.
const int DRY_THRESHOLD = 3000;
const int WATCH_THRESHOLD = 2400;
const int GOOD_THRESHOLD = 1600;

WebServer server(80);
unsigned long lastReadTime = 0;
int currentRawMoistureValue = 0;
String currentMoistureStatus = "UNKNOWN";

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

void readMoistureSensor() {
  currentRawMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  currentMoistureStatus = getMoistureStatus(currentRawMoistureValue);

  Serial.print("Raw soil moisture reading: ");
  Serial.print(currentRawMoistureValue);
  Serial.print(" | Status: ");
  Serial.println(currentMoistureStatus);
}

String buildDashboardPage() {
  String page = "<!doctype html><html><head>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  page += "<meta http-equiv='refresh' content='5'>";
  page += "<title>AI-CMS Soil Monitor</title>";
  page += "<style>body{font-family:Arial,sans-serif;margin:24px;background:#f6f7f8;color:#111;}";
  page += ".card{max-width:520px;padding:20px;border-radius:14px;background:#fff;box-shadow:0 2px 12px rgba(0,0,0,.12);}";
  page += "h1{font-size:24px;margin:0 0 8px;} .label{color:#555;margin-top:18px;}";
  page += ".value{font-size:34px;font-weight:700;margin-top:4px;} .status{font-size:42px;font-weight:800;margin-top:4px;}";
  page += ".note{font-size:14px;color:#666;margin-top:18px;line-height:1.4;}";
  page += "</style></head><body><div class='card'>";
  page += "<h1>AI-CMS Soil Monitor</h1>";
  page += "<div class='note'>Local ESP32 dashboard shell — one sensor only.</div>";
  page += "<div class='label'>Raw moisture value</div>";
  page += "<div class='value'>" + String(currentRawMoistureValue) + "</div>";
  page += "<div class='label'>Current status</div>";
  page += "<div class='status'>" + currentMoistureStatus + "</div>";
  page += "<div class='note'>Page refreshes every 5 seconds. No hourly storage or bar graph yet.</div>";
  page += "</div></body></html>";
  return page;
}

void handleDashboard() {
  server.send(200, "text/html", buildDashboardPage());
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("AI-CMS V1-M4 — Local ESP32 Web Dashboard Shell");
  Serial.println("Reading one capacitive soil moisture sensor...");
  Serial.println("Status thresholds: DRY / WATCH / GOOD / WET");

  readMoistureSensor();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Dashboard available at: http://");
  Serial.println(WiFi.localIP());

  server.on("/", handleDashboard);
  server.begin();
}

void loop() {
  server.handleClient();

  unsigned long currentTime = millis();

  if (currentTime - lastReadTime >= READ_INTERVAL_MS) {
    lastReadTime = currentTime;
    readMoistureSensor();
  }
}

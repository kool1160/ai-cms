/*
  AI-CMS V1-M6 — Dashboard Bar Graph

  Purpose:
  Read one capacitive soil moisture sensor on an ESP32, print raw analog values,
  output a basic soil status to the Serial Monitor, serve a simple local dashboard,
  keep recent hourly readings in runtime memory, and display those readings as
  lightweight dashboard bars.

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
  - Runtime memory only.
  - No database, cloud, AI analytics, mobile app, platform features, or multiple sensors.
*/

#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const int SOIL_MOISTURE_PIN = 34;
const unsigned long READ_INTERVAL_MS = 1000;
const unsigned long HOURLY_CAPTURE_INTERVAL_MS = 3600000;
const int MAX_READING_HISTORY = 24;
const int ADC_MAX_VALUE = 4095;

// Temporary starting thresholds. Calibrate with real dry-air and wet-soil readings.
const int DRY_THRESHOLD = 3000;
const int WATCH_THRESHOLD = 2400;
const int GOOD_THRESHOLD = 1600;

struct MoistureReading {
  unsigned long capturedAtMs;
  int rawValue;
  String status;
};

WebServer server(80);
unsigned long lastReadTime = 0;
unsigned long lastHourlyCaptureTime = 0;
int currentRawMoistureValue = 0;
String currentMoistureStatus = "UNKNOWN";
MoistureReading readingHistory[MAX_READING_HISTORY];
int readingHistoryCount = 0;

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

String formatElapsedTime(unsigned long capturedAtMs) {
  unsigned long elapsedMs = millis() - capturedAtMs;
  unsigned long elapsedMinutes = elapsedMs / 60000;

  if (elapsedMinutes < 1) {
    return "just now";
  }

  if (elapsedMinutes < 60) {
    return String(elapsedMinutes) + " min ago";
  }

  return String(elapsedMinutes / 60) + " hr ago";
}

void captureHourlyReading() {
  if (readingHistoryCount < MAX_READING_HISTORY) {
    readingHistory[readingHistoryCount] = { millis(), currentRawMoistureValue, currentMoistureStatus };
    readingHistoryCount++;
    return;
  }

  for (int i = 1; i < MAX_READING_HISTORY; i++) {
    readingHistory[i - 1] = readingHistory[i];
  }

  readingHistory[MAX_READING_HISTORY - 1] = { millis(), currentRawMoistureValue, currentMoistureStatus };
}

void readMoistureSensor() {
  currentRawMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  currentMoistureStatus = getMoistureStatus(currentRawMoistureValue);

  Serial.print("Raw soil moisture reading: ");
  Serial.print(currentRawMoistureValue);
  Serial.print(" | Status: ");
  Serial.println(currentMoistureStatus);
}

String buildReadingBarsHtml() {
  if (readingHistoryCount == 0) {
    return "<div class='note'>No readings available for graph yet.</div>";
  }

  String html = "<div class='barGraph'>";

  for (int i = readingHistoryCount - 1; i >= 0; i--) {
    int barWidth = map(readingHistory[i].rawValue, 0, ADC_MAX_VALUE, 4, 100);

    if (barWidth < 4) {
      barWidth = 4;
    }

    if (barWidth > 100) {
      barWidth = 100;
    }

    html += "<div class='barRow'>";
    html += "<div class='barLabel'>" + formatElapsedTime(readingHistory[i].capturedAtMs) + "</div>";
    html += "<div class='barTrack'><div class='barFill' style='width:" + String(barWidth) + "%;'></div></div>";
    html += "<div class='barValue'>" + String(readingHistory[i].rawValue) + "</div>";
    html += "</div>";
  }

  html += "</div>";
  return html;
}

String buildReadingHistoryHtml() {
  if (readingHistoryCount == 0) {
    return "<div class='note'>No hourly readings captured yet.</div>";
  }

  String html = "<table><thead><tr><th>Captured</th><th>Raw</th><th>Status</th></tr></thead><tbody>";

  for (int i = readingHistoryCount - 1; i >= 0; i--) {
    html += "<tr><td>" + formatElapsedTime(readingHistory[i].capturedAtMs) + "</td>";
    html += "<td>" + String(readingHistory[i].rawValue) + "</td>";
    html += "<td>" + readingHistory[i].status + "</td></tr>";
  }

  html += "</tbody></table>";
  return html;
}

String buildDashboardPage() {
  String page = "<!doctype html><html><head>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  page += "<meta http-equiv='refresh' content='5'>";
  page += "<title>AI-CMS Soil Monitor</title>";
  page += "<style>body{font-family:Arial,sans-serif;margin:24px;background:#f6f7f8;color:#111;}";
  page += ".card{max-width:680px;padding:20px;border-radius:14px;background:#fff;box-shadow:0 2px 12px rgba(0,0,0,.12);}";
  page += "h1{font-size:24px;margin:0 0 8px;} h2{font-size:20px;margin:24px 0 8px;} .label{color:#555;margin-top:18px;}";
  page += ".value{font-size:34px;font-weight:700;margin-top:4px;} .status{font-size:42px;font-weight:800;margin-top:4px;}";
  page += ".note{font-size:14px;color:#666;margin-top:18px;line-height:1.4;}";
  page += ".barGraph{margin-top:10px;} .barRow{display:grid;grid-template-columns:80px 1fr 56px;gap:8px;align-items:center;margin:8px 0;}";
  page += ".barLabel,.barValue{font-size:13px;color:#555;} .barTrack{height:18px;background:#e5e7eb;border-radius:10px;overflow:hidden;}";
  page += ".barFill{height:100%;background:#111;border-radius:10px;}";
  page += "table{width:100%;border-collapse:collapse;margin-top:10px;} th,td{text-align:left;padding:8px;border-bottom:1px solid #ddd;} th{color:#555;font-size:13px;}";
  page += "</style></head><body><div class='card'>";
  page += "<h1>AI-CMS Soil Monitor</h1>";
  page += "<div class='note'>Local ESP32 dashboard — one sensor only.</div>";
  page += "<div class='label'>Raw moisture value</div>";
  page += "<div class='value'>" + String(currentRawMoistureValue) + "</div>";
  page += "<div class='label'>Current status</div>";
  page += "<div class='status'>" + currentMoistureStatus + "</div>";
  page += "<h2>Recent reading graph</h2>";
  page += buildReadingBarsHtml();
  page += "<h2>Recent hourly readings</h2>";
  page += buildReadingHistoryHtml();
  page += "<div class='note'>Bars represent raw ESP32 ADC moisture values. Readings are stored in runtime memory only.</div>";
  page += "</div></body></html>";
  return page;
}

void handleDashboard() {
  server.send(200, "text/html", buildDashboardPage());
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("AI-CMS V1-M6 — Dashboard Bar Graph");
  Serial.println("Reading one capacitive soil moisture sensor...");
  Serial.println("Status thresholds: DRY / WATCH / GOOD / WET");

  readMoistureSensor();
  captureHourlyReading();
  lastHourlyCaptureTime = millis();

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

  if (currentTime - lastHourlyCaptureTime >= HOURLY_CAPTURE_INTERVAL_MS) {
    lastHourlyCaptureTime = currentTime;
    captureHourlyReading();
  }
}

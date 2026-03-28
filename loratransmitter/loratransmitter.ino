#include <SoftwareSerial.h>
#include <DHT.h>
#include <Adafruit_BMP085.h>

#define DHTPIN 3         // DHT11 connected to digital pin 3
#define DHTTYPE DHT11
#define WATER_PIN A0     // Analog input for water level sensor

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

// HC-12 connected to pin 2 (RX) and 4 (TX)
SoftwareSerial HC12(2, 4);

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  dht.begin();

  if (!bmp.begin()) {
    Serial.println("BMP180 not detected!");
    while (1);
  }

  Serial.println("HC12 Weather Transmitter Ready...");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float pressure = bmp.readPressure() / 100.0;  // convert Pa to hPa
  float altitude = bmp.readAltitude();
  int waterLevel = analogRead(WATER_PIN);

  // If DHT fails to read, skip this cycle
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Format data into a single string
  String data = "Temp:" + String(temperature) + "C, " +
                "Hum:" + String(humidity) + "%, " +
                "Pres:" + String(pressure) + "hPa, " +
                "Alt:" + String(altitude) + "m, " +
                "Water:" + String(waterLevel);

  // Send via HC-12
  HC12.println(data);
  Serial.println("Sent -> " + data);

  delay(5000);  // Send every 5 seconds
}

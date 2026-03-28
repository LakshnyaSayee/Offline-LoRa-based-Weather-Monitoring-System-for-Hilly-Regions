void setup() {
  Serial.begin(9600);
  Serial.println("Weather Monitor Simulation Ready...");
}

void loop() {
  // Dummy values
  float temperature = 28.5;   // °C
  float humidity = 65.0;      // %
  float pressure = 1007.2;    // hPa
  int waterLevel = 320;       // arbitrary value

  // Print to Serial Monitor
  Serial.println("---- Sensor Data ----");
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("Water Level: "); Serial.println(waterLevel);
  Serial.println("--------------------");

  delay(2000); // update every 2 seconds
}

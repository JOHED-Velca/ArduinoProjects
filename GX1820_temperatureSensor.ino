// First install the OneWire and DallasTemperature libraries
// Pins order facing the flat side from left to right: signal, 5v, ground.

#include <OneWire.h>
#include <DallasTemperature.h>

// Temperature Sensor
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// RGB LED Pins
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

void setup() {
  Serial.begin(9600);
  sensors.begin();

  // Set RGB LED pins as output
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Control RGB LED color based on temperature
  if (temperature > 27) {
    setColor(255, 0, 0);  // Red for temp > 27°C
  } else if (temperature >= 26 && temperature <= 27) {
    setColor(0, 255, 0);  // Green for 26°C <= temp <= 27°C
  } else {
    setColor(0, 0, 255);  // Blue for temp < 26°C
  }

  delay(1000);  // Wait 1 second before the next reading
}

// Function to set the RGB LED color
void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

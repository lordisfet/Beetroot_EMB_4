#include <Arduino.h>

#define MONITOR_BAUD_RATE 115200
#define ADC_RESOLUTION 12
#define ADC_MAX_VALUE ((1 << ADC_RESOLUTION) - 1)
#define ADC_REF_VOLTAGE 3.3
#define ADC_PIN 4

double calculateVoltage(int adcValue);

int measureInterval = 100;

void setup() {
  Serial.begin(MONITOR_BAUD_RATE);
  analogReadResolution(ADC_RESOLUTION);
  pinMode(ADC_PIN, INPUT);
}

void loop() {
  int adcValue = analogRead(ADC_PIN);

  Serial.print("ADC RAW value: " + String(adcValue));
  Serial.print("\t|\tCalculeted voltage: " + String(calculateVoltage(adcValue), 3) + " V");
  Serial.println("\t|\t Measured voltage: " + String(analogReadMilliVolts(ADC_PIN)) + " V");
  delay(measureInterval);
}

double calculateVoltage(int adcValue) {
  return (adcValue / (double)ADC_MAX_VALUE) * ADC_REF_VOLTAGE;
}
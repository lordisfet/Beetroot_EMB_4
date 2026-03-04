#include <Arduino.h>

#define MONITOR_BAUD_RATE 115200
#define ADC_RESOLUTION 12
#define ADC_MAX_VALUE ((1 << ADC_RESOLUTION) - 1)
#define ADC_REF_VOLTAGE 3.3
#define ADC_PIN 4

double calculateVoltage(int adcValue);
void printData(int adcResolution = ADC_RESOLUTION, adc_attenuation_t attenuation = ADC_11db);

int measureInterval = 100;

void setup() {
  Serial.begin(MONITOR_BAUD_RATE);
  analogReadResolution(ADC_RESOLUTION);
  analogSetAttenuation(ADC_11db); // Set attenuation for the ADC pin to read up to 3.3V
  pinMode(ADC_PIN, INPUT);
}

void loop() {
  printData();
  delay(measureInterval);
}

double calculateVoltage(int adcValue) {
  return (adcValue / (double)ADC_MAX_VALUE) * ADC_REF_VOLTAGE;
}

void printData(int adcResolution = ADC_RESOLUTION, adc_attenuation_t attenuation = ADC_11db) {
  int adcValue = analogRead(ADC_PIN);
  double calculatedVoltage = calculateVoltage(adcValue);
  double measuredVoltage = analogReadMilliVolts(ADC_PIN) / 1000.0;

  Serial.print("ADC RAW value: " + String(adcValue));
  Serial.print("\t|\tCalculeted voltage: " + String(calculatedVoltage, 3) + " V");
  Serial.print("\t|\tMeasured voltage: " + String(measuredVoltage, 3) + " V");
  Serial.println("\t|\tDifference: " + String(abs(calculatedVoltage - measuredVoltage) * 100.0 / measuredVoltage, 2) + " %");
}
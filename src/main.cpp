#include <Arduino.h>

#define MONITOR_BAUD_RATE 115200
#define ADC_MAX_RESOLUTION 12
#define ADC_MIN_RESOLUTION 8
#define ADC_REF_VOLTAGE 3.3
#define ADC_PIN 4

double calculateVoltage(int adcValue, int adcResolution);
double maxValueADC(int adcResolution);
void printData(int adcResolution = ADC_MAX_RESOLUTION, adc_attenuation_t attenuation = ADC_11db);

int measureInterval = 100;

void setup() {
  Serial.begin(MONITOR_BAUD_RATE);
  pinMode(ADC_PIN, INPUT);
}

void loop() {
  Serial.println("\n-----------------------------------------------------------------------------------------------------------------------------");
  Serial.println("ADC measurement with different RESOLUTION:");
  for (int i = ADC_MIN_RESOLUTION; i <= ADC_MAX_RESOLUTION; i++)
  {
    printData(i);
  }
  Serial.println("-   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -");
  Serial.println("ADC measurement with different ATTENUATION:");
  for (int i = 0; i <= ADC_ATTENDB_MAX; i++)
  {
    printData(ADC_MAX_RESOLUTION, (adc_attenuation_t)i);
  }
  
  Serial.println("-----------------------------------------------------------------------------------------------------------------------------\n");  
  delay(measureInterval);
}

double calculateVoltage(int adcValue, int adcResolution) {
  return (adcValue / (double)maxValueADC(adcResolution)) * ADC_REF_VOLTAGE;
}

double maxValueADC(int adcResolution) {
  return (1 << adcResolution) - 1;
}

void printData(int adcResolution, adc_attenuation_t attenuation) {
  analogReadResolution(adcResolution);
  analogSetAttenuation(attenuation);

  int adcValue = analogRead(ADC_PIN);
  double calculatedVoltage = calculateVoltage(adcValue, adcResolution);
  double measuredVoltage = analogReadMilliVolts(ADC_PIN) / 1000.0;

  Serial.print("ADC Resolution: " + String(adcResolution) + " bits, " + (String)maxValueADC(adcResolution) + " max value");
  Serial.print("\t|\tADC RAW value: " + String(adcValue));
  Serial.print("\t|\tCalculeted voltage: " + String(calculatedVoltage, 3) + " V");
  Serial.print("\t|\tMeasured voltage: " + String(measuredVoltage, 3) + " V");
  Serial.println("\t|\tDifference: " + String(abs(calculatedVoltage - measuredVoltage) * 100.0 / measuredVoltage, 2) + " %");
}
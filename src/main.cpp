#include <Arduino.h>

constexpr int MONITOR_BOUD_RATE = 115200;

constexpr int8_t RELAY_CONTROLL_PIN = 21;
constexpr int8_t RELAY_INPUT_PIN = 2;

volatile unsigned long signalSentTime = 0;
volatile unsigned long reactionTime = 0;
volatile bool measurementReady = false;
volatile bool waitingForMeasurement = false;

const int MAX_MEASUREMENTS = 10;
int measurementCount = 0;
unsigned long totalReactionTime = 0;
bool relayControlPinState = LOW;

void IRAM_ATTR relayContactISR()
{
  if (waitingForMeasurement)
  {
    reactionTime = millis() - signalSentTime;
    measurementReady = true;
    waitingForMeasurement = false;
  }
}

void setup()
{
  Serial.begin(MONITOR_BOUD_RATE);
  Serial.println("Starting relay reaction time test (10 measurements)...");

  pinMode(RELAY_CONTROLL_PIN, OUTPUT);
  digitalWrite(RELAY_CONTROLL_PIN, relayControlPinState);

  pinMode(RELAY_INPUT_PIN, INPUT_PULLDOWN);

  attachInterrupt(digitalPinToInterrupt(RELAY_INPUT_PIN), relayContactISR, RISING);
}

void loop()
{
  unsigned long currentTime = millis();
  static unsigned long lastActiveTime = 0;

  if (measurementCount < MAX_MEASUREMENTS)
  {
    if (currentTime - lastActiveTime >= 1000)
    {
      lastActiveTime = currentTime;
      relayControlPinState = !relayControlPinState;

      if (relayControlPinState == HIGH)
      {
        measurementReady = false;
        waitingForMeasurement = true;
        signalSentTime = millis();
        digitalWrite(RELAY_CONTROLL_PIN, HIGH);
      }
      else
      {
        digitalWrite(RELAY_CONTROLL_PIN, LOW);
      }
    }
  }

  if (measurementReady)
  {
    measurementReady = false;
    measurementCount++;
    totalReactionTime += reactionTime;

    Serial.print("Measurement ");
    Serial.print(measurementCount);
    Serial.print(": ");
    Serial.print(reactionTime);
    Serial.println(" ms");

    if (measurementCount == MAX_MEASUREMENTS)
    {
      float averageTime = (float)totalReactionTime / MAX_MEASUREMENTS;
      Serial.println("================================");
      Serial.print("Average reaction time: ");
      Serial.print(averageTime);
      Serial.println(" ms");
    }
  }
}
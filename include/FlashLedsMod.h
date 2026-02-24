class FlashLedsMod
{
private:
  const int8_t* leds;
  int8_t count;
  unsigned int duration;

  void flashLed(int led, unsigned long start, unsigned int duration, unsigned int currentCycle);

public:
  FlashLedsMod(const int8_t* leds, int8_t count, int duration);
  FlashLedsMod();
  ~FlashLedsMod();

  void setLeds(const int8_t* leds, int8_t count) {
    this->leds = leds;
    this->count = count;
  }

  void flashing(unsigned long currentCycle);

  unsigned int getDuration() const {
    return duration;
  }

  void setDuration(unsigned int newDuration) {
    duration = newDuration;
  }

  unsigned long getTotalCycles() const {
    int totalCycles = duration * count;
    return totalCycles > 0 ? totalCycles : 1; // Ensure totalCycles is at least 1 to avoid division by zero
  }
};
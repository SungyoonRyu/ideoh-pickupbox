#ifndef MTASK_H
#define MTASK_H

#include <Arduino.h>

struct TaskState {
  unsigned long delayTime;
  boolean isDelaying;
};

class MTask {
private:
  unsigned long bef_delay_time;
public:
  boolean isDelaying = false;
  unsigned long delayTime = 0; // TODO : it is depends on isDelaying. it should separate by state with isDelaying
    virtual void setup() = 0;
    virtual void loop() = 0;

  void delayMillis(unsigned long dt);
  void delayMillis();
  void delayMicros(unsigned int dt);
};

#endif

#include "mtask.h"

void MTask::delayMillis() {
  delayMillis(delayTime);
}

void MTask::delayMillis(unsigned long dt) {
  if(!isDelaying) {
    delayTime = dt;
    isDelaying = true;
    bef_delay_time = millis();
    return;
  }
  if(millis() - bef_delay_time < dt)
    return;
  else {
    isDelaying = false;
    return;
  }
}

void MTask:: delayMicros(unsigned int dt) {
  
}

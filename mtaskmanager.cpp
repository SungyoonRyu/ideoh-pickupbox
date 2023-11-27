#include "mtaskmanager.h"

MTaskManager* instance = NULL;

MTaskManager* MTaskManager::getInstance() {
    if(instance == NULL) {
        instance = new MTaskManager();
        return instance;
    }
    return instance;
}

void MTaskManager::addTask(MTask* task) {
  tasks[num_task++] = task;
}

void MTaskManager::run() {
#if RUN_MODE==1
  auto startLoop_millis = micros();
#endif
  for (int i = 0; i < num_task; ++i) {
    if(tasks[i]->isDelaying)
      tasks[i]->delayMillis();
    else
      tasks[i]->loop();
  }
  ++count;
#if RUN_MODE==1
  estimated_running_time = 0.7 * (micros() - startLoop_millis) + 0.2 * estimated_running_time;
  if (!(count % DEBUG_INTERVAL)) {
    Serial.println(estimated_running_time);
  }
#endif
}

#ifndef MTASK_MANAGER_H
#define MTASK_MANAGER_H

#define RUN_MODE 0
// 0 - release, 1 - debug
#define DEBUG_INTERVAL 2048
#define TASK_CAPACITY 32
#define ORDER_CAPACITY 32

#include "mtask.h"

// struct BoxState {
// }

// struct Order {
//   int orderId;
// }

// struct 

// struct MState {
//   BoxState pBox[4];
//   OrderId orderQueue[100];
// }


class MTaskManager {
private:
  unsigned long estimated_running_time = 0;
  unsigned long count = 0;

  MTask* tasks[TASK_CAPACITY];
  int num_task = 0;
public:
  static MTaskManager* getInstance();

  void addTask(MTask* task);

  void run();
};


#endif // end MTASK_MANAGER_H

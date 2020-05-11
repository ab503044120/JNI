//
// Created by huihui on 2019/8/19.
//

#ifndef QLAUNCHER_CONDITION_H
#define QLAUNCHER_CONDITION_H

#include <pthread.h>
class Condition {
 private:
  pthread_cond_t cond;
 public:
  void wait(pthread_mutex_t *mutex);
  void wait(int64_t time, pthread_mutex_t *mutex);
  void signal();
  Condition();
  virtual ~Condition();
};


#endif //QLAUNCHER_CONDITION_H

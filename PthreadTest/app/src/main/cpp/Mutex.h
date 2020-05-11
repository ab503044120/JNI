//
// Created by huihui on 2019/8/19.
//
#include <pthread.h>
#ifndef QLAUNCHER_MUTEX_H
#define QLAUNCHER_MUTEX_H


class Mutex {
 private:
  pthread_mutex_t mutex;
 public:
  void lock();
  void unLock();
  Mutex();
  virtual ~Mutex();
};


#endif //QLAUNCHER_MUTEX_H

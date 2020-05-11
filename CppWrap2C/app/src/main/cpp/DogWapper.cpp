//
// Created by huihui on 2019/9/8.
//

#include "DogWapper.h"
#include "Dog.h"
#ifdef __cplusplus
extern "C" {
#endif
void *getInstance() {
  return new Test::Dog;
}
void call(void *dog) {
  (static_cast<Test::Dog *>(dog))->call();
}
void destory(void **dog) {
  delete (*dog);
  *dog = nullptr;
}

#ifdef __cplusplus
}
#endif
//
// Created by huihui on 2019/9/8.
//

#include "DogWapper.h"
#include "Dog.h"
#include "DogWraper2.h"

#ifdef __cplusplus
extern "C" {
#endif
struct DogWrapper {
  Test::Dog *delegate;
};

DogWrapper *getDogWapper() {
  auto wrapper = new DogWrapper();
  wrapper->delegate = new Test::Dog();
  return wrapper;
}


void callx(DogWrapper *dogWapper) {
  dogWapper->delegate->call();
}
void distroyDogWapper(DogWrapper **dogWapper) {
  delete (*dogWapper)->delegate;
  (*dogWapper)->delegate = nullptr;
  delete *dogWapper;
}
#ifdef __cplusplus
}
#endif
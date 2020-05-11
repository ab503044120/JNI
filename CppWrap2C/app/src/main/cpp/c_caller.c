//
// Created by huihui on 2019/9/8.
//
#include "DogWapper.h"
#include "DogWraper2.h"

void c_call() {
  void *instance = getInstance();
  call(instance);
  destory(&instance);
}

void c_call2() {
  DogWrapper *wrap = getDogWapper();
  callx(wrap);
  distroyDogWapper(&wrap);
}
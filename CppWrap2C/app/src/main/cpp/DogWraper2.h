//
// Created by huihui on 2019/9/8.
//

#ifndef CPPWRAP2C_DOGWRAPER2_H
#define CPPWRAP2C_DOGWRAPER2_H
#ifdef __cplusplus
extern "C" {
#endif
struct DogWrapper;

typedef struct DogWrapper DogWrapper;

DogWrapper *getDogWapper();

void callx(DogWrapper *dogWapper);

void distroyDogWapper(DogWrapper **dogWapper);
#ifdef __cplusplus
}
#endif
#endif //CPPWRAP2C_DOGWRAPER2_H

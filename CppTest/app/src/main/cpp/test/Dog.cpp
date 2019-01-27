//
// Created by huihui on 2019/1/27.
//

#include "Dog.h"
#include <android/log.h>
Dog::Dog( string n) : Animal(n) {

}

void Dog::call() {
    __android_log_print(ANDROID_LOG_ERROR,"dog","汪汪汪");
}

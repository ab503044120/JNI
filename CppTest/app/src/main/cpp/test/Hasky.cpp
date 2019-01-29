//
// Created by huihui on 2019/1/27.
//

#include <android/log.h>
#include "Hasky.h"

Hasky::Hasky(const string &n) : Dog(n) {


}

void Hasky::call() {
    __android_log_print(ANDROID_LOG_ERROR,"dog","啊呜");
}

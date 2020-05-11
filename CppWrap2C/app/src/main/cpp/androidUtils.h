//
// Created by huihui on 2019/8/21.
//
#include <android/log.h>

#ifndef QLAUNCHER_ANDROIDUTILS_H
#define QLAUNCHER_ANDROIDUTILS_H
#define  Log_i(TAG, ...)  __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
#define  Log_e(TAG, ...)  __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
#endif //QLAUNCHER_ANDROIDUTILS_H

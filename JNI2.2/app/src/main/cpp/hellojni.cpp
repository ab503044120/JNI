//
// Created by huihui on 2016/9/21.
//

#include "com_android_jni22_MainActivity.h"
#include "other.h"
JNIEXPORT jstring JNICALL
Java_com_android_jni22_MainActivity_hellojni(JNIEnv *env, jobject instance) {

    return env->NewStringUTF(gethello());
}

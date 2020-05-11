//
// Created by huihui on 2020/3/19.
//

#ifndef JNITEST_TESTC_H
#define JNITEST_TESTC_H
#include <jni.h>
#ifdef __cplusplus
extern "C"{
#endif
void test(JNIEnv *env);

JNIEXPORT void JNICALL
Java_org_huihui_jnitest_TestC_envTest(JNIEnv *env, jobject thiz);

#ifdef __cplusplus
}
#endif
#endif //JNITEST_TESTC_H

//
// Created by huihui on 2020/3/19.
//

#include "Testc.h"
void test(JNIEnv *env) {
  JavaVM *javaVm;
  (*env)->GetJavaVM(env, &javaVm);
  JNIEnv *jniEnv;
  (*javaVm)->GetEnv(javaVm, (void **) &jniEnv, JNI_VERSION_1_6);
}

JNIEXPORT void JNICALL
Java_org_huihui_jnitest_TestC_envTest(JNIEnv *env, jobject thiz) {
  test(env);
}


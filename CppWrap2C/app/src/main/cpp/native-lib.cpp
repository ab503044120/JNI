#include <jni.h>
#include <string>
#include "c_caller.h"

extern "C" JNIEXPORT jstring JNICALL
Java_org_huihui_cppwrap2c_MainActivity_stringFromJNI(
    JNIEnv *env,
    jobject /* this */) {
  std::string hello = "Hello from C++";
  c_call();
  c_call2();
  return env->NewStringUTF(hello.c_str());
}

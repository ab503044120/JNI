#include <jni.h>
#include <string>
extern "C"
#include "hello.h"
extern "C" JNIEXPORT jstring
JNICALL
Java_org_huihui_ndk_131_MainActivity_stringFromJNI(
    JNIEnv *env,
    jobject /* this */) {
  std::string hello = "Hello from C++";
  for (int i = 0; i < 100; ++i) {
    hello1();
  }
  return env->NewStringUTF(hello.c_str());
}

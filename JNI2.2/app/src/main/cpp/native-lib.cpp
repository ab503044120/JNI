#include "com_android_jni22_MainActivity.h"
#include <string>

extern "C"
jstring
Java_com_android_jni22_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

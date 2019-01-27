#include <jni.h>
#include <string>
#include <android/log.h>
#include "test/Animal.h"
#include "test/Dog.h"
#include "test/Hasky.h"
#include "test/Pet.h"

extern "C" JNIEXPORT jstring JNICALL
Java_org_huihui_cpptest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    Hasky hasky("汪汪");

    hasky.Pet::call();
    return env->NewStringUTF(hello.c_str());
}

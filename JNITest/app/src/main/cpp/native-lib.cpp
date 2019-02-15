#include <jni.h>
#include <string>
#include "log/log.h"
#include <pthread.h>

const char *TAG = "happy";

struct global_context {
    JavaVM *javaVm;
    jclass callbackClass;
    jmethodID callbackClass_onTick;
} g_ctx;


JNIEXPORT
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    memset(&g_ctx, 0, sizeof(g_ctx));
    g_ctx.javaVm = vm;
    LOGV(TAG, "JNI_OnLoad");
    return JNI_VERSION_1_6;
}

JNIEXPORT
void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGV(TAG, "JNI_OnUnload");
}

extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_jnitest_Test_init(JNIEnv *env, jclass clazz, jobject callback) {
    jclass callbackClass = env->GetObjectClass(callback);
    jmethodID callbackClass_onTick = env->GetMethodID(callbackClass, "onTick", "()V");
    g_ctx.callbackClass = callbackClass;
    g_ctx.callbackClass_onTick = callbackClass_onTick;
}

extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_jnitest_Test_unInit(JNIEnv *env, jclass clazz) {


}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_jnitest_Test_start(JNIEnv *env, jclass clazz) {

}
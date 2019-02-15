#include <jni.h>
#include <string>
#include "log/log.h"
#include <pthread.h>

void *tickThread(void *arg);

const char *TAG = "happy";

typedef struct global_context {
    JavaVM *javaVm;
    jclass callbackClass;
    jobject callbackObj;
    jmethodID callbackClass_onTick;
    pthread_mutex_t *lock;
} global_context;

global_context g_ctx;

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
    g_ctx.callbackClass = static_cast<jclass>(env->NewGlobalRef(callbackClass));
    g_ctx.callbackObj = env->NewGlobalRef(callback);
    g_ctx.callbackClass_onTick = callbackClass_onTick;

}

extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_jnitest_Test_unInit(JNIEnv *env, jclass clazz) {


}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_jnitest_Test_start(JNIEnv *env, jclass clazz) {
    pthread_mutex_init(g_ctx.lock, NULL);
    pthread_t *thread;
    pthread_create(thread, NULL, tickThread, NULL);

}

void *tickThread(void *arg) {
    JNIEnv *env;
    g_ctx.javaVm->GetEnv(g_ctx.javaVm,(void**)&env, JNI_VERSION_1_6);
    ->CallVoidMethod(g_ctx.callbackObj, g_ctx.callbackClass_onTick);
}


extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_jnitest_Test_stop(JNIEnv *env, jclass clazz) {

}
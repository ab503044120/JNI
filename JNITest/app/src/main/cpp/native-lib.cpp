#include <jni.h>
#include <string>
#include "log/log.h"
#include <pthread.h>
#include <cstring>
#include <unistd.h>

void *tickThread(void *arg);

const char *TAG = "happy";

typedef struct global_context {
    JavaVM *javaVm;
    jclass callbackClass;
    jobject callbackObj;
    jmethodID callbackClass_onTick;
    pthread_mutex_t lock;
    pthread_t *thread;
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
    pthread_mutex_init(&g_ctx.lock, NULL);
    pthread_t thread;
    pthread_create(&thread, NULL, tickThread, NULL);
    g_ctx.thread = &thread;
    return;
}

void *tickThread(void *arg) {
    JNIEnv *env = NULL;
    g_ctx.javaVm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    g_ctx.javaVm->AttachCurrentThread(&env, NULL);
    while (true) {
        env->CallVoidMethod(g_ctx.callbackObj, g_ctx.callbackClass_onTick);
        sleep(1);
    }
    g_ctx.javaVm->DetachCurrentThread();
    LOGV(TAG, "thread stop");
    return 0;
}


extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_jnitest_Test_stop(JNIEnv *env, jclass clazz) {
    LOGV(TAG, "stop");
}




extern "C"
JNIEXPORT jstring JNICALL
Java_org_huihui_jnitest_Test_handleString(JNIEnv *env, jclass type, jstring j_str) {
//  const char *s = env->GetStringUTFChars(j_str, 0);
//  env->ReleaseStringUTFChars(j_str, s);

//    //默认是unicode
//    int strLen = env->GetStringLength(j_str);
//    jchar c_string[1024];
//    LOGV(TAG,"%d",strLen);
//    env->GetStringRegion(j_str, 0, strLen, c_string);
//    return env->NewString(c_string, strLen - 1);


    //utf-8
    int strLen = env->GetStringUTFLength(j_str);
    char c_string[1024];
    LOGV(TAG, "%d", strLen);
    env->GetStringUTFRegion(j_str, 0, strLen-1, c_string);
    return env->NewStringUTF(c_string);

//    jsize len = env->GetStringLength(j_str);  // 获取unicode字符串的长度
//    printf("str_len:%d\n",len);
//    char buff[128] = "hello ";
//    char* pBuff = buff + 6;
//    // 将JVM中的字符串以utf-8编码拷入C缓冲区,该函数内部不会分配内存空间
//    env->GetStringUTFRegion(j_str,0,len-1,pBuff);
//    return env->NewStringUTF(buff);
}
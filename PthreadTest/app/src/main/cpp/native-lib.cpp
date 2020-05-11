#include <jni.h>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include "androidUtils.h"

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
#if __ANDROID_API__ >= 21
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "haha%d", __ANDROID_API__);
#else
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "haha%d", __ANDROID_API__);
#endif
    return JNI_VERSION_1_4;
}

extern "C" JNIEXPORT jstring JNICALL
Java_org_huihui_pthread_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

static void thread_cancel_signal_handler(int sig_num) {
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "thread_cancel_signal_handler");
    if (sig_num == SIGUSR2) {
        pthread_exit(0);
    }
}

/* This function can be called in the place of pthread_setcancelstate() and setcanceltype
*/
/* Note it must be called for cancelable threads */
int thread_cancelable() {
    struct sigaction action{};
    memset(&action, 0, sizeof(action));
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    action.sa_handler = &thread_cancel_signal_handler;

    return sigaction(SIGUSR2, &action, NULL);
}

/* Substitute for pthread_cancel */
static int pthread_cancel(pthread_t thread) {
    //SIGUSR1不知道为什么不行
    return pthread_kill(thread, SIGUSR2);
}

void clean(void *arg) {
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "clean");
}

void *run(void *arg) {
//    int state;
//    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &state);
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "thread_cancelable%d", thread_cancelable());
    pthread_cleanup_push(clean, NULL);
        while (true) {
            __android_log_print(ANDROID_LOG_ERROR, "CLog", "haha");
            sleep(1);
        }
            pthread_cleanup_pop(0);
    return 0;
}

pthread_t pthread;

extern "C" JNIEXPORT void JNICALL
Java_org_huihui_pthread_MainActivity_startPthread(
        JNIEnv *env,
        jobject /* this */) {
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "start");
    pthread_create(&pthread, nullptr, run, nullptr);
    pthread_detach(pthread);
}
extern "C" JNIEXPORT void JNICALL
Java_org_huihui_pthread_MainActivity_killPthread(
        JNIEnv *env,
        jobject /* this */) {
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "kill%d", pthread_cancel(pthread));
//    __android_log_print(ANDROID_LOG_ERROR, "CLog", "pthread_join%d", pthread_join(pthread, nullptr));
}

void *t1f(void *arg) {
    //线程安全 errno
    __set_errno(2);
    sleep(2);
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "t1 error%d", errno);
    __set_errno(1);
    return 0;
}

void *t2f(void *arg) {
    sleep(1);
    __set_errno(2);
    sleep(2);
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "t2 error%d", errno);
    return 0;
}

extern "C" JNIEXPORT void JNICALL
Java_org_huihui_pthread_MainActivity_pthreadErrno(
        JNIEnv *env,
        jobject /* this */) {
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, nullptr, t1f, nullptr);
    pthread_create(&t2, nullptr, t2f, nullptr);
}
extern "C" JNIEXPORT void JNICALL
Java_org_huihui_pthread_MainActivity_pthreadMutexUnlock(
        JNIEnv *env,
        jobject /* this */) {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "lock%d", pthread_mutex_lock(&mutex));
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "unlock%d", pthread_mutex_unlock(&mutex));
    __android_log_print(ANDROID_LOG_ERROR, "CLog", "unlock%d", pthread_mutex_unlock(&mutex));
    pthread_mutex_destroy(&mutex);
}




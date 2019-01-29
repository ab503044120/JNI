#include <jni.h>
#include <string>
#include <android/log.h>
#include <vector>
#include <deque>
#include <list>
#include "test/Animal.h"
#include "test/Dog.h"
#include "test/Hasky.h"
#include "test/Pet.h"

class base
{
public:
    void a()
    {
        __android_log_print(ANDROID_LOG_ERROR,"dog","base a\n");
        b(1);
    };
    virtual void b(int x)
    {
        __android_log_print(ANDROID_LOG_ERROR,"dog","base b %d \n",x);
    };
};

class ext:public base
{
    virtual void b(int x)
    {
        __android_log_print(ANDROID_LOG_ERROR,"dog","ext b %d \n",x);
    };

};


extern "C" JNIEXPORT jstring JNICALL
Java_org_huihui_cpptest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    Hasky hasky("汪汪");
    hasky.Pet::call();
    hasky.haha();

    Animal &a = hasky;
    a.haha();

    ext ext_i;
    base base_i;
    base*  base_p;
    base&  base_r=ext_i;
    base_p=&ext_i;
    base_p->a();
    base_r.a();
    base_i.a();

//    std::vector<string> vector1{"1", "2", "3"};
//    vector1.insert(vector1.begin() += 1, "a");
//    vector1.push_back("1");
//    std::deque deque1;
//    std::list list1;
//    list1.insert(++list1.begin(), "b");
    return env->NewStringUTF(hello.c_str());
}




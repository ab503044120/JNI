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

class base {
public:

    base(string &a) {

    }

    void a() {
        __android_log_print(ANDROID_LOG_ERROR, "dog", "base a\n");
        b(1);
    };

    virtual void b(int x) {
        __android_log_print(ANDROID_LOG_ERROR, "dog", "base b %d \n", x);
    };
};


class ext : public base {
public:
    int bbb;

    ext(string &a) : base(static_cast<std::string &>("aaa")), bbb(2) {}

private:
    virtual void b(int x) {
        __android_log_print(ANDROID_LOG_ERROR, "dog", "ext b %d \n", x);
    };

};

int &return0() {

    static int a = 0;
    return a;
}

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

    int &a0 = return0();

//    string aa = "a";
//    string &bb = (string &) "a";
//    string *cc = &((string *) "aaa");
//    ext ext2(bb);
//    ext *ext1 = &ext(bb);
//    ext *ext1 = &ext2;
//    ext *ext3 = &(*ext1);
//  ext ext_i(*cc);
//    base base_i(bb);
//    base *base_p;
//  base &base_r = ext_i;
//  base_p = &ext_i;
//  base_p->a();
//  base_r.a();
//  base_i.a();

//    std::vector<string> vector1{"1", "2", "3"};
//    vector1.insert(vector1.begin() += 1, "a");
//    vector1.push_back("1");
//    std::deque deque1;
//    std::list list1;
//    list1.insert(++list1.begin(), "b");
    return env->NewStringUTF(hello.c_str());
}






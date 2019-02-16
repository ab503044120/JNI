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


class ext: public base {
 public:
  int bbb;

//    ext(string &a) : base(static_cast<std::string &>("aaa")), bbb(2) {}

 private:
 public:
  ext(string &a) : base(a) {}

 private:
  virtual void b(int x) {
    __android_log_print(ANDROID_LOG_ERROR, "dog", "ext b %d \n", x);
  };

};

int &return0() {

  static int a = 0;
  return a;
}


class Person {
 public:
  Person() {
    __android_log_print(ANDROID_LOG_ERROR, "dog", "no param constructor!");
    mAge = 0;
  }
  //有参构造函数
  Person(int age) {
    __android_log_print(ANDROID_LOG_ERROR, "dog", "1 param constructor!");
    mAge = age;
  }
  //拷贝构造函数(复制构造函数) 使用另一个对象初始化本对象
  Person(const Person &person) {
    __android_log_print(ANDROID_LOG_ERROR, "dog", "copy constructor!");
    mAge = person.mAge;
  }
  //打印年龄
  void PrintPerson() {
    __android_log_print(ANDROID_LOG_ERROR, "dog", "Age:");
  }
 private:
  int mAge;
};
//1. 无参构造调用方式
void test01() {

  //调用无参构造函数
  Person person1;
  person1.PrintPerson();

  //无参构造函数错误调用方式
  //Person person2();
  //person2.PrintPerson();
}
//2. 调用有参构造函数
void test02() {

  //第一种 括号法，最常用
  Person person01(100);
  person01.PrintPerson();

  //调用拷贝构造函数
  Person person02(person01);
  person02.PrintPerson();

  //第二种 匿名对象(显示调用构造函数)
  Person(200); //匿名对象，没有名字的对象

  Person person03 = Person(300);
  person03.PrintPerson();

  //注意: 使用匿名对象初始化判断调用哪一个构造函数，要看匿名对象的参数类型
  Person person06(Person(400)); //等价于 Person person06 = Person(400);
  person06.PrintPerson();

  //第三种 =号法 隐式转换
  Person person04 = 100; //Person person04 =  Person(100)
  person04.PrintPerson();

  //调用拷贝构造
  Person person05 = person04; //Person person05 =  Person(person04)
  person05.PrintPerson();
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
    string &bb = new string("aaa");


//  string &bb = new string("aaa");

  string *cc = new string("aaa");

  string &dd = *cc;

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

  test02();

    test02();
    jbyteArray bytes = env->NewByteArray(10);
    return env->NewStringUTF(hello.c_str());
}






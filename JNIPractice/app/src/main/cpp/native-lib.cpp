#include <jni.h>
#include <string>
#include "native-lib.h"

jstring Java_org_huihui_jnipractice_MainActivity_stringFromJNI(
    JNIEnv *env,
    jobject instance) {
  std::string hello = "Hello from C++";

  char *string;
  getString((char **) &string);
  hello = string;
  return env->NewStringUTF(hello.c_str());
}

char *getString(char **string) {
  *string = "xxx";
  return *string;
}


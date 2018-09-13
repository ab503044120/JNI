LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#  c++98 c++03
LOCAL_CPPFLAGS := -std=c++98 -fexceptions -frtti
# c89 c90
LOCAL_CFLAGS := -std=c89
LOCAL_MODULE    := native-lib
LOCAL_SRC_FILES :=  hello.c\
                    native-lib.cpp

include $(BUILD_SHARED_LIBRARY)

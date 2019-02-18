package org.huihui.jnitest;

public class Test {
    static {
        System.loadLibrary("native-lib");
    }

    public static native void init(Callback callback);

    public static native void unInit();

    public static native void  start();

    public static native void  stop();

    public static native String handleString(String s);

}

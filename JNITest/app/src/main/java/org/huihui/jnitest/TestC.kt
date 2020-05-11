package org.huihui.jnitest

class TestC {
    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("testc")
        }
    }
    external fun envTest()
}
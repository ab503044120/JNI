package org.huihui.pthread

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        btn1.setOnClickListener {
            startPthread()
        }
        btn2.setOnClickListener {
            killPthread()
        }
        btn3.setOnClickListener {
            pthreadErrno()
        }
        btn4.setOnClickListener {
            pthreadMutexUnlock()
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun startPthread()

    external fun killPthread()

    external fun pthreadErrno()

    external fun pthreadMutexUnlock()

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}

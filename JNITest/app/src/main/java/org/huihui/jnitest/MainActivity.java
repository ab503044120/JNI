package org.huihui.jnitest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements Callback {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Test.init(this);
        ((TextView) findViewById(R.id.sample_text))
//                .setText(Test.handleString("你好"));
                .setText(Test.handleString("hello"));
        Test.start();
    }


    @Override
    protected void onPause() {
        super.onPause();
        Test.stop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Test.unInit();
    }

    @Override
    public void onTick() {
        Log.e("happy", "onTick: ");
    }
}

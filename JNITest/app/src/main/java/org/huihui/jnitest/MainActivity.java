package org.huihui.jnitest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements Callback {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Test.init(this);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Test.unInit();
    }

    @Override
    public void onTick() {

    }
}

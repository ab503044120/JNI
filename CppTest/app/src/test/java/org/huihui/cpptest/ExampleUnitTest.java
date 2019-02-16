package org.huihui.cpptest;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        assertEquals(4, 2 + 2);
    }

    class Parent {
        public Parent() {
            print();
        }

        public void print() {
            System.out.println("父类");
        }
    }

    class Child extends Parent {
        @Override
        public void print() {
            System.out.println("子类");
        }
    }

    @Test
    public void testExtends() {
        new Child();
    }
}
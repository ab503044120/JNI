package com.westwhale.csocket;

public class CSocket {
    static {
        System.loadLibrary("csocket");
    }

    private long handle_t;

    private CSocket(int port) {
        handle_t = init(port);
    }

    public static CSocket getInstance(int port) {
        return new CSocket(port);
    }


    public void release() {
        release(handle_t);
        handle_t = -1;
    }

    public void start() {
        start(handle_t);
    }

    public void stop() {
        stop(handle_t);
    }

    private native void start(long handle_t);

    private native void stop(long handle_t);


    private native long init(int port);


    private native void release(long handle_t);
}

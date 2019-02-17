#include <jni.h>
#include <string>
#include <malloc.h>
#include <sys/socket.h>
#include <linux/in.h>
#include <cstring>
#include <endian.h>
#include "log/log.h"
#include <arpa/inet.h>
#include <unistd.h>
typedef struct {
  int port;
  pthread_t *thread_t;
  int socket_handle_t;
  pthread_mutex_t *mutex;
  bool thread_run;
} csocket_t;


void *socketThread(void *arg) {
  csocket_t *csocket = reinterpret_cast<csocket_t *>(arg);
  int family = AF_INET;// AF_INET6 : AF_INET;
  int type = SOCK_STREAM; //SOCK_DGRAM : SOCK_STREAM;
  int proto = IPPROTO_TCP;//IPPROTO_UDP : IPPROTO_TCP;
  int socket_t = socket(family, type, 0);
  csocket->socket_handle_t = socket_t;
  sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = PF_INET;

  // Bind to all addresses
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  // Convert port to network byte order
  address.sin_port = htons(csocket->port);

  if (-1 == bind(socket_t, (struct sockaddr *) &address, sizeof(address))) {

  }
  listen(socket_t, 256);
  LOGV("happy", "socket开启");
  struct sockaddr_in address1;
  socklen_t addressLength = sizeof(address1);
  int clientSocket = accept(socket_t, (struct sockaddr *) &address1, &addressLength);
  char *saddr = inet_ntoa(address1.sin_addr);
  LOGV("happy", "端口号:%s", saddr);
  return 0;
}

void *socketSelectThread(void *arg) {
  csocket_t *csocket = reinterpret_cast<csocket_t *>(arg);
  int family = AF_INET;// AF_INET6 : AF_INET;
  int type = SOCK_STREAM; //SOCK_DGRAM : SOCK_STREAM;
  int proto = IPPROTO_TCP;//IPPROTO_UDP : IPPROTO_TCP;
  int socket_t = socket(family, type, 0);
  csocket->socket_handle_t = socket_t;
  sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = PF_INET;

  // Bind to all addresses
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  // Convert port to network byte order
  address.sin_port = htons(csocket->port);

  if (-1 == bind(socket_t, (struct sockaddr *) &address, sizeof(address))) {

  }
  listen(socket_t, 256);


  fd_set socket_fd_set ,copy_socket_fd_set;
  FD_ZERO(&socket_fd_set);
  FD_SET(socket_t, &socket_fd_set);

  pthread_mutex_lock(csocket->mutex);
  csocket->thread_run = true;
  pthread_mutex_unlock(csocket->mutex);

  LOGV("happy", "socket开启");
  int fd_max = socket_t;
  struct timeval timeval1;
  timeval1.tv_sec = 5;
  while (true) {
    copy_socket_fd_set = socket_fd_set;
    pthread_mutex_lock(csocket->mutex);
    if (!csocket->thread_run) {
      break;
    }
    pthread_mutex_unlock(csocket->mutex);
    LOGV("happy", "start select fd_max:%d", fd_max);
    int ret = select(fd_max + 1, &copy_socket_fd_set, 0, 0, 0);
    LOGV("happy", "select");
    if (ret < 0) {
      LOGV("happy", "错误");
      break;
    }
    char buf[1024];
    for (int i = 0; i < fd_max + 1; ++i) {
      if (FD_ISSET(i, &copy_socket_fd_set)) {
        LOGV("happy", "有事件:%d", i);
        if (i == socket_t) {
          struct sockaddr_in address1;
          socklen_t addressLength = sizeof(address1);
          int clientSocket = accept(socket_t, (struct sockaddr *) &address1, &addressLength);
          char *saddr = inet_ntoa(address1.sin_addr);
          LOGV("happy", "端口号:%s", saddr);
          if (fd_max < clientSocket) {
            fd_max = clientSocket;
            LOGV("happy", "fd_max:%d", fd_max);
          }
          FD_SET(clientSocket, &socket_fd_set);
        } else {
          int ret = recv(i, buf, 1024, 0);
          if (ret == 0) {
            FD_CLR(i, &socket_fd_set);
            close(i);
            LOGV("happy", "断开连接");
          } else {
          LOGV("happy", "收到消息");
          char msg[ret + 1];
          memcpy(msg, buf, ret);
          msg[ret] = '\0';
          LOGV("happy", "消息:%s", msg);
        }
      }

    }
  }

}
LOGV("happy", "已经退出");
return 0;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_westwhale_csocket_CSocket_release(JNIEnv *env, jobject instance, jlong handle_t) {
  csocket_t *csocket = reinterpret_cast<csocket_t *>(handle_t);
  delete csocket;
}
extern "C"
JNIEXPORT jlong JNICALL
Java_com_westwhale_csocket_CSocket_init(JNIEnv *env, jobject instance, jint port) {
  csocket_t *csocket = new csocket_t;
  csocket->port = port;
  csocket->thread_run = false;
  return reinterpret_cast<jlong>(csocket);
}extern "C"
JNIEXPORT void JNICALL
Java_com_westwhale_csocket_CSocket_start(JNIEnv *env, jobject instance, jlong handle_t) {
  csocket_t *csocket = reinterpret_cast<csocket_t *>(handle_t);
  pthread_mutex_t *mutex = new pthread_mutex_t;
  pthread_mutex_init(&(*mutex), NULL);
  csocket->mutex = mutex;
  pthread_t pthread;
  pthread_attr_t *attr = new pthread_attr_t;
  pthread_attr_init(attr);
  pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);
  pthread_create(&pthread, attr, socketSelectThread, csocket);
  pthread_attr_destroy(attr);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_westwhale_csocket_CSocket_stop(JNIEnv *env, jobject instance, jlong handle_t) {

}


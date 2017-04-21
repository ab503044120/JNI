# centos 7.0下搭建rtmp

## 下载安装nginx

### 准备工作

> 安装第三方库

```
$   yum install gcc-c++
$   yum install pcre pcre-devel
$   yum install zlib zlib-devel
$   yum install openssl openssl--devel
```
>下载安装nginx和nginx-rtmp-module

首先进入/usr/local目录
```
$   cd /usr/local
```
从官网下载nginx
```
$   wget http://nginx.org/download/nginx-1.7.4.tar.gz
```
解压nginx
```
$   tar -zxvf nginx-1.7.4.tar.gz
```
下载nginx-rtmp-module(在/usr/local目录)
```
git clone https://github.com/arut/nginx-rtmp-module.git
```
进入nginx-1.7.4目录
```
$   cd  nginx-1.7.4
```
接下来安装，使用--prefix参数指定nginx安装的目录并添加nginx-rtmp-module,make、make install安装
```
$   ./configure  --add-module=../nginx-rtmp-module
    #默认安装在/usr/local/nginx
$   make
$   make install
```
接下来配置nginx.conf在http上添加如下配置
```
rtmp {

    server {

        listen 1935;  #监听的端口

        chunk_size 4000;


        application hls {  #rtmp推流请求路径
            live on;
            hls on;
            hls_path /usr/local/share/nginx/html/hls;
            hls_fragment 5s;
        }
    }
}
```
根据现在的安装目录开启nginx指令如下
```
#开启
/usr/local/nginx/sbin/nginx
#关闭
/usr/local/nginx/sbin/nginx -s stop
#重载
nginx -s reload
```
>安装推流和拉流的客户端

如下客户端:
[AnyRTC](https://github.com/AnyRTC/AnyRTC-RTMP "AnyRTC")(TMP 推流器，RTMP(HLS)秒开播放器，跨平台（Win,IOS,Android)

windows下测试可用如下工具
[nginx-rtmp-win32](https://github.com/illuspas/nginx-rtmp-win32 "nginx-rtmp-win32")

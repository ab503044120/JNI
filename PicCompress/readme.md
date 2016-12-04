## 图片压缩算法
NativeUtil.java

###1. 质量压缩
 设置bitmap options属性，降低图片的质量，像素不会减少
 第一个参数为需要压缩的bitmap图片对象，第二个参数为压缩后图片保存的位置
 设置options 属性0-100，来实现压缩
> public static void compressImageToFile(Bitmap bmp,File file)

###2. 尺寸压缩
 通过缩放图片像素来减少图片占用内存大小
 >public static void compressBitmapToFile(Bitmap bmp, File file)
 
 ###3. 采样率压缩
 设置图片的采样率，降低图片像素
 > public static void compressBitmap(String filePath, File file)
 
 ###4. 利用libjpg哈夫曼编码压缩图片
 >  public static native String compressBitmap(Bitmap bit, int w, int h, int quality, byte[] fileNameBytes,
  	                                                boolean optimize);

**注意此工程只能用as2.2的cmake编译**

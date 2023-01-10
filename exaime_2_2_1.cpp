/*
2.1 读取 RM.png 图片
2.2 使用 cv::namedWindow() 创建窗口，命名为：“hsv调节”
2.3 使用 cv::createTrackbar() 创建六个滑动条，分别为：
    h-max h-min s-max s-min v-max v-min
2.4 显示原图窗口和HSV窗口
*/
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int i = 0;//滑动条初始值

void text(int,void*){
    Mat src = imread("D:\\OpenCV4.1.1\\img\\RM.png");
//    vector<Mat> channels;
//    split(src,channels);
    imshow("hsv调节",src);
}

int main()
    {
    //2.1 读取 RM.png 图片
    Mat src = imread("D:\\OpenCV4.1.1\\img\\RM.png");

    if (src.empty())
    {
        printf("图片加载失败\n");
        system("pause");
        return 0;
    }

    //2.2 使用 cv::namedWindow() 创建窗口，命名为：“hsv调节”
    namedWindow("hsv调节",WINDOW_AUTOSIZE);

    //2.3 使用 cv::createTrackbar() 创建六个滑动条，分别为：
    //    h-max h-min s-max s-min v-max v-min
    createTrackbar("h-max","hsv调节",&i,180,text);
    createTrackbar("h-min","hsv调节",&i,180,text);

    createTrackbar("s-max","hsv调节",&i,255,text);
    createTrackbar("s-min","hsv调节",&i,255,text);

    createTrackbar("v-max","hsv调节",&i,255,text);
    createTrackbar("v-min","hsv调节",&i,255,text);

    text(0,0);

    //2.4 显示原图窗口和HSV窗口
    imshow("image",src);

    waitKey(0);
    return 0;
}

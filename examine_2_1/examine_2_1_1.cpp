/*
1.1 读取 RM.png 文件
要求：
      1.1.1 转换颜色空间为GRAY
      1.1.2 添加高斯滤波，滤波器尺寸 (3 * 3）
      1.1.3 对得到的转换图二值化并显示
*/
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    //1.1.1 转换颜色空间为GRAY
    Mat img = imread("D:\\OpenCV4.1.1\\img\\RM.png",1);
    cvtColor(img,img,COLOR_BGR2GRAY);

    //1.1.2 添加高斯滤波，滤波器尺寸 (3 * 3）
    GaussianBlur(img,img,Size(3,3),3,0);

    //1.1.3 对得到的转换图二值化并显示
    threshold(img,img,80,255,THRESH_BINARY);

    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    //imshow-在指定的窗口中显示图像
    imshow("image", img);
    //waitKey(0)-将无限显示窗口
    waitKey(0);
    destroyAllWindows();
    return 0;
}


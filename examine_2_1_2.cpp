#include <opencv2/opencv.hpp>
#include <iostream>
#include<cstring>
/*
1.2 读取 preview.mp4 文件
要求： 1.2.1 显示视频
      1.2.2 在视频左上角显示视频中图像帧率，字体颜色为绿色
*/
using namespace std;
using namespace cv;

int main(){
    //1.2.1 显示视频
    VideoCapture cap("D:\\OpenCV4.1.1\\video\\preview.mp4");
    Mat img;

    while(true){
        cap.read(img);
        //获取视频帧率
        double fps=cap.get(CAP_PROP_FPS);
        ostringstream str;
        str<<"fps:"<<fps;
    //1.2.2 在视频左上角显示视频中图像帧率，字体颜色为绿色
        putText(img,str.str(),Point(0,20),FONT_HERSHEY_PLAIN,1.5,Scalar(0,255,0),2,LINE_AA);
        imshow("image",img);
        waitKey(1);
    }
    destroyAllWindows();
}

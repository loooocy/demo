/*
3.1 读取 board.jpg 图片
3.2 图像预处理
3.3 霍夫变换，识别直线并显示
*/
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    //3.1 读取 board.jpg 图片
    Mat img = imread("D:\\OpenCV4.1.1\\img\\board.jpg",1);

    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    //3.2 图像预处理
    cvtColor(img,img,COLOR_BGR2GRAY);
    GaussianBlur(img,img,Size(3,3),3,0);
    Mat dst;
    Canny(img, dst, 50, 200, 3);

    //3.3 霍夫变换，识别直线并显示
    vector<Vec2f> lines;
    HoughLines(dst,lines,1,CV_PI/180,200);

    for (size_t i = 0; i < lines.size(); i++)
        {
            float rho = lines[i][0], theta = lines[i][1];    //距离精度、角度精度
            Point pt1, pt2;                                  //定义两点p1和p2
            double a = cos(theta), b = sin(theta);           //a:cos  b:sin
            //以x0和y0作为参照点，求出(x1, y1)和(x2, y2)
            double x0 = a * rho, y0 = b * rho;
            pt1.x = cvRound(x0 - 1000 * (-b));
            pt1.y = cvRound(y0 - 1000 * (a));
            pt2.x = cvRound(x0 + 1000 * (-b));
            pt2.y = cvRound(y0 + 1000 * (a));
            line(dst, pt1, pt2, Scalar(200, 0, 0), 3);       //绘制直线
        }

    imshow("image", dst);

    waitKey(0);
    destroyAllWindows();
    return 0;
}


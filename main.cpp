#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>

/*
 int main(){
    cv::Mat image,logo;
    image=cv::imread("/home/limingwu/Pictures/1.jpeg");
    logo=cv::imread("/home/limingwu/Pictures/5.jpg");

    cv::Mat imageROI(image,cv::Rect(image.cols-logo.cols,
                                    image.rows-logo.rows,logo.cols,logo.rows));

    cv::Mat gray_mat;
    cvtColor(logo, gray_mat, CV_BGR2GRAY);

    cv::imwrite("/home/limingwu/Pictures/gray_logo.jpeg",gray_mat);
    cv::Mat grayMast=cv::imread("/home/limingwu/Pictures/gray_logo.jpet");

    cv::Mat mask(grayMast);

    logo.copyTo(imageROI,mask);
    std::cout<<"The cols and rows of image is "<<image.cols<<" "<<image.rows<<std::endl;
    cv::namedWindow("ImageRIO");
    cv::imshow("ImageRIO",image);
    cv::imwrite("/home/limingwu/Pictures/logo.jpeg",image);
    cv::waitKey(0);

    return 0;
}
 */
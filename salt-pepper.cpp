//
// Created by limingwu on 16-11-9.
//

/*#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv.h>

//add salt-and-pepper noise to the given pictures.
void salt(cv::Mat image,int n){
    int i,j;
    for(int k=0;k<n;k++){
        i=std::rand()%image.cols;
        j=std::rand()%image.rows;

        if(image.type()==CV_8UC1){
            image.at<uchar>(j,i)=255;
        }else if(image.type()==CV_8UC3){
            image.at<cv::Vec3b>(j,i)[0]=255;
            image.at<cv::Vec3b>(j,i)[1]=255;
            image.at<cv::Vec3b>(j,i)[2]=255;
        }
    }
}

//reduce the amounts of colors .
void colorReduce(cv::Mat image,int div=64){
    int nl=image.rows;
    int nc=image.cols*image.channels();

    for(int i=0;i<nl;i++){
        uchar* data=image.ptr<uchar>(i);
        for(int j=0;j<nc;j++){
            data[j]=data[j]/div*div+div/2;
        }
    }
}

void colorReduce2(cv::Mat &image,int div=64){
    //cv::Mat_<cv::Vec3b>::iterator it=image.begin<cv::Vec3b>();
    //cv::Mat_<cv::Vec3b>::iterator itend=image.end<cv::Vec3b>();

    cv::MatIterator_<cv::Vec3b> it=image.begin<cv::Vec3b>();
    cv::MatIterator_<cv::Vec3b> itend=image.end<cv::Vec3b>();
   for( ; it != itend; it++){
        (*it)[0]=(*it)[0]/div*div+div/2;
       (*it)[1]=(*it)[1]/div*div+div/2;
       (*it)[2]=(*it)[2]/div*div+div/2;

   }
}

//sharpen the images.
void sharpen(const cv::Mat &image,cv::Mat &result){
    result.create(image.size(),image.type());
    int nchannels=image.channels();

    for(int j=1;j<image.rows-1;j++){
        const uchar* previous=image.ptr<const uchar>(j-1);
        const uchar* current=image.ptr<const uchar>(j);
        const uchar* next=image.ptr<const uchar>(j+1);
        uchar* output=result.ptr<uchar>(j);

        for(int i=nchannels;i<(image.cols-1)*nchannels;i++){
            *output++=cv::saturate_cast<uchar>(5*current[i]-current[i-nchannels]-
            current[i+nchannels]-previous[i]-next[i]);
        }
    }

    result.row(0).setTo(cv::Scalar(0));
    result.row(result.rows-1).setTo(cv::Scalar(0));
    result.col(0).setTo(cv::Scalar(0));
    result.col(result.cols-1).setTo(cv::Scalar(0));
}

int main(){

    cv::Mat image=cv::imread("/home/limingwu/Pictures/1.jpeg");
    cv::Mat result;
    //salt(image,3000);
    //colorReduce2(image,64);
    sharpen(image,result);

    cv::namedWindow("Image");
    cv::imshow("Image",result);
    //cv::imwrite("/home/limingwu/Pictures/saltAdded.jpeg",image);
    //cv::imwrite("/home/limingwu/Pictures/colorReduced.jpeg",image);
    //cv::imwrite("/home/limingwu/Pictures/colorReduced3.jpeg",image);
    cv::imwrite("/home/limingwu/Pictures/sharpen.jpeg",result);

    cv::waitKey(0);

    return 0;
}
*/
#include <dirent.h>
#include <stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#define TWO_PI 6.2831853071795864769252866

using namespace std;
using namespace cv;

vector <string> findfile(string path);
void salt(cv::Mat image,int n);
string newPath(std::string basePath, int i);
double generateGaussianNoise();
void AddGaussianNoise(Mat& image);

int main(int argc, char *argv[])
{
    /*if(argc!=2)
    {
        std::cout<<"usage: command SourceDirectoryPath DestinationDirectoryPath"<<std::endl;
        return 1;
    }*/
    //std::string SourcePath=argv[1];
    //std::string DestinationPath=argv[2];
    vector<string> Filename = findfile("/home/limingwu/Pictures/");
   // vector<string> Filename = findfile(SourcePath);

    for (int i = 0;i<Filename.size();i++) {
        cv::Mat image=cv::imread(Filename[i]);
        //salt(image,3000);
        AddGaussianNoise(image);

        std::string basePath="/home/limingwu/Documents/ResultImages2/";
        //std::string basePath=DestinationPath;

        std::string storePath=newPath(basePath,i) ;
        cv::imwrite(storePath,image);

        cout << "Have done "<<i<<" pictures ..."<< endl;
    }

    return 0;
}

vector <string> findfile(string path)
{
    DIR *dp;
    struct dirent *dirp;

    vector<std::string> filename;

    if( (dp=opendir(path.c_str()) )==NULL )
        perror("open dir error");

    while( (dirp=readdir(dp) )!=NULL ){
        if(strcmp(dirp->d_name,".")==0 || strcmp(dirp->d_name,"..")==0|| dirp->d_type == 10)    ///current dir OR parrent dir OR link
            continue;
        filename.push_back(path + string(dirp->d_name));
    }

    closedir(dp);

    return filename;
}

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

string newPath(std::string basePath, int i)
{
    stringstream s;
    std::string postfix=".jpeg";
    s << basePath << i<<postfix;
    return s.str();
}

double generateGaussianNoise()
{
    static bool hasSpare = false;
    static double rand1, rand2;

    if(hasSpare)
    {
        hasSpare = false;
        return sqrt(rand1) * sin(rand2);
    }

    hasSpare = true;

    rand1 = rand() / ((double) RAND_MAX);
    if(rand1 < 1e-100) rand1 = 1e-100;
    rand1 = -2 * log(rand1);
    rand2 = (rand() / ((double) RAND_MAX)) * TWO_PI;

    return sqrt(rand1) * cos(rand2);
}


void AddGaussianNoise(Mat& I)
{
    // accept only char type matrices
    CV_Assert(I.depth() != sizeof(uchar));

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if(I.isContinuous()){
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    for(i = 0; i < nRows; ++i){
        p = I.ptr<uchar>(i);
        for(j = 0; j < nCols; ++j){
            double val = p[j] + generateGaussianNoise() * 128;
            if(val < 0)
                val = 0;
            if(val > 255)
                val = 255;

            p[j] = (uchar)val;

        }
    }

}
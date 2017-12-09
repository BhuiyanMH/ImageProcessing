#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>

using namespace std;
using namespace cv;

int main ()
{

    Mat src, dst;
    src = imread("index.jpg", 1 );
    imshow("Original Image", src);

    vector<int> originalPixelValues;
    vector<string> compressedPixelValues;

    for( int i=0 ; i<100; i++)
    {
        for(int j = 0; j<100; j++)
        {
            originalPixelValues.push_back((int)src.at<uchar>(i,j));
        }
    }

    for(int i=0; i<256; i++)
    {
        //string s = string(itoa(i));

        std::string s = std::to_string(42);
        compressedPixelValues[i] = s;
    }



    //imshow( "Compressed Image", dst );
    waitKey(0);
    destroyWindow("window");
    return 0;
}

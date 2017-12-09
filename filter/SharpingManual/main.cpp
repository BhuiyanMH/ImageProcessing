#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

    Mat dst1, dst2, dst3;
    Mat img = imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    dst2 = imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    GaussianBlur( img, dst1, Size(3,3), 0, 0, BORDER_DEFAULT );

    int i, j, cnt, org, blr;

    for(i=0; i<512; i++)
    {
        for(j=0; j<512; j++)
        {
            org = (int)img.at<uchar>(i,j);
            blr = (int)dst1.at<uchar>(i,j);
            dst2.at<uchar>(i,j) = org + (org-blr);
        }
    }

    imshow("Original", img);
    imshow("Sharpen", dst2);
    waitKey(0);
    destroyWindow("Original");
    destroyWindow("Sharpen");

    return 0;
}


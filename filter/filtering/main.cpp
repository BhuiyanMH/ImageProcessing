#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int main ()
{

    Mat src, dst;

    Mat kernel;
    Point anchor;
    double delta;
    int ddepth;
    int kernel_size;

    int c;
    src = imread("index.jpg", 1 );
    imshow("Original Image", src);

    /// Initialize arguments for the filter
    anchor = Point( 0, 0 );
    delta = 0;
    ddepth = -1;

    kernel_size= 3;
    kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);

    /// Apply filter
    filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );

    imshow( "2D: Average Filtered Image", dst );
    waitKey(0);
    destroyWindow("window");
    return 0;
}

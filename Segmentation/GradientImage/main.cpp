#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;

int main()
{
    Mat src, dst;
    src = imread( "lena.jpg", 1);
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    imshow("Before Gradient ", src);

    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    Sobel( src, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );

    imshow( "grad x", abs_grad_x );


    Sobel( src, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_y, abs_grad_y );

    imshow( "grad y", abs_grad_y );


    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst );

    imshow( "Sobel", dst );
    waitKey(0);

}

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;

int main()
{
    Mat src, dst;
    src = imread( "lena.jpg", 1);


    imshow("Before Filtering ", src);

    // Gaussian smoothing
    GaussianBlur( src, dst, Size( 3,  3), 0, 0 );

    //show the blurred image with the text
    imshow( "Gaussian filter", dst );
    waitKey(0);

}

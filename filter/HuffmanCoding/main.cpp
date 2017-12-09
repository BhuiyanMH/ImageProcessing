#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {

	Mat img = imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst1, res, dst2, dst3;

    GaussianBlur( img, dst1, Size(3,3), 0, 0, BORDER_DEFAULT );
    subtract(img,dst1,res);

    int k=10;
    add(img, k*res, dst2);

	imshow("Original", img);
	imshow("Gaussian", dst1);
	imshow("Unsharp", dst2);


	waitKey(0);
	destroyWindow("Original");
    destroyWindow("Gaussian");
    destroyWindow("Unsharp");

    return 0;
}


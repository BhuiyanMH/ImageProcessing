#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat img = imread("test.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    cout << "Number of Rows: " <<img.rows <<endl;
    cout << "Number of Columns: "<<img.cols << endl;

   //cout << "M = "<< endl << " "  << img << endl << endl;

    for(int i=0; i<10; i++)
    {
       for(int j =0; j<10; j++){

            cout << (int)img.at<uchar>(i,j) <<"\t";
        }
        cout <<endl;
    }

    namedWindow("window", WINDOW_AUTOSIZE);
    imshow("window", img);
    waitKey(0);
    destroyWindow("window");
    return 0;
}

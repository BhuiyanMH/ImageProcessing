#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main()
{

    int dimX, dimY, temp;
    cout << "Enter the dimension of the image ( M X N ): ";
    cin >> dimX >> dimY;

    Mat original =  Mat(dimX, dimY, CV_8UC3);
    Mat compressed = Mat(dimX, dimY, CV_8UC3);


    cout << "\nOriginal Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {

            cout << "Enter the value: x"<< i <<", y"<<j <<": ";
            cin >> temp;
            original.at<uchar>(i,j) = temp;
        }
    }

    cout << "\nCompressed Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {
            cout << "Enter the value: x"<< i <<", y"<<j << ": ";
            cin >> temp;
            compressed.at<uchar>(i,j) = temp;
        }
    }


    cout << "\nOriginal Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {
            cout << (int)original.at<uchar>(i,j) << "\t";

        }
        cout << "\n";
    }

    cout << "\nCompressed Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {

            cout << (int)compressed.at<uchar>(i,j) << "\t";

        }
        cout << "\n";
    }

    double numerator = 0, denominator =0;

    int x , y;
    for(int i=0; i<dimX; i++)
        for(int j=0; j<dimY; j++)
        {

            x = (int)original.at<uchar>(i,j);
            y =  (int)compressed.at<uchar>(i,j);
            numerator += pow(y, 2);
            denominator += pow((y-x), 2);

        }

    cout << "\nSNR = " << (numerator/denominator) << endl;

    return 0;
}

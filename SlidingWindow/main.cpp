#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int dim, temp, windowDim;
Mat original;

void printWindow(int i, int j);

int main()
{
    cout << "Enter the dimension of the image ( N X N ): ";
    cin >> dim;
    windowDim = dim-2;
    original =  Mat(dim+1, dim+1, CV_8UC3);

    cout << "\nOriginal Image:" << endl;
    for(int i = 1; i<=dim; i++)
    {
        for(int j=1; j<=dim; j++)
        {
            cin >> temp;
            original.at<uchar>(i,j) = temp;
        }
    }

    cout << "\nWindows:" << endl;

    for(int row = 1; row<=3; row++)
    {
        for(int col=1; col<=3; col++)
        {
            printWindow(row, col);

            cout<< "\n";
        }


    }

    return 0;
}

void printWindow(int i, int j)
{
    for(int r = i; r<=i+windowDim-1; r++)
    {
        for(int c = j; c<=j+windowDim-1; c++)
        {
            cout << (int)original.at<uchar>(r,c) << " ";
        }
        cout <<"\n";
    }

}

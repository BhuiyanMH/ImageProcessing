#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int dimX, dimY;
    cout << "Enter the dimension of the image ( M X N ): ";
    cin >> dimX >> dimY;

    int original[dimX][dimY], compressed[dimX][dimY];

    cout << "\nOriginal Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {

            cout << "Enter the value: x"<< i <<", y"<<j <<": ";
            cin >> original[i][j];
        }
    }

    cout << "\nCompressed Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {
            cout << "Enter the value: x"<< i <<", y"<<j << ": ";
            cin >> compressed[i][j];
        }
    }


    cout << "\nOriginal Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {

            cout <<  original[i][j] <<"\t";
        }
        cout << "\n";
    }

    cout << "\nCompressed Image:" << endl;
    for(int i = 0; i< dimX; i++)
    {
        for(int j=0; j<dimY; j++)
        {
            cout << compressed[i][j] <<"\t";
        }
        cout << "\n";
    }

    double numerator = 0, denominator =0;

    for(int i=0; i<dimX; i++)
        for(int j=0; j<dimY; j++)
        {

            numerator += pow(compressed[i][j], 2);
            denominator += pow((compressed[i][j]-original[i][j]), 2);

        }

    cout << "\nSNR = " << (numerator/denominator) << endl;

    return 0;
}

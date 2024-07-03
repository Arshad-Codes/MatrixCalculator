#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>

using namespace std;  //ARSHAD .A.H.M.
class cmatrix          //EG/2020/4331
{
    public:
        cmatrix();
        virtual ~cmatrix();
        cmatrix(double a11, double a12, double a21, double a22,string name);
        cmatrix(string name);
        void print();                      //printing the matrix
        void printxy();                    //Function for printing the x,y values
        cmatrix(cmatrix &m);               //copy constructor
        cmatrix & operator = (cmatrix &m); // Assignment operator (chaining Supported)
        cmatrix & operator + (cmatrix &m); // Addition operator (chaining Supported)
        cmatrix & operator - (cmatrix &m); // Subtraction operator (chaining Supported)
        cmatrix & operator * (cmatrix &m); // Multiplication operator
        cmatrix & operator / (cmatrix &m); // Inverse operator

        cmatrix & operator * (double k); // Scalar Multiplication operator
        cmatrix & operator ^ (double k); // Scalar Division operator
        cmatrix & operator + (double k); // Scalar Addition operator
        cmatrix & operator - (double k); // Scalar Subtraction operator

    protected:

    private:
        double x[2][2];
        string matname;
        bool temp;
        void TemporaryMatrix(cmatrix *m);
};

#endif // CMATRIX_H

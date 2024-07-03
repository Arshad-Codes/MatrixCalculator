#include "cmatrix.h"

//Default Constructor
cmatrix::cmatrix()      //Arshad.A.H.M.
{                       //EG/2020/4331
    x[0][0] = 1;
    x[0][1] = 0;
    x[1][0] = 0;
    x[1][1] = 1; //Identity matrix
    matname="I";
    temp=false;
}
//overloaded constructor 1
cmatrix::cmatrix(double a11,double a12,double a21, double a22,string name)
{
    x[0][0] = a11;
    x[0][1] = a12;
    x[1][0] = a21;
    x[1][1] = a22;
    matname=name;
    temp=false;
}
//Overloaded constructor 2
cmatrix::cmatrix(string name)
{
    x[0][0] = 1;
    x[0][1] = 1;
    x[1][0] = 1;
    x[1][1] = 1;
    matname = name;
    temp=false;
}


cmatrix::~cmatrix()
{
    //destructor
}
//print function
void cmatrix::print()
{
    cout<<endl<<matname<<"=";
    cout<<endl<<x[0][0]<<", "<<x[0][1]<<endl;
    cout<<x[1][0]<<", "<<x[1][1]<<endl;
}
//printing the result
void cmatrix::printxy()
{
    cout<<endl<<"The Value of X is : "<<x[0][0]<<endl;
    cout<<endl<<"The Value of Y is : "<<x[1][0]<<endl;
}

//Copy constructor
cmatrix::cmatrix(cmatrix &m)
{
    x[0][0]=m.x[0][0]; x[0][1]=m.x[0][1];
    x[1][0]=m.x[1][0]; x[1][1]=m.x[1][1];
    TemporaryMatrix(&m);
}

//Assignment operator (Chaining supported)
cmatrix & cmatrix::operator = (cmatrix &m)
{
    x[0][0]=m.x[0][0]; x[0][1]=m.x[0][1];
    x[1][0]=m.x[1][0]; x[1][1]=m.x[1][1];

    TemporaryMatrix(&m);
    return *this;
}

//Addition operator (chaining supported)
cmatrix & cmatrix::operator + (cmatrix &m)
{
    cmatrix *res = new cmatrix();
    res->temp=true;

    res->x[0][0] = x[0][0] + m.x[0][0];
    res->x[0][1] = x[0][1] + m.x[0][1];
    res->x[1][0] = x[1][0] + m.x[1][0];
    res->x[1][1] = x[1][1] + m.x[1][1];

    TemporaryMatrix(&m);
    TemporaryMatrix(this);

    return *res;
}

//Subtraction operator (chaining supported)
cmatrix & cmatrix::operator - (cmatrix &m)
{
    cmatrix *res = new cmatrix();
    res->temp=true;

    res->x[0][0] = x[0][0] - m.x[0][0];
    res->x[0][1] = x[0][1] - m.x[0][1];
    res->x[1][0] = x[1][0] - m.x[1][0];
    res->x[1][1] = x[1][1] - m.x[1][1];

    TemporaryMatrix(&m);
    TemporaryMatrix(this);

    return *res;
}

//Multiplication operator (chaining supported)
cmatrix & cmatrix::operator * (cmatrix &m)
{
    cmatrix *res = new cmatrix();
    res->temp=true;

    res->x[0][0] = x[0][0]*m.x[0][0] + x[0][1]*m.x[1][0];
    res->x[0][1] = x[0][0]*m.x[0][1] + x[0][1]*m.x[1][1];
    res->x[1][0] = x[1][0]*m.x[0][0] + x[1][1]*m.x[1][0];
    res->x[1][1] = x[1][0]*m.x[0][1] + x[1][1]*m.x[1][1];

    TemporaryMatrix(&m);
    TemporaryMatrix(this);

    return *res;
}



//Scalar Multiplication operator
cmatrix & cmatrix::operator * (double k)
{
    cmatrix *res = new cmatrix();
    res->temp=false;

    res->x[0][0] = k*x[0][0];
    res->x[0][1] = k*x[0][1];
    res->x[1][0] = k*x[1][0];
    res->x[1][1] = k*x[1][1];
    return *res;
}


//Scalar Division operator
cmatrix & cmatrix::operator ^ (double k)
{
    cmatrix *res = new cmatrix();
    res->temp=false;

    res->x[0][0] = x[0][0]/k;
    res->x[0][1] = x[0][1]/k;
    res->x[1][0] = x[1][0]/k;
    res->x[1][1] = x[1][1]/k;
    return *res;
}

//Scalar Addition operator
cmatrix & cmatrix::operator + (double k)
{
    cmatrix *res = new cmatrix();
    res->temp=false;

    res->x[0][0] = x[0][0] + k;
    res->x[0][1] = x[0][1];
    res->x[1][0] = x[1][0];
    res->x[1][1] = x[1][1] + k;
    return *res;
}

//Scalar Subtraction  operator
cmatrix & cmatrix::operator - (double k)
{
    cmatrix *res = new cmatrix();
    res->temp=false;

    res->x[0][0] = x[0][0] - k;
    res->x[0][1] = x[0][1];
    res->x[1][0] = x[1][0];
    res->x[1][1] = x[1][1] - k;
    return *res;
}



//Inverse operator
cmatrix & cmatrix::operator / (cmatrix &m)
{
    double det = (m.x[0][0]*m.x[1][1]) - (m.x[0][1]*m.x[1][0]);
    x[0][0] =  m.x[1][1]/det;
    x[0][1] = -m.x[0][1]/det;
    x[1][0] = -m.x[1][0]/det;
    x[1][1] =  m.x[0][0]/det;
    TemporaryMatrix(&m);

}
// Function to delete garbage value
void cmatrix::TemporaryMatrix(cmatrix *m)
{
    if(m->temp == true) delete m;
}

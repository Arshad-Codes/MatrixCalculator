#include <iostream>
#include "cmatrix.h"

using namespace std; //Arshad A.H.M
                    //EG/2020/4331
int main()
{
    int opt=1;
    while(opt==1){
    double p,q,r,s,g,h;
    cout << "--------------------------------------------------" << endl;
    cout << "----Two variable Simultaneous equation Solver-----" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Ax +By = C"<<endl<<"Here,"<<endl<<"x , y : Two variables"<<endl;
    cout<<"A , B : Coefficient of the Variable"<<endl<<"C     : Constant"<<endl;
    cout << "--------------------------------------------------" << endl;

    cout<<"Enter the A value of First equation "<<endl;cin>>p;
    cout<<"Enter the B value of First equation "<<endl;cin>>q;
    cout<<"Enter the C value of First equation "<<endl;cin>>g;

    cout<<"Enter the A value of Second equation "<<endl;cin>>r;
    cout<<"Enter the B value of Second equation "<<endl;cin>>s;
    cout<<"Enter the C value of Second equation "<<endl;cin>>h;

    cmatrix m1(p,q,r,s,"M1");
    cmatrix m2(g,0,h,0,"M2");
    cmatrix m3("M3");
    cmatrix m4("M4");

    m3/m1;       //m3 is the inverse of m1
    m4 = m3*m2;  //Solving the simultaneous equation using Inverse matrix
    m4.printxy();
    cout<<"Enter 0 to exit the program "<<endl;
    cout<<"Enter 1 for another calculation "<<endl;
    cin>>opt;
    }
}

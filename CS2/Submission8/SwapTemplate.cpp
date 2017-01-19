//Deandre Hall - 1241692
#include<iostream>
#include<stdio.h>

using namespace std;

template <class T>
void swapping(T &val1,T &val2)
{
T temp;   
temp=val2;
val2=val1;
val1=temp;
}

int main()
{
///////////////////Swapping int types
   
int A = 12;
int B = 10;

cout<<"Int swap: "<<endl;

cout<<"A = "<<A<<endl;
cout<<"B = "<<B<<endl<<endl;


cout<<"After swapping: "<<endl;
swapping(A,B);
cout<<"Value of A = "<<A<<endl;
cout<<"Value of B = "<<B<<endl<<endl;


///////////////////Float swap

float float_A = 1.2;
float float_B = 2.32;

cout<<"Float swap: "<<endl;
cout<<"A = "<<float_A<<endl;
cout<<"B = "<<float_B<<endl<<endl;

cout<<"After swapping: "<<endl;
swapping(float_A,float_B);
cout<<"Value of A = "<<float_A<<endl;
cout<<"Value of B = "<<float_B<<endl<<endl;


///////////////////double swap

double double_A = 25.7;
double double_B = 8.2;

cout<<"Double swap: "<<endl;

cout<<"A = "<<double_A<<endl;
cout<<"B = "<<double_B<<endl<<endl;

cout<<"After swapping: "<<endl;
swapping(double_A,double_B);
cout<<"Value of A = "<<double_A<<endl;
cout<<"Value of B = "<<double_B<<endl<<endl;

return 0;
}

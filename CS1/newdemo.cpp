//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <new>
using namespace std;

int main () {

int *point = new int[10]{2};
//*point = 5;
cout<<"Point = "<<point[0]<<endl;
delete [] point;
cout<<"Point = "<<point[0]<<endl;
point = NULL;
system("pause");
cout<<"Point = "<<point[0]<<endl;
system("pause");
return 0;
}


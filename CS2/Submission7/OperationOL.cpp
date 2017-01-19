//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <new>
using namespace std;



class Box
{
public:
    int x,y;
    Box(int a=0, int b=0)
    {
        x = a;
        y = b;
    }
    
    Box operator+ (const Box &);
    bool operator== (const Box &);
};

Box Box::operator+ (const Box &p)
{
    Box b;
    b.x = this->x + p.x;
    b.y = this->y + p.y;

    return b;
}

bool Box::operator== (const Box &p)
{
	Box b;
	b.x= p.x - p.y;
	cout<<"do the math take a bath"<<endl;
	if (b.x == 0) return true;
	else return false;
}

int main(){
    Box b1(10,12);
    Box b2(5,10);
    Box b3;                // b1 + b2;
    b3 = b1 + b2;
    cout<<b3.x<<", "<< b3.y<<endl;
    
    if (b3.x  == b1.x + b2.x) cout<<"nice!"<<endl;
    
    system("pause");
    return 0;
}

// overloading class constructors
#include <iostream>
#include <new>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle ();
    Rectangle (int);
    Rectangle (int,int);
    //~Rectangle;
    int area (void) {return (width*height);}
};

Rectangle::Rectangle () {
  width = 0;
  height = 0;
}

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

Rectangle::Rectangle (int a){
	width=a;
	height=7;
}

//Rectangle::~Rectangle;


int main () {
  Rectangle rect (3,4);
  Rectangle rectb;
  Rectangle rectc(3);
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  cout << "rectc area: " << rectc.area() << endl;
  return 0;
}

//Deandre Hall -1241692
//1410 COSC [T/Th 11:30-1] lab w/ Chris Devito

#include <iostream>
using namespace std;

int main(){
char grade;
bool done = true;
char ch;

do{
cout<<"Insert your class letter grade >> " ;
cin >> grade;

switch(grade){
              
case 'a':	case 'A':
case 'b':	case 'B':
case 'c':	case 'C':
case 'd':	case 'D':cout<<"You passed!"<<endl;break;
default: cout<<"You failed."<<endl;

}
cout<<endl;
cout<<"Would you like to enter another grade? (Y/N) "<<endl;
cin>>ch;
cout<<endl;

if (ch=='n'||ch=='N') done=false;
} while (done!=false);

cin.get();
return 0;


}

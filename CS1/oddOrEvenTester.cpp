#include <iostream>
#include <iomanip>

using namespace std;

int main(){
int i=0, j=1;
bool test = true;
char ch;


while(test!=false){
	
cout<<"Enter a number: ";
cin>> i ;

if ((i%2)==1)	cout<<"The number "<<i<<" is an odd number"<<endl;
else cout<<"The number "<<i<<" is an even number"<<endl;

cout<<"Would you like to check another number? (Y/N) ";
cin>>ch;

if (ch=='n' || ch=='N') test=false;

}

cin.get();
return 0;   
}

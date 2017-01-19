//Deandre Hall - 1241692
//1410 COSC [T/Th lab 11:30-1] TA: Chris Devito

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

int i=0;
bool done = true;
char ch;

	cout<<"Enter an integer value: ";
	cin>>i;
	i*=2;

for (int j = 0; done!=false ; i*=2){
	
	cout<<"The number "<<i/2<<" after doubling "<<++j<<" time(s) is "<< i << "." <<endl;
	cout<<"Do you want to double it again? (Y/N) ";
	cin>>ch;
	cout<<endl<<endl;
	
if (ch == 'n' || ch=='N')
	{done=false;}
		
		
		
}
return 0;
}

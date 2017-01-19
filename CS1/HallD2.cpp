//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30 - 1 lab w/ Chris Devito]

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
int axels=0;
char test;
bool done=true;

while( done != false){

cout<<"Does the vehicle have an EZ tag? (Y/N) ";
cin>>test;

if (test=='Y' || test=='y')
	{cout<<">> The vehicle has an EZ tag."<<endl<<endl;
	cout<<"How many axels does the Vehicle have? ";
	cin>>axels;
	if (axels<=2) {cout<<"The vehicle has "<<axels<<" axel(s). "<<endl<<endl;
		cout<<"Toll charge = $1.45"<<endl<<endl;}
	else if (axels==3) {cout<<"The vehicle has "<<axels<<" axels."<<endl<<endl;
		cout<<"Toll charge = $3.50"<<endl<<endl;}
	else if (axels==4) {cout<<"The vehicle has "<<axels<<" axels."<<endl<<endl;
		cout<<"Toll charge = $5.25"<<endl<<endl;}
	else if (axels==5) {cout<<"The vehicle has "<<axels<<" axels."<<endl<<endl;
		cout<<"Toll charge = $7.00"<<endl<<endl;}
	else {cout<<"The vehicle has "<<axels<<" axels."<<endl<<endl;
		cout<<"Toll charge = $8.75"<<endl<<endl;}
}
		
else if (test=='N'||test=='n')
	{cout<<">> The vehicle does not have an EZ tag."<<endl<<endl;
	cout<<"How many axels does the vehicle have? ";
	cin>>axels;
	cout<<endl;
	switch(axels){
		case 0: case 1: case 2: cout<<"The vehicle has "<<axels<<" axel(s). "<<endl<<endl;
		cout<<"Toll charge = $1.75"<<endl<<endl; break;
		case 3:cout<<"The vehicle has "<<axels<<" axel(s). "<<endl<<endl;
		cout<<"Toll charge = $4.00"<<endl<<endl; break;
		case 4:cout<<"The vehicle has "<<axels<<" axel(s). "<<endl<<endl;
		cout<<"Toll charge = $6.00"<<endl<<endl; break;
		case 5:cout<<"The vehicle has "<<axels<<" axel(s). "<<endl<<endl;
		cout<<"Toll charge = $7.75"<<endl<<endl; break;
		default: {cout<<"The vehicle has "<<axels<<" axel(s). "<<endl<<endl;
		cout<<"Toll charge = $9.25"<<endl<<endl;}
	}

}

cout<<"Do you wish to try again? (Y/N) "<<endl<<endl;
cin>>test;
if (test=='n'||test=='N') done=false;
	
}




return 0;	
}

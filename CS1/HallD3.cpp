//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
int years=0;
double rate=0.0, deposit=0.0,startBalance=0.0, endBalance=0.0,dummyValue=0.0;
char ch;
bool done=true;
	
do{
cout<<"Initial deposit? $ ";
cin>>deposit;
cout<<endl;

dummyValue = deposit;

cout<<"Interest rate? % ";
cin>>rate;
cout<<endl;
rate*=.01;
rate-=.001;

cout<<"Number of years? (10-20) ";
cin>>years;
while(years>20){
cout<<"Please re-enter a correct value (10-20)"<<endl;
cin>>years;
}

cout<<endl;

cout<<"Balances at the end of each year: "<<endl<<endl;
//Calculation and outputs

int counter=1;

while(counter<=3)
{

startBalance = deposit;

cout<<"Rate>> "<<(rate)*100<<endl<<endl;

	cout << "Year" << fixed<<setprecision(2)<<right<<
        setw(18) << "Initial Balance" <<
        setw(18) << "Interest" <<
        setw(18) << "Ending balance" <<endl;

    	for(int i=1; i<=years; i++){


		double interest =0.0;

		interest = (startBalance*(rate));	
		endBalance = startBalance + interest;

			cout << i <<
        		setw(18)<< startBalance <<
        		setw(18)<< interest <<
        		setw(18)<< endBalance<<endl;

		
			startBalance=endBalance;
}
rate+=.001;
cout<<endl<<endl;
counter++;

}

cout<<"Do you wish to try again? (Y/N) ";
cin>>ch;

if(ch=='n'||ch=='N') {done=false;}

}
while(done!=false);

return 0;

}


//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

enum exType {BUY,SELL};

double exchange (double& rate,exType ex);
double setRate (double& rate);
void showRates (double& rate);
int showMenu (double& rate);

int main(){
double rate=13.30;

do{	
showMenu (rate);
}while(true);

system ("pause");
return 0;
}

double exchange (double& rate,exType ex){
	double inputValue;
	
	if (ex == 0){
		cout<<"Enter the amout to exchange in Pesos: ";
		cin>>inputValue;
		cout<<"You will get: "<<fixed<<setprecision(2)<<(inputValue/(rate*1.07))<<" in USD."<<endl;
		cout<<endl<<endl<<endl;
	}
	else {
		cout<<"Enter the amount to exchange in Dollars: ";
		cin>>inputValue;
		cout<<"You will get: "<<fixed<<setprecision(2)<<(inputValue/(rate*0.93))<<" in USD."<<endl;
		cout<<endl<<endl<<endl;
	}
	return rate;
}

double setRate (double& rate){
cout<<"The current rate is: "<<rate<<endl;
cout<<"Enter the new exchange rate (Pesos per Dollar): ";
cin>>rate;
return rate;
}

void showRates (double& rate){
cout<<"	Buying Pesos	  Selling Pesos"<<endl;
cout<<"	------------	  -------------"<<endl<<endl;
cout<<setprecision(4)<<"$1 = 	"<<rate*0.93<<"		   "<<rate*1.07<<endl<<endl;
}

int showMenu (double& rate){
int option =0;	
	
cout<<"CURRENCY EXCHANGE MEXICAN PESOS<>USD"<<endl;
cout<<"------------------------------------"<<endl;
cout<<"	Buying Pesos	  Selling Pesos"<<endl;
cout<<"	------------	  -------------"<<endl<<endl;
cout<<"$1 = 	"<<fixed<<setprecision(4)<<rate*0.93<<"		   "<<rate*1.07<<endl<<endl;
cout<<"Select the option"<<endl<<endl;

cout<<"	1. Pesos to Dollars"<<endl;
cout<<"	2. Dollars to Pesos"<<endl;
cout<<"	3. Change Exchange Rate"<<endl;
cout<<"	4. Show Exchange Rates"<<endl;
cout<<"	5. Exit"<<endl<<endl;

cout<<">>";
cin>>option;

switch(option){
case 1: {exchange (rate,BUY);} break;
case 2: {exchange (rate,SELL);}break;
case 3: setRate (rate); break;
case 4: showRates (rate); break;
case 5:	exit(1);	
}




}


//Deandre Hall - 1241692
//1410 COSC Program 1
//[T/Th 11:30-1] Lab w/ Chris Devito

#include <iostream> //libraries
#include <iomanip>
using namespace std; // namespace

const double RENT_COST = 1200.00, CABLE_COST=55.99, INTERNET_COST=45.00, PHONE_COST=39.50; //constant assignment

int main()
{
double gasBill=0.00, electrBill=0.00, totalUtilities=0.00;
int numTenants=3;
cout<<fixed;

cout<<"Bob: Gas bill: $";
cin>>gasBill;

cout<<"Bob: Electricity bill: $";
cin>>electrBill;
cout<<endl;

cout<<"--------------------------------"<<endl;
cout<<"Number of tentants: "<<numTenants<<endl<<endl;

cout<<"Rent:        $ "<<setw(8)<<setprecision(2)<<RENT_COST<<" A"<<endl;  //outputs the values for the cost of each bill
cout<<"Electricity: $ "<<setw(8)<<setprecision(2)<<electrBill<<" B"<<endl;
cout<<"Gas:         $ "<<setw(8)<<setprecision(2)<<gasBill<<" B"<<endl;
cout<<"Cable:       $ "<<setw(8)<<setprecision(2)<<CABLE_COST<<" C"<<endl;
cout<<"Phone:       $ "<<setw(8)<<setprecision(2)<<PHONE_COST<<" C"<<endl;
cout<<"Internet:    $ "<<setw(8)<<setprecision(2)<<INTERNET_COST<<" C"<<endl<<endl;

totalUtilities=electrBill+gasBill+CABLE_COST+PHONE_COST+INTERNET_COST;

cout<<"Total Utilites:        $ "<<setw(8)<<setprecision(2)<<totalUtilities<<endl<<endl;

cout<<"Total for Adam:        $ "<<setw(8)<<setprecision(2)<<((totalUtilities/3)+(RENT_COST/2))<<endl;
cout<<"Total for Bob:         $ "<<setw(8)<<setprecision(2)<<((totalUtilities/3)+(RENT_COST/4))<<endl;
cout<<"Total for Charles:     $ "<<setw(8)<<setprecision(2)<<((totalUtilities/3)+(RENT_COST/4))<<endl<<endl;

cout<<"Bob must pay Adam:     $ "<<setw(8)<<setprecision(2)<<((totalUtilities/3)+(RENT_COST/4)) - (electrBill+gasBill) <<endl;
cout<<"Charles must pay Adam: $ "<<setw(8)<<setprecision(2)<<((totalUtilities/3)+(RENT_COST/4)) - (CABLE_COST + PHONE_COST + INTERNET_COST)<<endl;
cout<<"Adam will collect:     $ "<<setw(8)<<setprecision(2)<<((totalUtilities/3)+(RENT_COST/4)) - (electrBill+gasBill) + ((totalUtilities/3)+(RENT_COST/4)) - (CABLE_COST + PHONE_COST + INTERNET_COST); cout<<" from Bob and Charles."<<endl;

return 0;	
}

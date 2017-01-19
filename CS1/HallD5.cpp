//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <time.h>

using namespace std;

void init(int& size);
int getNum(int lower, int upper);
//void getStatistics(double mean,double std,int size,int lower,int upper);
//double getZ (double mean,double std);
bool repeat(); 


int main(){
int seed,size,upper,lower,sum=0,dummy,squared=0;
double mean=0.0,std=0.0;
srand (time(NULL));

do{

cout<<"Seed for the random number generator >> ";
cin>>seed; cout<<endl;
srand(seed);

init(size);
lower=0;
upper=100;
for(int i=1;i<=size*.2;i++){	
dummy=getNum(lower, upper);
squared+=(dummy*dummy);
sum+=dummy;
}
lower=40;
upper=70;
for(int i=1;i<=size*.8;i++){	
dummy=getNum(lower, upper);
squared+=(dummy*dummy);
sum+=dummy;
}

mean = ((double)(sum)/size);
cout<<"Average = "<<fixed<<setprecision(2)<<mean; cout<<endl;

std = sqrt((((squared)-(2*mean*sum)+((mean*mean)*size))/size));

cout<<"Stanard deviation = "<<fixed<<setprecision(2)<<std<<endl<<endl;

//getZ(mean,std);

cout<<endl<<endl<<endl;
}while(repeat()==true);
cin.get();
return 0;
}

void init(int& size){
cout<<"The size of the sequence >> ";
cin>>size; cout<<endl;

//cout<<"Lower and upper bound for the random number >> ";
//cin>>lower; cin>>upper; cout<<endl;
}

int getNum(int lower, int upper){
	int randNum=rand()% upper + lower;
	cout <<	randNum <<endl;
	return randNum;
}

bool repeat(){
	char done;
	cout<<"Would you like to try again? (Y/N) >> ";
	cin >> done;
	if (done=='y'||done=='Y') return true;
	else return false;
	cout<<endl<<endl;	
}



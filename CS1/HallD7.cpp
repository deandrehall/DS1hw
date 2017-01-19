
//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int randNum();
void direction();
void printArray();
void printArraySteps();
void printArrayLocat(); 
void exitProgram();

const int SIZE = 15;
int stepCounter=0;

int x={(SIZE/2)};
int y={(SIZE/2)};

int array[SIZE][SIZE]={0};

int main(){
int seed = 0;

cout<<"Random Walk Simulation"<<endl<<"Seed: ";
cin>>seed;
srand(seed);

printArray();

system("pause");
return 0;
}

int randNum(){
	int randomInt=rand()%4+1;
	return randomInt;
}

void direction(){
	
int randDirection = randNum();

switch(randDirection){
case 1: /*east*/ 

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}

x++;

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}

	for(int i=0; i<SIZE; i++){
	
		for(int j=0;j<SIZE; j++){
			
			if ((x==i)&&(y==j)){	
				array[i][j]++;	
			}
		}
	}
	break;

case 2: /*west*/

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}

x--;

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}

	for(int i=0; i<SIZE; i++){
	
		for(int j=0;j<SIZE; j++){
			
			if ((x==i)&&(y==j)){	
			array[i][j]++;
			}
		}
	}
	break;
case 3: /*north*/ 

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}

y++;

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}

	for(int i=0; i<SIZE; i++){
	
		for(int j=0;j<SIZE; j++){
			
			if ((x==i)&&(y==j)){
			array[i][j]++;
			}
		}
	}
	break;

case 4:	 /*south*/

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}

y--;

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}
	for(int i=0; i<SIZE; i++){
	
		for(int j=0;j<SIZE; j++){
			
			if ((x==i)&&(y==j)){
			array[i][j]++;
			}
		}
	}
	break;
}
}

void printArraySteps(){
	
	for(int i=0; i<SIZE; i++){
	
		for(int j=0;j<SIZE; j++){
			
			cout<<setw(3)<<array[i][j];
	}
	cout<<endl<<endl;
}
}

void printArrayLocat(){
	
	for(int i=0; i<SIZE; i++){
	
		for(int j=0;j<SIZE; j++){
			
				if ((x==i)&&(y==j)){
				cout<<setw(3)<<"O";
				}
			else cout<<setw(3)<<".";
	}
	cout<<endl<<endl;
}
}

void printArray(){
int numSteps=0; 

do{
cout<<"Number of steps (0 to stop): ";
cin>>numSteps;

for(int i=0;i<numSteps;i++){
 		direction();
 		if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}
 		cout<<"Coordinate: ("<<x+1<<", "<<y+1<<")"<<endl;
 		stepCounter++;
}

if((x<0)||(x==SIZE)||(y<0)||(y==SIZE)) {exitProgram();}
cout<<"Total Steps: "<< stepCounter <<endl;
printArrayLocat();
cout<<endl<<endl;
printArraySteps();
cout<<endl<<endl;

cout<<"Number of steps (0 to stop): ";

}while(numSteps!=0);
exitProgram();
}

void exitProgram(){
printArrayLocat();
cout<<endl<<endl;
printArraySteps();
cout<<endl<<endl;
cout<<"The Random Walk is Over in " << stepCounter <<" steps.";
exit(0);
}

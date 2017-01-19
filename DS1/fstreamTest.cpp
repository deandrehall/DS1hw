//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main () {

ifstream txtFile;
int numCount=0;
int wordCount=0;
int alpha=0; // letters in each input
int num=0; // digits in each input
char grabThis[100]; //input from txt file

txtFile.open("input1.txt");

   if (txtFile.fail()){
         cout<<"File failed to open."<<endl;
         system("pause"); 
    	 exit(1);
      } 
      
	else{
	  		cout<<"input1.txt"<<endl;
 		}

while(txtFile>>grabThis){
	
	for(int i=0; i<100; i++){
	
	//if ((!isalnum(grabThis[i])) || (isspace(grabThis[i])));
	/*else*/ if(isalpha(grabThis[i])) alpha++;
	else if(isdigit(grabThis[i])) num++;
	
	if(i=100){
		
		if((alpha>num)&(alpha>0)){
		wordCount++;
		alpha=0;
		num=0;
		}
	
		else if ((num>alpha)&(num>0)){ 
		numCount++;
		alpha=0;
		num=0;
		}
	
	}
	
 }
	
	cout<<grabThis<<endl;
	
}

txtFile.close();

cout<<"words="<<wordCount<<endl;
cout<<"numbers="<<numCount<<endl;

system("pause");
return 0;
}


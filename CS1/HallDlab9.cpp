/*
  Lab 9 exercise 1
  Date: 17/09/09 15:27
  Description:   Show the effects of global and local scope 
*/

#include <iostream>
#include <cstdlib>

using namespace std;

//global variable
int number = 10000;

int function(int number);

int main(){
   cout << "global: " << number << endl;
 
 
   //local variable
   int number = 6;
   cout << "local: " << number << endl;
 
   int newNumber = 0;
   //save return variable
   int returnNumber = function(newNumber);
   cout << "return " << returnNumber << endl;
 
   //is this local, global, or changed from function?
   //This 'number' is local
   cout << "number " << number << endl;
 
   //which newNumber is this?
   //This 'newNumber' is only available within the main function
   cout << "newNumber " << newNumber << endl;
 
   system("Pause");
   return 0;
}

int function(int number){
    cout << "paramater " << number << endl;
    number = 123456;
    int newNumber = 4000;
    return newNumber;
}

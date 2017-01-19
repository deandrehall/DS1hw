#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_LINE_LENGTH = 121;
void getlineDeleteExtraSpace(char line[]);

int main(){
   int n;
   char line[MAX_LINE_LENGTH];

   cout<<"Enter a line of text:\n";
   getlineDeleteExtraSpace(line);
   cout<<"Here is the input string:\n";
   cout<<line<<endl;
   cin.get();  // instead of the pause.
   return 0;
}

void getlineDeleteExtraSpace(char line[]){
   char ch;
   bool previousSpace = false;
   int n = 0;

   cin.get(ch);
   while (ch != '\n'){
      if (ch != ' '){
         line[n] = ch;
         n++;
         previousSpace = false;
      }  else if (!previousSpace){ //and ch == ' '
         line[n] = ch;
         n++;
         previousSpace = true;
      }
      cin.get(ch);
   }
   line[n] = '\0';
}

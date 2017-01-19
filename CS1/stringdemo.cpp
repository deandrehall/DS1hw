#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

int main (){
	int length=0;
	string name ("DEANDRE");
	
	for(int i=0;i<name.length();i++){
		
		name[i]=tolower(name[i]);
	}
	
	cout<<name;
	
	
	
	system("pause");
	return 0;
}

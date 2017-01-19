//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;

void remPunct(string &word, int &wordCount, int &numCount){

	if(isalpha(word[0])) wordCount++;
	else if(isdigit(word[0])) numCount++;
	
}

int main(int argc, char *argv[]) {

ifstream txtFile;
int numCount=0;
int wordCount=0;
string word="";
char grabThis; //input from txt file
bool clean = false;
string token="";
string fileName = argv[1];
token = fileName.substr(9);

txtFile.open(token);

while(txtFile.get(grabThis)){
////Grab each character, skip whitespace && !alnum characters
	
	if((isalnum(grabThis)) || (grabThis == '-')){
	word+=grabThis;
	if(!((isalnum(txtFile.peek())) || (txtFile.peek() == '-'))) clean=true;
	}
	
	if((clean==true))
	{
	//cout<<word<<endl;
	remPunct(word, wordCount, numCount);
	word="";
	clean=false;
	}

}

txtFile.close();
cout<<"words="<<wordCount<< " " <<"numbers="<<numCount<<endl;

return 0;
}


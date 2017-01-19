//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;
/*
void remPunct(string &word){
	string taboo = "-(),+.=_<>/?!@#$%^&*[]{}:;";
	int pos=0;
	
	for(int x = 0; x<word.length(); x++){
		for(int y = 0; y<taboo.length(); y++){
			pos=word.find(taboo[y]);
			if(word[x]==taboo[y]) word.erase(word.begin()+pos);
		}
	}
	
}
*/
void remPunct(string &word, int &wordCount, int &numCount){
	string taboo = "().,+=_<>/?!@#$%^&*[]{}:;";
	string dummy="";
	bool check = true;
	bool clean = false;
	size_t pos = 0;
	string token = "";
	//int pos=0;

	//check if isalnum(word[i]), dummy+=word[i]; catches good characters; might be able to be called recursivly
	
	
	for(int x=0;x<word.length();x++){
		if((isalnum(word[x])) || (word[x]=='-')) dummy+=word[x];
	}
	
	for(int i=0;i<word.length();i++){
		for(int c=0;c<taboo.length();c++){
			if(word[i]==taboo[c]) check=false;
		}
		if(check=true){
		clean = true;
		}
	}
	
	/*
	for(int x=0;x<word.length();x++){
		if(isalnum(word[x])) dummy+=word[x];
	}
	*/
	
	/*
	for(int x = 0; x<word.length(); x++){
		for(int y = 0; y<taboo.length(); y++){
			pos=word.find(taboo[y]);
			if(word[x]==taboo[y]) {
				word.erase(word.begin()+pos);
				remPunct(word);
				}	
		}
	}
	*/
	
	/*	
	for(int i = 0; i<word.size(); i++){
		
	if ((ispunct(word[i]))||(!isalnum(word[i]))) word.erase(word.begin()+i);
	
	}
	*/
	word=dummy;
	if(clean=true){
	if(isalpha(word[0])) wordCount++;
	else if(isdigit(word[0])) numCount++;
	}
	//else if((ispunct(word[0])) || (isspace(word[0])));
	
}


	


int main (int argc, char* argv[]) {

ifstream txtFile;
int numCount=0;
int wordCount=0;
string word="";
char grabThis[100]; //input from txt file

txtFile.open("input2.txt");

while(txtFile>>grabThis){
////Grab each character, skip whitespace && !alnum characters
	word = grabThis;
	remPunct(word, wordCount, numCount);
	
	cout<<word<<endl;
}

txtFile.close();
cout<<"words="<<wordCount<< " " <<"numbers="<<numCount<<endl;

system("pause");
return 0;
}


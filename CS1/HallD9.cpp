//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

//string toLowerCase();

struct words {
	string word;
	int count;
}word[200];

const int MAX = 200;

int main(){
	int i=0;
	int totalwords=0;
	int distinctwords=0;
	
	
	
cout<<"Please enter your sentences, you can enter '###' as a single word with"<<endl;
cout<<"leading and following spaces to finish the input: ";
cout<<endl<<endl;

for ( i = 0; i<MAX;i++){
	
	nextword:
		
	cin>>word[i].word;
	
	
	//Exits input
	if(word[i].word == "###"){
	
	 break;
}
	
		//removes punctuation
	for(int k = 0; k<word[i].word.length(); k++){
		if(ispunct(word[i].word[k])){
			word[i].word.erase(k,1);
		}
		
			
	}
	
	

	//lowercase converter
	for (int j=0;j<word[i].word.length();j++){

	for(int k=0;k<word[i].word[k]!='\0';k++){
		word[i].word[k]=tolower(word[i].word[k]);
		
	}
	
}


//word[i].word=toLowerCase();


	
	for (int k=0;k<word[i].word.length();k++){
			//skips spaces
		if(word[i].word[k] == ' '){
			i++;
			
			goto nextword;
		}
	}
	
		//duplicate word check
	for(int k = 0; k<MAX; k++){
	
	if(word[i].word != word[k].word){
		word[i].count++;
		i++;
		goto nextword;
	}
	else if (word[i].word == word[k].word){
         
         word[k].word=word[i].word;
         word[k].count++;
        // word[i].word="";
         
         //word[i].count=0;
         i++;
         goto nextword;
         }
}
/*
	for(int k = 1; k<MAX; k++){
	
	if(word[i].word == word[k].word){
		word[i].count+=word[k].count;
		word[k].count=0;
	
	
		i++;
		goto nextword;
	}
}
*/

}



	/*
	for(int k=0; k<MAX; k++){
		
	}*/
	


//Outputs
for (int j = 0; j<MAX; j++){
	totalwords+=word[j].count;
	if(word[j].word!="") distinctwords++;
}


cout<<"Total number of words: "<<totalwords<<endl<<endl;
//cout<<"Total number of distinct words: "<<distinctwords;


cout<<endl<<endl;
for(int j = 0; j<MAX; j++){

if((word[j].word != "")&&(word[j].word != "###")&&(word[j].count>0)){
cout<<setw(20)<<word[j].word<<"	"<<word[j].count<<endl;
}

}

system("pause");
return 0;
}
/*
string toLowerCase(){

int i =0;

	//lowercase converter
	for ( i=0;i<word[i].word.length();i++){

	for(int k=0;k<word[i].word[k]!='\0';k++){
		word[i].word[k]=tolower(word[i].word[k]);
		
	}
	
}

return word[i].word;

	
}*/


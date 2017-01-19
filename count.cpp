#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream count;
	char word[35];
	int wordCounter = 0;
	int numberCounter = 0;
	char ch;
	int index = 0;
	string fileName;
	string str2;
	string tok1,tok2;
	
	fileName = argv[1];	// sending filename to string
	//str2 = fileName.substr(6); // getting rid of input=
    //cout<<str2<<endl;
    cout<<fileName<<endl;
    
    size_t pos1 = fileName.find("input=");
    size_t pos2 = fileName.find(";");
    tok1=fileName.substr(pos1+6,pos2-6);
    pos1=fileName.find("digitsPerNode=");
    tok2=fileName.substr(pos1+14);
    
    cout<<"tok1="<<tok1<<endl;
    cout<<"tok2="<<tok2<<endl;
    
    
    /*
    for(int i=0; i<test.length(); i++){
        if(test[i]=';') test.erase(i);
    }
    cout<<test<<endl;
     */
     
	count.open(str2.c_str());

	while(count.get(ch))	// while loop in order to read everything in the file
	{

		if(isalpha(ch))	// if statement to check if it is a word.
		{
			word[0] = ch;
			index++;
			count.get(word[index]);

			while(!(ispunct(word[index]) | isspace(word[index])))	//reading the word until it hits anything that isnt a letter or digit.
			{ 
				index++;
				count.get(word[index]);
			}

			index = 0;		// resets the index.
			wordCounter++;
		}


		if(isdigit(ch))	// if statement to check if it is a number.
		{
			word[0] = ch;
			index++;
			count.get(word[index]);

			while(!(ispunct(word[index]) | isspace(word[index])))
			{ 
				index++;
				count.get(word[index]);
			}

			index = 0;
			numberCounter++;
		}


	}



count.close();

cout << "words=" << wordCounter << " " << "numbers=" << numberCounter << endl;


return 0;
}
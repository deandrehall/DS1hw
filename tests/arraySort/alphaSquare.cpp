#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {

ifstream unsorted;//unsorted txt file
ofstream sorted;//sorted txt file
char grab[25]; //pulls characters from unsorted txt file
char storage[5][5]; //stores values of sorted array

unsorted.open("unsortedarray.txt");//opens unsorted txt file
cout<<"unsorted file"<<endl;
//puts contents of unsorted txt file into an array of length 25, prints unsorted file, then closes unsorted txt file
while(!unsorted.eof()){
	
	static int i = 0;
	unsorted>>grab[i];
	if(i%5==0) cout<<endl;//new line after 5 characters
	if(i!=25)cout<<grab[i];//prints 25 characters and then stops

	i++;
}
unsorted.close();
//

sort(grab, grab+25);//sorts 25 elements in grab[]

sorted.open("sortedarray.txt");//opens sorted txt file

cout<<endl;//line break for sorted output
cout<<"sorted file"<<endl<<endl;


//puts the contents of the new sorted array into the 5x5 array and writes to sorted txt file, prints sorted array, then closes sorted txt file
for(int x=0; x<5; x++){
	static int i=0;
	
	for(int y=0; y<5; y++){
		
		storage[x][y] = grab[i];//transfers values from sorted array into storage array
		i++;
		sorted<<storage[x][y];//writes contents of storage array onto the sorted txt file
		if(i%5==0)sorted<<endl;//new line after 5 characters
		cout<<storage[x][y];//prints sorted characters
		if(i%5==0)cout<<endl;//new line after 5 characters
			
	}
}
sorted.close();
//
system("pause");
return 0;
}


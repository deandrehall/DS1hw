//#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using namespace std;

bool check4Rep(int vector[9]){
	
	int elem, elem2;
	for(int i=0;i<9;i++){
		elem=vector[i];
		for(int k=(i+1); k<9; k++){
			elem2=vector[k];
			if( elem!=0)
				if( elem!=0 && elem ==elem2)
					 return false;
		}
	}
	return true;
	
	
}

int main()
{
  
	int grid[9][9]={{5,3,4,6,7,8,9,1,2},	
					{6,7,2,1,9,5,3,4,8},
					{1,9,8,3,4,2,5,6,7},
					{8,5,9,7,6,1,4,2,3},
					{4,2,6,8,5,3,7,9,1},
					{7,1,3,9,2,4,8,5,6},
					{9,6,1,5,3,7,2,8,4},
					{2,8,7,4,1,9,6,3,5},
					{3,4,5,2,8,6,1,7,9}};

	int vector[9];
	
	int x=0;
	int y=0;
	int counter=0;
	
for(int k=0;k<9;k++){
	
	for(int i=0;i<9;i++){
		vector[i] = grid[x][y];
		y++;
	}
	if(check4Rep(vector)!=true){
	cout<<check4Rep(vector)<<endl;
	return 0;
	}
	x++;
	y=0;
}

	x=0;
	y=0;
for(int k=0;k<9;k++){
	
	for( int i=0; i<9; i++){
		vector[i] = grid[x][y];
		x++;
	}
	if(check4Rep(vector)!=true){
	cout<<check4Rep(vector)<<endl;
	return 0;
	}
	y++;
	x=0;	
}


	cout<<"1"<<endl;	
	system("pause");

    return 0;
}

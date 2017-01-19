//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int map[18] = { 2, 1, 3, 1, 1, 2, 3, 5, 3, 2, 1, 0, 2, 1, 2, 4, 1, 2 };


int main(){

	int arsize = 0;
	int arvalue = 0;

	cout << "Enter the size of the target array: ";
	cin >> arsize;

	int target[arsize];
	/*
	cout << "Enter " << arsize << " integers between 0 and 5 >> ";

	for (int i = 0; i < arsize; i++){
		cin >> arvalue;
		target[i] = arvalue;
	}
	*/
	system("pause");
	return 0;
}
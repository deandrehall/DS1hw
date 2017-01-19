//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int map[18]={2,1,3,1,1,2,3,5,3,2,1,0,2,1,2,4,1,2};

void calcdiff(int array[],int arsize);

int calcsum(int a, int b);
//int calcsumdummy(int c, int d);

int main(){
	
do{
	int arsize = 0;
	int arvalue = 0;

	cout << "Enter the size of the target array: ";
	cin >> arsize;
	if(arsize==0) exit(0);

	int target[arsize];
//////////////////////////////////////////////////////////////
	cout << "Enter " << arsize << " integers between 0 and 5 >> ";

	for (int i = 0; i < arsize; i++){
		cin >> arvalue;
		target[i] = arvalue;
	}

	cout<<"The map: "<<endl<<endl;
	
	for(int i = 0;i < 18;i++){
		cout<<map[i]<<" ";
	}
		cout<<endl<<endl;
	
	cout<<"The target: "<<endl<<endl;
	
	for(int i = 0;i<arsize;i++){
		cout<<target[i]<<" ";	
	}
		cout<<endl<<endl;
/////////////////////////////////////////////////////////////////

calcdiff(target,arsize);
}while(true);


	system("pause");
	return 0;
}

void calcdiff(int array[],int arsize){
	int a=0, b=arsize-1 ,sum=0 ,sumB=0;
	int smallestdiff=0,smallestA=0,smallestB=0;
	
	for(int i=0;i<arsize;i++){
	sum+=array[i];
	}
	
	cout<<"sum of target = "<<sum<<endl<<endl;
	smallestdiff=abs(sum-calcsum(a,b));


while (b<18){
	for(a;a<b;a++){
		sumB=abs((sum-calcsum(a,b)));
	
		cout<<"Diff ["<<a<<", "<<b<<"] = "<<sumB<<endl;
		
		if (smallestdiff>sumB){
			smallestdiff=sumB;
			smallestA=a;
			smallestB=b;
		}
		
		a++;
		break;
	}
b++;
}
cout<<endl;
cout<<"The best match is at ["<<smallestA<<", "<<smallestB<<"] with a diff of "<<smallestdiff<<".";
cout<<endl<<endl;

}

int calcsum(int a, int b){
	int sum=0;
	
	for(a;a<=b;a++){

		sum+=map[a];
	}
	
	return sum;
}


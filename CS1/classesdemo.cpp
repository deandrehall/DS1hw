//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

class programming{
	private:
		int variable;
	public:
		void input_value(){
			cout<<"In function input_value, Enter a value: ";
			cin>>variable;
		}
		void output_value(){
			cout<<"Variable entered is ";
			cout <<variable <<endl;
		}
}i;

int main(){
//programming i;
i.input_value();
i.output_value();




system("pause");
return 0;
}


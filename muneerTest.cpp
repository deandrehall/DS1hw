
#include <iostream>
#include<cstdlib>

using namespace std;

void sayOneDigit(char a)
{
	switch(a){
	case '1': cout <<"one";break;
	case '2': cout <<"two";break;
	case '3': cout <<"three";break;
	case '4': cout <<"four";break;
	}
}
void sayTwoDigit(char a,char b)
{
	switch(a){
	case'1':
		switch(b){
	case '0': cout <<"ten";break;
	case '1': cout <<"eleven";break;
	case '2': cout <<"twelve";break;
	}
		return;
	case '2': cout << "twenty";break;
	case '3': cout << "thirty";break;
	case '4': cout << "fourty";break;

	}
	sayOneDigit(b);
}
void sayThreeDigit(char a,char b,char c)
{
	sayOneDigit(a);
	cout << "hundred";
	sayTwoDigit(b,c);

}

int countNumElem(char num[])
{
int cnt=0;
while(num[cnt] !=0)
	cnt++;
return cnt;
}


int main()
{
    char num[]="312";
	int cnt=countNumElem(num);

	
	switch(cnt){
	case 1:sayOneDigit(num[0]);break;
	case 2:sayTwoDigit(num[0],num[1]);break;
	case 3:sayThreeDigit(num[0],num[1],num[2]);break;
   cout <<endl;
	}
   system("pause");
   return 0;
}

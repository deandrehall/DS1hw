//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <new>
#include <fstream>
#include <cmath>
using namespace std;

struct node{
	
	string input1;
	string input2;
	string op;
	string answer;
	node *next;
	node *last;
	
};

node *head;

void doMath(node *link);
int getLSD(string bignum, int pos);

node* createNode(string num1, string num2, string ch){
	
	node *link = new node;
	link->input1=num1;
	link->input2=num2;
	link->op=ch;
	link->next=NULL;
	link->last=NULL;
	return link;
	
}

void clearList(){
	
	if(head == NULL) return;
	else head = NULL;
	
}

void insertNode(string num1, string num2, string ch){
	
	node *temp = head;
	node *newNode = createNode(num1, num2, ch);
	if (head == NULL){
		head = newNode;
		head->last = NULL;
	}
	else{
		while(temp->next != NULL) temp = temp->next; //find end of list;
		temp->next = newNode;
		newNode->last = temp;
	}
	
}

void print(){
	
	if (head == NULL){
		cout<<"empty list"<<endl;
		return;
	}
	
	node *temp = head;
	while(temp != NULL){
		cout<<temp->input1;
		cout<<temp->op;
		cout<<temp->input2<<endl;
		
		temp=temp->next;
	}
	
}

void reversePrint(){
	
	if (head == NULL){
		cout<<"empty list"<<endl;
		return;
	}
	
	node *temp = head;
	while(temp->next != NULL) temp = temp->next; //finds end of list
	while(temp != NULL){
		cout<<temp->input1;
		cout<<temp->op;
		cout<<temp->input2<<endl;
		
		temp=temp->last;	
	}
	cout<<endl;
	
}

void prep(){
	
	node *temp = head;
	
	while(temp != NULL){
		
		doMath(temp);
		cout<<temp->input1<<temp->op<<temp->input2<<"="<<temp->answer<<endl;
		temp = temp -> next;
	
	}
	
}

void doMath(node *link){
	
	string digits = "";
	int i = 0; //larger length
	int j = 0; //smaller length
	int x = 0; //place changer var
	//int z; //length of the longest num
	
	int a; // num1
	int b; // num2
	int m; //place changer
	//int counterA = to_string(link->input1).length();
	//int counterB = to_string(link->input2).length();
	int sum = 0;
	string finalsum = "";
	int carry = 0; // carryout from addition
	
	/*
	if(link->input1.length() >link->input2.length()){
		i = link->input1.length();
		j = link->input2.length();
	}
	else if(link->input2.length() > link->input1.length()){
		i = link->input2.length();
		j = link->input1.length();
	}
	else if (link->input2.length() == link->input1.length()){
		i = link->input1.length();
		j = link->input1.length();
	}
	*/
	
	//cout<<"z="<<z<<endl;
	
	int posa = link->input1.length();
	int posb = link->input2.length();
	
	if ( posa > posb ) i = posa;
	else if ( posb > posa ) i = posb;
	
	while(i>0){
		
		//a = link->input1[i] - '0';
		//b = link->input2[j] - '0';  //out of bounds, getting garbage value, add another iterator for smaller values
		//int dummy=atoi(link->input1[i]);
		//cout<<"dummy to int:"<<dummy<<endl;
		a = getLSD(link->input1, posa);
		b = getLSD(link->input2, posb);
		cout<<"input1="<<link->input1<<endl;
		cout<<"input2="<<link->input2<<endl;
		cout<<"a="<<a<<endl;
		cout<<"b="<<b<<endl;
		/*
		cout<<"a in loop "<<a<<endl;
		cout<<"a fixed in loop "<<(int)link->input1[i]<<endl;
		cout<<"b in loop "<<b<<endl;
		cout<<"b fixed in loop "<<(int)link->input2[i]<<endl;
		*/
		
		/*
		if(i < 0) a=0;
		else if(j < 0) b=0;
		else if((j && i) < 0){
			a=0;
			b=0;
		}
		*/
		
		posa--;
		posb--;
		
		i--;
		j--;
	

		m = pow(10,x);
		
		//sum = a*m + b*m + carry*m;
		sum = a + b + carry;
		carry = sum/10;
		sum = sum % 10;
		
		
			//cout<<"i="<<i<<endl;
			//cout<<"j="<<j<<endl;
			//cout<<"a="<<link->input1<<endl;
			//cout<<"a len ="<<link->input1.length()<<endl;
			//cout<<"b="<<link->input2<<endl;
			//cout<<"b len ="<<link->input2.length()<<endl;
			cout<<"sum="<<sum<<endl;
		
		
		/*
		if((a+b+carry) >= 10){
			sum -= 10*m;
			carry = 1;
		}
		else carry = 0;
		*/
		
		finalsum += to_string(sum);
		
		x++;
		//counterA--;
		//counterB--;
	}
	/*
	cout<<"a="<<link->input1<<endl;
	cout<<"a len ="<<link->input1.length()<<endl;
	cout<<"b="<<link->input2<<endl;
	cout<<"b len ="<<link->input2.length()<<endl;
	cout<<"sum="<<sum<<endl;
	*/
	if(carry!=0) finalsum+=carry;
	link->answer = finalsum;
	
}

int getLSD(string bignum, int pos){
	bignum="1000";
	cout<<bignum<<endl;
	if( (pos < bignum.length()) || (pos > 0 ) ){
		
		int nice = bignum[pos-1]-'0';
		cout<<"getLSDval = "<<nice<<endl;
		return nice;
	}
	
	else return 0;
	

}

int main (){

	ifstream file;
	string line;
	string input1;
	string input2;
	string op;
	int numnodes = 0;
	bool moveon = false;
	int i = 0;
	int len1 = 0;
	int len2 = 0;
	
	string dummy1="";
	string dummy2="";
	
	int digitspernode=2;
	file.open("input1.txt");
	
	while( getline(file, line) ){
		
			while( i < line.length() ){
				
				if( ((isdigit(line[i])) || (line[i] == '.')) && (moveon == false) ){
					input1 += line[i];
					i++;
				}
				
				else if((line[i] == '*') || (line[i] == '+')){
					op = line[i];
					moveon = true;
					i++;
				}
				
				else if( ((isdigit(line[i])) || (line[i] == '.')) && (moveon == true) ){
					input2 += line[i];
					i++;
				}
			
			}
			
		//cout<<"input2="<<input2<<endl;
		
			int test = stoi(input1) + stoi(input2);
		cout<<"TEST"<<test<<endl;
		
		insertNode(input1, input2, op);
		
		//print();
		
		
	
		i = 0;
		input1="";
		input2="";
		moveon=false;
		
		prep();
		
		
	}
	
	
	
	
	//getLSD("1234567",5);


system("pause");
return 0;
}


//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <new>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

class linkedlist
{
	
	protected:
	
		struct node
		{
			long long digits;
			char digit;
			string number;
			node *next;
			node *prev;
		};
	
		node *head;
		node *tail;
		int count;

	public:

		linkedlist()
		{ head = NULL; tail = NULL; count = 0; }
	
		~linkedlist();
		void display() const;
		void insertNode();
		void print();
		void appendString(string num);
		void destroyList();
	
};

string add(string, string);
string stringswap(string);
string multiply(string, string);
void ParseCommand(const char* command, string& filename, int& digitsPerNode);

string add(string num1, string num2){
	
	int len;
	if( num1.length() > num2.length() ) len = num1.length();
	else if ( num2.length() > num1.length() ) len = num2.length();
	else len = num1.length();
	
	int i = 0;
	int a = 0;
	int b = 0;
	int temp = 0 ;
	int carry = 0;
	int posA = num1.length()-1;
	int posB = num2.length()-1;
	string sum = "";
	
	//cout<<"num1: "<<num1<<endl;
	//cout<<"num2: "<<num2<<endl;
	
	for(i=len-1; i>=0; i--){
		
		a = num1[posA]-'0';
		b = num2[posB]-'0';
		
		if( posA<0 ) a = 0;
		else if( posB<0 ) b = 0; 
		else if ( i<0 ) a = b = 0;
		
		temp=(a+b+carry);
		
		if( (a+b+carry) >= 10 ) carry = 1;
		else carry = 0;
		
		temp = temp % 10;
		
		/*
		cout<<"a = "<<a<<endl;
		cout<<"b = "<<b<<endl;
		cout<<"carry = "<<carry<<endl;
		cout<<"current sum = "<<temp<<endl;
		*/
		
		sum += to_string(temp);
		
		posA--;
		posB--;
		
	}
	
	if(carry != 0) sum+= to_string(carry);
	
	//sum = reverse(sum.begin(), sum.end())
	sum = stringswap(sum);
	
	while( (sum.length()!=1) and (sum[0] == '0') ){
		sum.erase(sum.begin());
	}
	
	
	return sum;
	i=0;
	sum = "";
	
}

string stringswap(string number){

	int length = number.length();
	int last_pos = length-1;
	for(int i = 0; i < length/2; i++)
	{
	    char tmp = number[i];
	    number[i] = number[last_pos - i];
	    number[last_pos - i] = tmp;
	}
	
	//cout<<"swapped = "<<number<<endl;
	return number;
}

string multiply(string num1, string num2){
	
	int i = 0;
	int a = 0;
	int b = 0;
	int numzeros = 0;
	int temp = 0 ;
	int carry = 0;
	//int posA = num1.length()-1;
	//int posB = num2.length()-1;
	//int num = stoll(num1);
	string prodDummy = "0";
	string prod = "";
	
	int len;
	
	if( num1.length() > num2.length() ){
		len = num1.length();
	}
	else if ( num2.length() > num1.length() ){
		len = num2.length();
		string dummy = num1;
		num1 = num2;
		num2 = dummy;
	}
	else{
		len = num1.length();
	}
	
	int posA = num1.length()-1;
	int posB = num2.length()-1;
	
	
	for(i = num2.length()-1; i>=0; i--){
		
		//if( posA<0 ) a = 0;
		//else if( posB<0 ) b = 0; 
		//else if ( i<0 ) a = b = 0;
		
		//cout<<"--multiplying"<<endl;
		for(int j=num1.length()-1; j>=0; j--){
			
			a = num1[posA]-'0';
			b = num2[posB]-'0';
			temp = (a*b + carry);
			
			carry = temp / 10;
			temp = temp % 10;
			
			//cout<<"posA="<<posA<<endl;
			//cout<<"posB="<<posB<<endl;
			//cout<<a<<"*"<<b<<"+"<<carry<<"="<<temp<<endl;
			//cout<<"carry="<<carry<<endl;
			
			if( (posA-1) >= 0 ){
				posA--;
			}
			
			/*
			while( (prod.length()>1) && (prod[0] == '0') ){
				prod.erase(prod.begin());
			}
			*/
			
			prod = to_string(temp) + prod;
			
			if(posA<0) break;
			if(posB<0) break;
				
		}
		
		posA = num1.length()-1;
		
		//cout<<"--adding"<<endl;
		
		//posA = num1.length()-1;
		//carry = 0;
		
		if( (posB-1) >= 0 ){
			posB--;
		}
		
		//cout<<"numzeros="<<numzeros<<endl;
		for(int x = 1*numzeros; x>0; x--){
			prod = prod + '0';
		}
		
		numzeros++;
		//cout<<"current prodDummy="<<prodDummy<<endl;
		//cout<<"current prod="<<prod<<endl;
		prodDummy = add(prodDummy, prod);
		//prod += add(prod,stringswap(prodDummy));
		//cout<<"post addition="<<prodDummy<<endl;
		//cout<<"current prod="<<prod<<endl;
		prod = "";
		
	}
	
	prod = prodDummy;
	
	if(carry != 0) prod = to_string(carry) + prod;
	
	//prodDummy = stringswap(prod);
	
	while( (prod.length()>1) && (prod[0] == '0') ){
		prod.erase(prod.begin());
	}
	
	return prod;
	
	
}

void ParseCommand(const char* command, string& filename, int& digitsPerNode)
{
	string strCommand(command);
	size_t posEqual1 = strCommand.find_first_of("=");
	size_t posEqual2 = strCommand.find_last_of("=");
	size_t posCommas = strCommand.find_first_of(";");

	filename = strCommand.substr(posEqual1 + 1, posCommas - posEqual1 - 1);
	string strDigitsPerNode = strCommand.substr(posEqual2 + 1);

	stringstream ss(strDigitsPerNode.c_str());

	ss >> digitsPerNode;
}

int main(int argc, char *argv[]){
	
	ifstream file;
	string line;
	string input1="";
	string input1dec="";
	string input2="";
	string input2dec="";
	string EE = "";
	string op;
	linkedlist num1, num2;
	bool nextnum = false;
	bool grabdec1 = false;
	bool grabdec2 = false;
	bool grabEE = false;
	bool swapcheck = false;
	
	int i = 0;
	
	
    string filename;
	int digitsPerNode;
	ParseCommand(argv[1], filename, digitsPerNode);
	file.open(filename.c_str());
	
	//file.open("input1.txt");
	
	while(file >> line){
		
		while( i < line.length() ){
				
			if( ((isdigit(line[i])) ) && (nextnum == false) ){
				input1 += line[i];
				i++;
			}
			
			else if( (line[i] == '.') && (nextnum == false) ){
				nextnum = true;
				i++;
			}
			
			else if( ( (isdigit(line[i])) ) && (grabdec1 == true) ){
				input1dec += line[i];
				grabdec1 = false;
				i++;
			}
			
			else if( (line[0]+line[1]+line[2]+line[3]) == 'swap' ){
				op = "swap";
				swapcheck = true;
				i++;
			}
			
			else if ( (line[i] == '#') ){
				op = "#";
				nextnum=true;
				i++;
			}
			
			else if((line[i] == '*') || (line[i] == '+')){ 
				op = line[i];
				nextnum = true;
				i++;
			}
			
			else if( ((isdigit(line[i])) ) && ( (swapcheck == true) && (nextnum == true) ) ){
				input2 += line[i];
				i++;
			}
			
			else if( ((isdigit(line[i])) ) && (nextnum == true) ){
				input2 += line[i];
				i++;
			}
			
			else if( (line[i] == '.') && (nextnum == true) ){
				grabdec2 = true;
				i++;
			}
			
			else if( ( (isdigit(line[i])) ) && (grabdec2 == true) ){
				input2dec += line[i];
				grabdec2 = false;
				i++;
			}
			
			else i++;
			
		}
		
		num1.appendString(input1);
		num2.appendString(input2);
		/*
		cout<<"input1 "<<input1<<endl;
		cout<<"op "<<op<<endl;
		cout<<"input2 "<<input2<<endl;
		*/	
		
		if(op == "+"){
			cout<<input1<<"+"<<input2<<"="<<(add(input1, input2))<<".0"<<endl;
		}
		else if(op == "*"){
			cout<<input1<<"*"<<input2<<"="<<multiply(input1, input2)<<".0"<<endl;
		}
		/*
		else if(op == "swap"){
		    //cout<<"input1="<<input1<<endl;
		    //cout<<"input1dec="<<input1dec<<endl;
			cout<<"swap("<<input1<<"."<<input2<<")="<<input2<<"."<<input1<<endl;
		}
		else if(op == "#"){
			cout<<input1<<"#"<<input2<<"="<<multiply(input1,input2)<<endl;
		}
			//Eval = stoi(Eval);
			//cout<<input1<<"#"<<input2<<"="<<multiply(input1, pow(10,Eval))<<endl;
		*/
		
		input1="";
		input1dec="";
		input2="";
		input2dec="";
		EE="";
		grabEE=false;
		grabdec1=false;
		grabdec2=false;
		nextnum=false;
		swapcheck=false;
		i=0;

	}
	
	
	
	//num1.print();cout<<endl;
	//num2.print();cout<<endl;
	//num2.print();
	
	//system("pause");
	return 0;
}

linkedlist::~linkedlist()
{
	node *nodePtr;
	node *nextNode;

	nodePtr = head;

	while(nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void linkedlist::display() const
{
	node *nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		cout << nodePtr->digit;

		nodePtr = nodePtr->next;
	}
}

void linkedlist::insertNode(){
	
	node *temp = head;
	node *newNode = new node();
	if (head == NULL){
		head = newNode;
		head->prev = NULL;
	}
	else{
		while(temp->next != NULL) temp = temp->next; //find end of list;
		temp->next = newNode;
		newNode->prev = temp;
	}
	
}

void linkedlist::print(){
	
	if (head == NULL){
		cout<<"empty list"<<endl;
		return;
	}
	
	node *temp = head;
	while(temp != NULL){
		cout<<temp->number<<endl;
		//cout<<temp->digits;
		//cout<<temp->digit<<endl;
		
		temp=temp->next;
	}
	
}

void linkedlist::appendString(string num)
{

	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->number = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(!head)
	{
		head = newNode;
		tail = newNode;
		count++;
	}

	else 
	{
		nodePtr = head;

		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
		newNode->prev = nodePtr;
		tail = newNode;
		count++;
	}
}

void linkedlist::destroyList()
{
	node *ptr;
	count = 0;
	while(head != NULL)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}

	tail = NULL;
}



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

class linkedlist
{
	
private:

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
	{ head = NULL; tail = NULL; count = 0;  }

	~linkedlist();

	void appendR(string);
	void display() const;
	void displayString() const;
	void destroyList();
	void reverseDisplay() const;
	int getDigit(int) const;
	int getCount() const;
	void append(long long);
	void appendS(char);
	char getStr(int);
	void appendString(string);
	string getString(int);
	
};

int main (){

	ifstream file;
	string line;
	string input1;
	string input2;
	string op;
	int numnodes = 0;
	bool moveon = false;
	int i = 0;
	
	string dummy1;
	string dummy2;
	
	linkedlist num1, num2;
	
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
			
			dummy1=input1;
			dummy2=input2;
			string send = "";
		
		for(int k = 0; k<dummy1.length(); k++){
			

			cout<<dummy1[k]<<" "<<k<<endl;
			cout<<(int)dummy1[k]<<" "<<k<<endl<<endl;
			cout<<dummy1[k]+dummy1[++k]<<" "<<k<<endl<<endl;
			cout<<dummy1[++k]<<" "<<k<<endl;
			cout<<(int)dummy1[++k]<<" "<<k<<endl<<endl;
			send+=dummy1[k];
			
		}
		
		cout<<"send: "<<send<<endl;
		
		//print();
		i = 0;
		input1 = "";
		input2 = "";
		send = "";
		moveon=false;
		
		
		//prep();
		
	}


system("pause");
return 0;
}

void linkedlist::append(long long number)
{

	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->digits = number;
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

void linkedlist::appendS(char number)
{

	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->digit = number;
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

void linkedlist::appendR(string num)
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
		nodePtr = tail;

		while(nodePtr->prev)
		{
			nodePtr = nodePtr->prev;
		}

		nodePtr->prev = newNode;
		newNode->next = nodePtr;
		head = newNode;
		count++;
	}
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

void linkedlist::reverseDisplay() const
{
	node *nodePtr;

	nodePtr = tail;

	while(nodePtr != NULL)
	{
		cout << nodePtr->digits << endl;
		nodePtr = nodePtr->prev;
	}
}

int linkedlist::getDigit(int position) const
{
	node *nodePtr;

	nodePtr = tail;

	if(position == 0)
	{
		return nodePtr->digits;
	}

	if(position >= count)
	{
		return 0;
	}

	else
	{
		for(int a = 0; a < position; a++)
		{
			nodePtr = nodePtr->prev;
		}

		return nodePtr->digits;
	}
}

int linkedlist::getCount() const
{
	return count;
}

char linkedlist::getStr(int position)
{
	node *nodePtr;

	nodePtr = head;

	if(position == 0)
	{
		return nodePtr->digit;
	}

	if(position >= count)
	{
		return 0;
	}

	else
	{
		for(int a = 0; a < position; a++)
		{
			nodePtr = nodePtr->next;
		}

		return nodePtr->digit;
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

string linkedlist::getString(int position)
{
	node *nodePtr;

	nodePtr = tail;

	if(position == 0)
	{
		return nodePtr->number;
	}

	if(position >= count)
	{
		return 0;
	}

	else
	{
		for(int a = 0; a < position; a++)
		{
			nodePtr = nodePtr->prev;
		}

		return nodePtr->number;
	}
}

void linkedlist::displayString() const
{
	node *nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		cout << nodePtr->number << endl;

		nodePtr = nodePtr->next;
	}
}


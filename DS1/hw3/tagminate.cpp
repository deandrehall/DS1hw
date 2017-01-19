//Deandre Hall - 1241692
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class stack{
	
	protected:
		struct node{
			char data = '@';
			node* prev;
		};
		
		node* top;
		int counter;
		int lineNum;
		bool errorFlag;
		char storeTop;
		char storeError;
		int storeLine;
		
	
	public:
		stack(){
			top = NULL;
			counter = 0;
			lineNum = 0;
			storeLine = 0;
			errorFlag = false;
		}
		
		~stack(){
			
		}
		
		void push(char x);
		node* topNode();
		char queryTop();
		bool isEmpty();
		void pop();
		int howMany();
		void evalSymbol(char);
		void print(node*);
		void incLineNum();
		int returnLineNum();
		bool checkFlag();
		int retStoredLine();
		char retStoredTop();
		char retStoredError();
	
};

int main(int argc, char* argv[]){
	
	ifstream file;
	file.open(argv[1]);
	
	string data;
		
	stack *tower;
	tower = new stack;

	while(getline(file, data)){
		tower->incLineNum();
		for(int i = 0; i<data.length();i++){
			
			if( !isalnum(data[i]) ){
				tower->evalSymbol(data[i]);
			}
		}
	}
	
	if((tower->isEmpty() == false) && (tower->checkFlag() == false)){
		cout<<"Error in line "<<tower->returnLineNum()+1<<", top of stack="<<tower->queryTop()<<" current=$";
	}
	else if(tower->checkFlag() == true){
		cout<<"Error in line "<<tower->retStoredLine()<<", top of stack="<<tower->retStoredTop()<<" current="<<tower->retStoredError();
	}
	else cout<<"ok";
	
	return 0;
}

void stack::push(char x){
	
	node *newNode;
	newNode = new node;
	newNode->data = x;
	newNode->prev = NULL;
	counter++;
	
	if(top == NULL){
		top = newNode;
	}
	else{
		newNode->prev = topNode();
		top = newNode;
	}
		
}

stack::node* stack::topNode(){
	return top;
}

char stack::queryTop(){
	
	if(top != NULL){
		return top->data;
	}
	
}

bool stack::isEmpty(){
	
	if(top==NULL) return true;
	else return false;
	
}

void stack::pop(){
	
	if(isEmpty()){
		(void)0;
	}
	
	else{
		node* temp = top;
		top = top->prev;
		
		if(howMany() >= 2){
			counter--;
			delete temp;
			return;
		}
		else{
			counter--;
			delete temp;
			top = NULL;
			return;
		}
	}
	
}

int stack::howMany(){
	return counter;
}

void stack::evalSymbol(char x){
	
	if(this->checkFlag() == false){
		
		if( (x == '(') || (x == '[') || (x == '{') || (x == '<') ){
			this->push(x);
		}
		
		if(x == '\"'){
			if(this->queryTop() == '\"'){
				this->pop();
			}
			else if( this->queryTop() != '\"' ){
				this->push(x);
			}
		}
		else if(x == '\''){
			if(this->queryTop() == '\''){
				this->pop();
			}
			else if( this->queryTop() != '\'' ){
				this->push(x);
			}
		}
		
		if(x == ')'){
			if(this->queryTop() != '('){
				this->errorFlag = true;
				this->storeError = x;
				this->storeTop = this->queryTop();
				this->storeLine = this->lineNum;
			}
			else this->pop();
		}
		else if(x == ']'){
			if(this->queryTop() != '['){
				this->errorFlag = true;
				this->storeError = x;
				this->storeTop = this->queryTop();
				this->storeLine = this->lineNum;
			}
			else this->pop();
		}
		else if(x == '}'){
			if(this->queryTop() != '{'){
				this->errorFlag = true;
				this->storeError = x;
				this->storeTop = this->queryTop();
				this->storeLine = this->lineNum;
			}
			else this->pop();
		}
		else if(x == '>'){
			if(this->queryTop() != '<'){
				this->errorFlag = true;
				this->storeError = x;
				this->storeTop = this->queryTop();
				this->storeLine = this->lineNum;
			}
			else this->pop();
		}
	
	}
	
}

void stack::print(node* temp){
	
	if(temp == NULL){
		cout<<endl;
		return;
	}
	
	else{
		cout<<temp->data<<endl;
		print(temp->prev);
	}
	
}

void stack::incLineNum(){
	this->lineNum++;
}

bool stack::checkFlag(){
	if(this->errorFlag == true) return true;
	else return false;
}

int stack::returnLineNum(){
	return this->lineNum;
}

int stack::retStoredLine(){
	return this->storeLine;
}

char stack::retStoredError(){
	return this->storeError;
}

char stack::retStoredTop(){
	return this->storeTop;
}

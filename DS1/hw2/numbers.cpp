//Deandre Hall - 1241692
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;

class linkedlist
{
	
	protected:
	
		struct node
		{
			string data = "";
			node *next;
			node *prev;
		}link;
	
		node *head;
		node *tail;

	public:

		linkedlist(){
			link.data == "";
			head = NULL;
			tail = NULL;
		}
	
		~linkedlist();
		void display(node* temp);
		void insertNode();
		void print();
		void appendString(node* link, string word);
		void destroyList();
		node* retHead();
		node* retTail();
		void removeNode(node* temp);
		void countNumbers(linkedlist* temp, node* seeker, int count);
		void mean(linkedlist* temp, node* seeker, int count, int sum);
		void max(linkedlist* temp, node* seeker, int maxval, int count);
		void min(linkedlist* temp, node* seeker, int minval, int count);
	
};

class listoflists: public linkedlist{
	protected:
		struct list{
			linkedlist *singlelist;
			list *next;
			list *prev;
		}chain;
		
		list *head;
		list *tail;
		
	public:
		
		listoflists(){
			head = NULL;
			tail = NULL;
		}
		~listoflists();
		void appendLine(list *temp, linkedlist *link);
		list* retHead();
		void findPage(list *temp, int pos, string op2);
		void insert(list *temp, int count);
		void remove(list *temp);
		void display(list *temp);
	
};

int main(int argc, char* argv[]){
	ifstream file;
	listoflists list;
	//chain = new listoflists;
	string line = "";
	string word = "";
	string op1 = "";
	string op2 = "";
	string num = "";
	size_t pos;
	size_t pos2;
	string meanreturn = "";
	string maxreturn = "";
	string minreturn = "";
	string countreturn = "";
	int i = 0;
	
	string input = argv[1];
	size_t posA = input.find("input=");
	size_t posB = input.find(";");
	string tok1 = input.substr(posA + 6, posB - 6);
	posA = input.find("operations=");
	string tok2 = input.substr(posA + 11);
	
	file.open(tok1); //parsing data from input file into linked lists
	while(getline(file, line)){
	    line += '\n';
	    linkedlist *link;
	    link = new linkedlist;
	    //cout<<line<<endl;
	    
	    while(line[i] != '\n'){
	        while(!isspace(line[i])){
	            word += line[i];
	            i++;
	        }
	        //cout<<word<<" ";
	        link->appendString(link->retHead(), word);
	        //link->appendString(link->retHead(), "test");
	        
	        if(line[i] == '\t' || line[i] == ' '){
	            word = "";
	            i++;
	        }
	        if(line[i] == '\r' || line[i] == '\n'){
	            word = "";
	            break;
	        }
	    }
	    i=0;
	    //link->display(link->retHead());
		//cout<<endl;
	    
	    list.appendLine(list.retHead(), link);
		
	}
	file.close();
	
	file.open(tok2); //parsing operations from operation file to perform onto linked lists;
	//cout<<endl;
	//cout<<"entering commands file"<<endl<<endl;
	while(getline(file,line)){
		
		pos = line.find(":");
		op1 = line.substr(0,pos);
		num = line.substr(pos+1);
		pos2 = num.find(":");
		op2 = num.substr(pos2+1);
		num = num.substr(0,pos2);
		//linkedlist *temp;
		//temp = new linkedlist;
		/*
		cout<<"op1: "<<op1<<endl;
		cout<<"op2: "<<op2<<endl;
		cout<<"num: "<<num<<endl;
		*/
		if(op1 == "mathline"){
			
			list.findPage(list.retHead(), stoi(num), op2);
			/*
			if(op2 == "count"){
				//countreturn = list.countNumbers(list.findPage(list.retHead(), stoi(num)), 0);
				//cout<<"starting count operation"<<endl;
				//cout<<"stoi num = "<<stoi(num)<<endl;
				//temp->appendString(list.findPage(list.retHead(), stoi(num)), list.findPage(list.retHead(), stoi(num))->countNumbers(list.findPage(list.retHead(), stoi(num)), num);
				//list.countNumbers(list.findPage(list.retHead(), stoi(num)), 0);
				//list.findPage(list.retHead(), stoi(num));
			}
			else if(op2 == "mean"){
				//cout<<"starting mean operation"<<endl;
				//cout<<"stoi num = "<<stoi(num)<<endl;
				//list.mean(list.findPage(list.retHead(), stoi(num)), 0, 0);
			}
			else if(op2 == "max"){
				//cout<<"starting max operation"<<endl;
				//cout<<"stoi num = "<<stoi(num)<<endl;
				//list.max(list.findPage(list.retHead(), stoi(num)), 0);
			}
			else if(op2 == "min"){
				//cout<<"starting min operation"<<endl;
				//cout<<"stoi num = "<<stoi(num)<<endl;
				//list.min(list.findPage(list.retHead(), stoi(num)), 0);
			}
			*/
		}
		else if(op1 == "deleteline"){
			list.findPage(list.retHead(), stoi(num), op1);
		}
		else if(op1 == "insertline"){
			//cout<<"!!!insert line call!!!"<<endl;
			list.findPage(list.retHead(), stoi(num), op1);
		}
		
	}
	file.close();
	list.display(list.retHead());
	return 0;
}

linkedlist::~linkedlist()
{
	/*
	node *nodePtr;
	node *nextNode;

	nodePtr = head;

	while(nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	*/
	
}

void linkedlist::display(node* temp){
	
	if(temp == head){
		//cout<<endl;
	}

	if(temp == NULL){
		cout<<endl;
		return;
	}
	
	if(temp->data == ""){
		display(temp->next);
	}
	
	else{
		cout<<temp->data<<"\t";
		
		display(temp->next);
		
	}	
}

/*
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
*/

void linkedlist::appendString(node* link, string word)
{
	//word = "ok";
    if(link == NULL){ //if this is a brand new list with no nodes
    	//cout<<"a brand new node!"<<endl;
        //cout<<"appending..."<<endl;
    	//cout<<"word: "<<word<<endl;
        node *newNode;
        newNode = new node;
        newNode->data = word;
        //cout<<"newnode data: "<<newNode->data<<endl;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        head = newNode;
        tail = newNode;
        return;
    }
    /*
    else if(link->next != NULL){ //inserts node in the middle of list;

    	node *temp;
    	temp = new node;
    	temp->data = word;
    	temp->prev = link;
    	temp->next = link->next;
    	link->next->prev = temp;
    	link->next = temp;
    }
    */
    else if(link->next == NULL){//inserts node at end of list, sets tail to that node
    	//cout<<"this node is used, but still good."<<endl;
    	//cout<<"word: "<<word<<endl;
    	node *newNode;
        newNode = new node;
        newNode->data = word;
        newNode->next = NULL;
        newNode->prev = NULL;
        //cout<<"newnode data: "<<newNode->data<<endl;
        link->next = newNode;
        newNode->prev = link;
        tail = newNode;
        return;
    }
    
    else{
    	//cout<<"searching for last node"<<endl;
    	appendString(link->next, word); //if you sent a node in the middle of the list, finds the end of the list
	}
	

}

/*
void linkedlist::destroyList()
{
	node *ptr;
	while(head != NULL)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}

	tail = NULL;
}
*/

linkedlist::node* linkedlist::retHead(){
	return head;
}

linkedlist::node* linkedlist::retTail(){
	return tail;
}

void linkedlist::countNumbers(linkedlist* temp, node* seeker, int count){
	
	if(seeker == NULL){
		//cout<<"appending count value to linkedlist"<<endl;
		//cout<<"printing "<<count<<endl;
		appendString(temp->retHead(), to_string(count));
		//this->display(this->retHead());
		//return to_string(count);
		return;
	}
	//temp.display();
	//cout<<"data in count function: "<<seeker->data<<endl;
	//cout<<"data: "<<temp->data<<endl;
	//cout<<"not null in count"<<endl;
	if(isdigit(seeker->data[0])){
		//cout<<"linear probing"<<endl;
		//cout<<"a number"<<endl;
		count++;
		countNumbers(temp, seeker->next, count);
	}
	else{
		//cout<<"not a number"<<endl;
		countNumbers(temp, seeker->next, count);
	}
	
}

void linkedlist::mean(linkedlist* temp, node* seeker, int count, int sum){
	
	if((seeker == NULL) && (count == 0)){
		//appendString(temp, "undefined");
		//this->display(this->retHead());
		appendString(temp->retHead(), "undefined");
		//return "undefined";
		return;
	}
	
	if(seeker == NULL){
		int mean = sum/count;
		//cout<<"printing mean"<<endl;
		appendString(temp->retHead(), to_string(mean));
		//this->display(this->retHead());
		//return to_string(mean);
		return;
	}
	//cout<<"data in mean function: "<<seeker->data<<endl;
	//cout<<"data: "<<temp->data<<endl;
	//cout<<"not null in mean"<<endl;
	if(isdigit(seeker->data[0])){
		//cout<<"linear probing"<<endl;
		count++;
		sum += stoi(seeker->data);
		mean(temp, seeker->next, count, sum);
	}
	else{
		mean(temp, seeker->next, count, sum);
	}
}


void linkedlist::max(linkedlist* temp, node* seeker, int maxval, int count){
	
	if((seeker == NULL) && (count == 0)){
		//appendString(temp, "undefined");
		//this->display(this->retHead());
		//cout<<"printing undefined"<<endl;
		appendString(temp->retHead(), "undefined");
		//return "undefined";
		return;
	}
	
	if(seeker == NULL){
		//cout<<"printing "<<maxval<<endl;
		//cout<<"appending max value to linkedlist"<<endl;
		appendString(temp->retHead(), to_string(maxval));
		//this->display(this->retHead());
		//return to_string(maxval);
		return;
	}
	//cout<<"data in max function: "<<seeker->data<<endl;
	//cout<<"data: "<<temp->data<<endl;
	//cout<<"not null in max"<<endl;
	if(isdigit(seeker->data[0])){
		//cout<<"linear probing"<<endl;
		count++;
		if(stoi(seeker->data) >= maxval) maxval = stoi(seeker->data);
		max(temp, seeker->next, maxval, count);
	}
	else{
		max(temp, seeker->next, maxval, count);
	}
	
}

void linkedlist::min(linkedlist* temp, node* seeker, int minval, int count){
	
	if((seeker == NULL) && (count == 0)){
		//appendString(temp, "undefined");
		//this->display(this->retHead());
		appendString(temp->retHead(), "undefined");
		//return "undefined";
		return;
	}
	
	if(seeker == NULL){
		//cout<<"appending min value to linkedlist"<<endl;
		appendString(temp->retHead(), to_string(minval));
		//this->display(this->retHead());
		//return to_string(minval);
		return;
	}
	//cout<<"data in min function: "<<seeker->data<<endl;
	//cout<<"data: "<<temp->data<<endl;
	//cout<<"not null in min"<<endl;
	if(isdigit(seeker->data[0])){
		//cout<<"linear probing"<<endl;
		count++;
		if(stoi(seeker->data) <= minval) minval = stoi(seeker->data);
		min(temp, seeker->next, minval, count);
	}
	else{
		min(temp, seeker->next, minval, count);
	}
}

listoflists::~listoflists()
{

}


listoflists::list* listoflists::retHead(){
	return this->head;
}

void listoflists::appendLine(list *chain, linkedlist *link){
	if (head == NULL)
	{
		list *newLine;
		newLine = new list;
		newLine->singlelist = link;
		newLine->next = NULL;
		newLine->prev = NULL;

		head = newLine;
		tail = newLine;
	}

	else if (chain->next == NULL)
	{
		list *newLine;
		newLine = new list;
		newLine->singlelist = link;
		newLine->next = NULL;
		newLine->prev = NULL;

		chain->next = newLine;
		newLine->prev = chain;
		tail = newLine;
	}

	else appendLine(chain->next, link);
}

//linkedlist::node* listoflists::findPage(list *temp, int pos, string op2){
void listoflists::findPage(list *temp, int pos, string op2){
	
	if(pos == 1){
		if(op2 == "count"){
			//cout<<"##entering count##"<<endl;
			countNumbers(temp->singlelist, temp->singlelist->retHead(), 0);
		}
		else if(op2 == "mean"){
			mean(temp->singlelist, temp->singlelist->retHead(), 0, 0);
		}
		else if(op2 == "max"){
			max(temp->singlelist, temp->singlelist->retHead(), 0, 0);
		}
		else if(op2 == "min"){
			min(temp->singlelist, temp->singlelist->retHead(), 9999999, 0);
		}
		else if(op2 == "insertline"){
			insert(temp, pos);
		}
		else if(op2 == "deleteline"){
			remove(temp);
		}
		return;
		
	}
	else findPage(temp->next, pos-1, op2);
}

void listoflists::insert(list *temp, int pos){
	
	if((pos == 1) || (temp->next == NULL)){
		if (temp == NULL){ //if theres nothing in listoflists
			list *newLine;
			newLine = new list;
			linkedlist *newDouble;
			newDouble = new linkedlist;
			//newDouble->appendString(newDouble->retHead(),"");
			newLine->singlelist = newDouble;
			newLine->next = NULL;
			newLine->prev = NULL;
		//	cout<<"NULL list"<<endl;
			head = newLine;
			tail = newLine;
			return;
		}
	
		else if (temp == head){ //insertline 1
			list *newLine;
			newLine = new list;
			linkedlist *newDouble;
			newDouble = new linkedlist;
			//newDouble->appendString(newDouble->retHead(),"");
			newLine->singlelist = newDouble;
			newLine->next = NULL;
			newLine->prev = NULL;
			//cout<<"top of list"<<endl;
			temp->prev = newLine;
			newLine->next = temp;
			head = newLine;
			return;
		}
	
		else if (temp->next == NULL){ //inserts line at end of listoflists
			list *newLine;
			newLine = new list;
			linkedlist *newDouble;
			newDouble = new linkedlist;
			//newDouble->display(newDouble->retHead());
			newLine->singlelist = newDouble;
			newLine->next = NULL;
			newLine->prev = NULL;
			//cout<<"end of list"<<endl;
			temp->next = newLine;
			newLine->prev = temp;
			tail = newLine;
			return;
		}
	
		else{ //inserts line between 2 nodes
			list *newLine;
			newLine = new list;
			linkedlist *newDouble;
			newDouble = new linkedlist;
			newDouble->appendString(newDouble->retHead(),"");
			//newDouble->removeNode(newDouble->retHead());
			newLine->singlelist = newDouble;
			newLine->next = NULL;
			newLine->prev = NULL;
			//cout<<"mid list"<<endl;
			newLine->next = temp;
			temp->prev->next = newLine;
			newLine->prev = temp->prev;
			temp->prev = newLine;
			return;
		}
	}
	else insert(temp->next, pos-1);
	
}

void listoflists::remove(list *temp){
	
	if (temp == head)
		{
			head = temp->next;
			delete temp;
			temp = NULL;
		}

		else if (temp->next == NULL)
		{
			tail = temp->prev;
			delete temp;
			temp = NULL;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			temp = NULL;
		}
}

void listoflists::display(list *temp){
	
	if(temp != NULL){
		temp->singlelist->display(temp->singlelist->retHead());
		this->display(temp->next);
	}
	
}

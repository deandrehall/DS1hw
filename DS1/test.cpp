//Deandre hall - 1241692

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int size = 100;

class Queue{
	protected:
		string person[size];
		int arrival[size];
		int duration[size];
		int remaining[size];
		int head, tail, breakCD, quantum;
	public:
		Queue(){
			head = -1;
			tail = -1;
			breakCD = 1;
			quantum = 2;
		}
		
		~Queue(){
			
		}
		
		bool isFull();
		bool isEmpty();
		void enQueue(string temp[4]);
		void deQueue();
		void fifo();
		void roundRobin();
		int retCount();
		int retHead();
		int search(string);
};

int main(){
	fstream file;
	file.open("test.txt");
	Queue Q;
	string person;
	string arrival;
	string duration;
	string temp[4];
	int time = 0;
	
	while(file>>person>>arrival>>duration){
		
		temp[0] = person;
		temp[1] = arrival;
		temp[2] = duration;
		temp[3] = to_string(stoi(duration)-1);
		
		Q.enQueue(temp);
	
	}
	//Q.fifo();
	Q.roundRobin();
	
	return 0;
}

bool Queue::isEmpty(){
	if (this->head == -1 && this->tail == -1) return true;
	else return false;
}

bool Queue::isFull(){
	if ((this->tail+1)%size == this->head) return true;
	else return false;
}

void Queue::enQueue(string temp[4]){
	
	if(this->isFull()){
		return;
	}
	else if(this->isEmpty()){
		this->head = 0;
		this->tail = 0;
	}
	else{
		this->tail = (this->tail+1)%size;
	}
	
	this->person[tail] = temp[0];
	this->arrival[tail] = stoi(temp[1]);
	this->duration[tail] = stoi(temp[2]);
	this->remaining[tail] = stoi(temp[3]);
	
}

void Queue::deQueue(){
	
	if(this->isEmpty()){
		return;
	}
	else if(this->head == this->tail){
		this->head = -1;
		this->tail = -1;
	}
	else{
		this->head = (this->head+1)%size;
	}
	
}

void Queue::fifo(){
	
	int x;
	int time = 0;
	int breakCounter = 0;
	
	while(!(isEmpty())){
		x = retHead();
		
		while(breakCD>4){
			if(breakCounter > 1){
				breakCounter = 0;
				breakCD = 1;
			}
			else{
				cout<<time<<"\trelax"<<endl;
				time++;
				breakCounter++;
			}
		}
		
		if(time<arrival[x]){
			while(time<arrival[x]){
			cout<<time<<"\twaiting"<<endl;
			time++;
			}
		}
			
		for(int i = 0; i<duration[x]; i++){
			cout<<time<<'\t'<<person[x]<<'\t'<<duration[x]<<'\t';
			if(i < duration[x]-1) cout<<"makeup"<<endl;
			else if(i == duration[x]-1) cout<<"completed"<<endl;
			time++;
		}
		
		breakCD++;
		deQueue();
	}
	
}

void Queue::roundRobin(){
	int x,y;
	int time = 0;
	int breakCounter = 0;
	string temp[4];
	Queue Q2;
	
	while(!(isEmpty())){
		x = retHead();
		while(breakCD>4){
			if(breakCounter > 1){
				breakCounter = 0;
				breakCD = 1;
			}
			else{
				cout<<time<<"\trelax"<<endl;
				time++;
				breakCounter++;
			}
		}
		
		
		
		if(time<arrival[x]){
			if(!(Q2.isEmpty())){
				for(int i = 0; i<quantum; i++){
					y = Q2.retHead();
					cout<<time<<'\t'<<Q2.person[y]<<'\t'<<Q2.duration[y]<<'\t'<<Q2.remaining[y]<<'\t';
					if(Q2.remaining[y]>0) cout<<"makeup"<<endl;
					else{
						cout<<"completed"<<endl;
						time++;
						Q2.deQueue();
						breakCD++;
						y = Q2.retHead();
						break;
					}
					Q2.remaining[y]--;
					time++;
				}
			
			}
			else{
				while(time<arrival[x]){
				cout<<time<<"\twaiting"<<endl;
				time++;
				}
			}
		}
			
		for(int i = 0; i<quantum; i++){
			x=retHead();
			cout<<time<<'\t'<<person[x]<<'\t'<<duration[x]<<'\t'<<remaining[x]<<'\t';
			if(remaining[x]>0) cout<<"makeup"<<endl;
			else if(remaining[x]<=0){
				cout<<"completed"<<endl;
				time++;
				deQueue();
				breakCD++;
				x=retHead();
				break;
			}
			remaining[x]--;
			time++;
		}
		
		if(remaining[x] > 0){
			temp[0] = person[x];
			temp[1] = to_string(arrival[x]);
			temp[2] = to_string(duration[x]);
			temp[3] = to_string(remaining[x]);
			cout<<temp[0]<<" needs more work"<<endl;
		 	Q2.enQueue(temp);
			deQueue();
		}
		
	}
}

int Queue::search(string temp){
	for(int i = 0; i<size; i++){
		if(this->person[i] == temp) return i;
	}
}

int Queue::retCount(){
	return (this->tail+size-this->head)%size+1;
}

int Queue::retHead(){
	return this->head;	
}



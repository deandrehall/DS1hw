//Deandre hall - 1241692

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//const int size = 10;

class Queue{
	protected:
		string *person;
		int *arrival;
		int *duration;
		int *remaining;
		int head, tail, breakCD, quantum, clock, count, dummy, size;
		bool flag = false;
	public:
		Queue(int arraySize){
			
			size = arraySize;
			
			person = new string[size];
			arrival = new int[size];
			duration = new int[size];
			remaining = new int[size];
			
			head = 0;
			tail = 0;
			breakCD = 1;
			quantum = 2;
			clock = 0;
			count = 0;
			dummy = 0;
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
		int retTime();
		bool inQueue(string);
		void setQuantum(int);
};


int main(int argc, char* argv[]){
	fstream file;
	string fileName = argv[1];
	string fileN;
	string person;
	string arrival;
	string duration;
	string temp[4];
	int size = 0;
	string Ssize;
	string schedule;
	string quant;
	
	size_t pos1 = fileName.find("input=");
	size_t pos2 = fileName.find(";");
	fileN = fileName.substr(pos1 + 6, (pos2 - pos1 - 6));
	file.open(fileN);
	//cout<<"filename="<<fileN<<endl;
	fileName = fileName.substr(pos2 + 1);
	pos1 = fileName.find("size=");
	pos2 = fileName.find(";");
	Ssize = fileName.substr(pos1 + 5, (pos2 - pos1 - 5));
	size = stoi(Ssize);
	//cout<<"size="<<Ssize<<endl;
	fileName = fileName.substr(pos2 + 1);
	pos1 = fileName.find("scheduling=");
	pos2 = fileName.find(";");
	schedule = fileName.substr(pos1 + 11, (pos2 - pos1 - 11));
	//cout<<"scheduling="<<schedule<<endl;
	
	fileName = fileName.substr(pos2 + 1);
	pos1 = fileName.find("quantum=");
	pos2 = fileName.find(";");
	quant = fileName.substr(pos1 + 8, (pos2 - pos1 - 8));
	//cout<<"quantum="<<quant<<endl;
	
	Queue Q(256);
	Q.setQuantum(stoi(quant));
	//Queue Q2(size, stoi(quant));
	
	while(file>>person>>arrival>>duration){
		
		if(person[0] != '#'){
			
			temp[0] = person;
			temp[1] = arrival;
			temp[2] = duration;
			temp[3] = to_string(stoi(duration));
			
			Q.enQueue(temp);
			
			if(schedule == "fifo"){
				Q.fifo();
			}
			
		}
		
	}
	
	if(schedule == "roundrobin"){
		Q.roundRobin();
	}
	
	
	
	file.close();
	return 0;
}

bool Queue::isEmpty(){
	if (this->count == 0) return true;
	else return false;
}

bool Queue::isFull(){
	if (this->count == size) return true;
	else return false; /////////USE COUNT IMPLEMENTATION HERE for is full and is empty functions
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
	
	this->count++;
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
		this->head = 0;
		this->tail = 0;
	}
	else{
		this->head = (this->head+1)%size;
	}
	
	this->count--;
	
}

void Queue::fifo(){
	
	int x;
	int static time = retTime();
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
	
	int x,y,durDummy,timeDummy;
	int static time = retTime();
	int breakCounter = 0;
	string temp[4] = "";
	string newActor[4] = "";
	Queue Q2(size);
	Q2.setQuantum(quantum);
	
	while(!isEmpty()){
		//cout<<"test"<<endl;
		x = retHead();
		
		while(breakCD>4){
			if(breakCounter > 1){
				breakCounter = 0;
				breakCD = 1;
			}
			else{
				cout<<time<<"\trelax"<<endl;
				time++;
				x = retHead();
		
				while( (person[x] != Q2.person[tail]) && (time >= arrival[x]) && !Q2.isFull() ){
					x = retHead();                          
				
					if( (person[x] != Q2.person[tail]) && (time >= arrival[x]) ){
						
						newActor[0] = person[x];
						newActor[1] = to_string(arrival[x]);
						newActor[2] = to_string(duration[x]);
						newActor[3] = to_string(remaining[x]);
						//cout<<"12 adding "<<person[x]<<" at time "<<arrival[x]<<" current time= "<<time<<endl;
						person[x] = "";
						deQueue();
						Q2.enQueue(newActor);
					}
				
					x = retHead();
		
				}
				
				breakCounter++;
			}
		}
		
		while( (person[x] != Q2.person[tail]) && (time >= arrival[x]) && !Q2.isFull() ){
			x = retHead();                          
		
			if( (person[x] != Q2.person[tail]) && (time >= arrival[x]) ){
				
				newActor[0] = person[x];
				newActor[1] = to_string(arrival[x]);
				newActor[2] = to_string(duration[x]);
				newActor[3] = to_string(remaining[x]);
				//cout<<"12 adding "<<person[x]<<" at time "<<arrival[x]<<" current time= "<<time<<endl;
				person[x] = "";
				deQueue();
				Q2.enQueue(newActor);
			}
		
			x = retHead();

		}

		
		y = Q2.retHead();
		
		if( (time < Q2.arrival[y]) && (!Q2.isEmpty()) ){
			//cout<<"test!!!"<<endl;
			y = Q2.retHead();
			durDummy = Q2.remaining[y];
			
			for(int i = 0; i<quantum; i++){
				y = Q2.retHead();
				if(durDummy<0){
					//Q2.deQueue();
					break;
				}
				
				durDummy--;
				Q2.remaining[y] = durDummy;
				
				//cout<<time<<'\t'<<"waiting ";
				cout<<time<<'\t'<<Q2.person[y]<<'\t'<<Q2.duration[y]<<'\t';
				
				if(durDummy <= 0){
					cout<<"completed"<<endl;
					breakCD++;
					time++;
					break;
				}
				else if (durDummy > 0){
					cout<<"makeup"<<endl;
				}
				
				time++;
				
				x = retHead();
				while( (person[x] != Q2.person[tail]) && (time >= arrival[x]) && !Q2.isFull() ){
					x = retHead();
					if( (person[x] != Q2.person[tail]) && (time >= arrival[x]) ){
						newActor[0] = person[x];
						newActor[1] = to_string(arrival[x]);
						newActor[2] = to_string(duration[x]);
						newActor[3] = to_string(remaining[x]);
						//cout<<"12 adding "<<person[x]<<" at time "<<arrival[x]<<" current time= "<<time<<endl;
						person[x] = "";
						deQueue();
						Q2.enQueue(newActor);
					}
					x = retHead();
				}
				
			}
			
			Q2.remaining[y] = durDummy;
			
			if(durDummy>0){
				y = Q2.retHead();
				temp[0] = Q2.person[y];
				temp[1] = to_string(Q2.arrival[y]);
				temp[2] = to_string(Q2.duration[y]);
				temp[3] = to_string(Q2.remaining[y]);
				//cout<<"sending "<<Q2.person[y]<<" to the end of the queue"<<endl;
				Q2.person[y] = "";
				Q2.deQueue();
				Q2.enQueue(temp);
			}
			else{
			//	Q2.deQueue();
			}
			
			
		}
		
		else if(Q2.isEmpty()){
			while(Q2.isEmpty()){
				cout<<time<<'\t'<<"waiting"<<endl;
				time++;
				x=retHead();
				while( (person[x] != Q2.person[tail]) && (time >= arrival[x]) && !Q2.isFull() ){
					x = retHead();
					if( (person[x] != Q2.person[tail]) && (time >= arrival[x]) ){
						newActor[0] = person[x];
						newActor[1] = to_string(arrival[x]);
						newActor[2] = to_string(duration[x]);
						newActor[3] = to_string(remaining[x]);
						//cout<<"12 adding "<<person[x]<<" at time "<<arrival[x]<<" current time= "<<time<<endl;
						person[x] = "";
						deQueue();
						Q2.enQueue(newActor);
					}
					x = retHead();
				}	
			}
		}
		
		else if(!Q2.isFull()){
			
			y = Q2.retHead();
			durDummy = Q2.remaining[y];
			
			for(int i = 0; i<quantum; i++){
				y = Q2.retHead();
				durDummy = Q2.remaining[y];
				if(durDummy<=0){
					//cout<<"ok"<<endl;
					Q2.deQueue();
					break;
				}
				
				
				durDummy--;
				Q2.remaining[y] = durDummy;
			
				cout<<time<<'\t'<<Q2.person[y]<<'\t'<<Q2.duration[y]<<'\t';
				
				if(durDummy <= 0){
					cout<<"completed"<<endl;
					breakCD++;
					time++;
					
					x = retHead();
					while( (person[x] != Q2.person[tail]) && (time >= arrival[x]) && !Q2.isFull() ){
						x = retHead();
						if( (person[x] != Q2.person[tail]) && (time >= arrival[x]) ){
							newActor[0] = person[x];
							newActor[1] = to_string(arrival[x]);
							newActor[2] = to_string(duration[x]);
							newActor[3] = to_string(remaining[x]);
							//cout<<"12 adding "<<person[x]<<" at time "<<arrival[x]<<" current time= "<<time<<endl;
							person[x] = "";
							deQueue();
							Q2.enQueue(newActor);
						}
						x = retHead();
					}
					
					Q2.person[Q2.retHead()] = "";
					Q2.deQueue();
															  
					break;
				}
				else if (durDummy > 0){
					cout<<"makeup"<<endl;
				}
				
				time++;
				
				x = retHead();
				while( (person[x] != Q2.person[tail]) && (time >= arrival[x]) && !Q2.isFull() ){
					x = retHead();
					if( (person[x] != Q2.person[tail]) && (time >= arrival[x]) ){
						newActor[0] = person[x];
						newActor[1] = to_string(arrival[x]);
						newActor[2] = to_string(duration[x]);
						newActor[3] = to_string(remaining[x]);
						//cout<<"12 adding "<<person[x]<<" at time "<<arrival[x]<<" current time= "<<time<<endl;
						person[x] = "";
						deQueue();
						Q2.enQueue(newActor);
					}
					x = retHead();
				}
				
				
					/*                                       
					x = retHead();
					if( (person[x] != newActor[0]) && (time >= stoi(newActor[1])) ){
						newActor[0] = person[x];
						newActor[1] = to_string(arrival[x]);
						newActor[2] = to_string(duration[x]);
						newActor[3] = to_string(remaining[x]);
						cout<<"test4 adding "<<person[x]<<" at time "<<arrival[x]<<endl;
						person[x] = "";
						deQueue();
						Q2.enQueue(newActor);
					}
					*/
					//break;
				
			}
			
			Q2.remaining[y] = durDummy;
			
			if(durDummy>0){
				y = Q2.retHead();
				temp[0] = Q2.person[y];
				temp[1] = to_string(Q2.arrival[y]);
				temp[2] = to_string(Q2.duration[y]);
				temp[3] = to_string(Q2.remaining[y]);
				//cout<<"test sending "<<Q2.person[y]<<" to the end of the queue"<<endl;
				Q2.deQueue();
				Q2.enQueue(temp);
			} 
			
			//else{
				//cout<<"finished with "<<person[x]<<endl;
			//	Q2.deQueue();
			//}
		 
		}
		
		else if(Q2.isFull()){
			while(Q2.isFull()){
				
				y = Q2.retHead();
				durDummy = Q2.remaining[y];
				
				for(int i = 0; i<quantum; i++){
					y = Q2.retHead();
					if(durDummy<0){
						break;
					}
					
					durDummy--;
					Q2.remaining[y] = durDummy;
				
					cout<<time<<'\t'<<Q2.person[y]<<'\t'<<Q2.duration[y]<<'\t';
					
					if(durDummy <= 0){
						cout<<"completed"<<endl;
						breakCD++;
						time++;
						
						x = retHead();
						while( (person[x] != Q2.person[tail]) && (time >= arrival[x]) && !Q2.isFull() ){
							x = retHead();
							if( (person[x] != Q2.person[tail]) && (time >= arrival[x]) ){
								newActor[0] = person[x];
								newActor[1] = to_string(arrival[x]);
								newActor[2] = to_string(duration[x]);
								newActor[3] = to_string(remaining[x]);
								//cout<<"12 adding "<<person[x]<<" at time "<<arrival[x]<<" current time= "<<time<<endl;
								person[x] = "";
								deQueue();
								Q2.enQueue(newActor);
							}
							x = retHead();
						}
						
						Q2.person[Q2.retHead()] = "";
						Q2.deQueue();
						
						break;
					}
					else if (durDummy > 0){
						cout<<"makeup"<<endl;
					}
					
					time++;					
				}
				
				Q2.remaining[y] = durDummy;
				
				if(durDummy>0){
					y = Q2.retHead();
					temp[0] = Q2.person[y];
					temp[1] = to_string(Q2.arrival[y]);
					temp[2] = to_string(Q2.duration[y]);
					temp[3] = to_string(Q2.remaining[y]);
					//cout<<"sending "<<Q2.person[y]<<" to the end of the queue"<<endl;
					Q2.person[y] = "";
					Q2.deQueue();
					Q2.enQueue(temp);
				}				
			}
		}
	
		
		
		
		
	}
	
	while(isEmpty() && !Q2.isEmpty()){
		
		x = Q2.retHead();
		
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
		
		while(Q2.person[x] == ""){
			Q2.deQueue();
			x = Q2.retHead();
		}
		
		if( time < Q2.arrival[x] && Q2.isEmpty()){
			
			cout<<time<<'\t'<<"waiting"<<endl;
			time++;
			
		}
		
		else if(!Q2.isFull()){
			
			y = Q2.retHead();
			durDummy = Q2.remaining[y];
			
			for(int i = 0; i<quantum; i++){
				y = Q2.retHead();
				if(durDummy<0){
					break;
				}
				
				durDummy--;
				Q2.remaining[y] = durDummy;
			
				cout<<time<<'\t'<<Q2.person[y]<<'\t'<<Q2.duration[y]<<'\t';
				
				if(durDummy <= 0){
					cout<<"completed"<<endl;
					breakCD++;
					time++;
					Q2.person[Q2.retHead()] = "";
					Q2.deQueue();
					break;
				}
				else if (durDummy > 0){
					cout<<"makeup"<<endl;
				}
				
				time++;
			}
			
			Q2.remaining[y] = durDummy;
			
			if(durDummy>0){
				y = Q2.retHead();
				temp[0] = Q2.person[y];
				temp[1] = to_string(Q2.arrival[y]);
				temp[2] = to_string(Q2.duration[y]);
				temp[3] = to_string(Q2.remaining[y]);
				//cout<<"sending "<<Q2.person[y]<<" to the end of the queue"<<endl;
				Q2.person[y] = "";
				Q2.deQueue();
				Q2.enQueue(temp);
			}
			else{
				//cout<<"finished with "<<person[x]<<endl;
				//Q2.deQueue();
			}
		}
		
		else if(Q2.isFull()){
			while(Q2.isFull()){
				
				y = Q2.retHead();
				durDummy = Q2.remaining[y];
				
				for(int i = 0; i<quantum; i++){
					y = Q2.retHead();
					if(durDummy<0){
						break;
					}
					
					durDummy--;
					Q2.remaining[y] = durDummy;
				
					cout<<time<<'\t'<<Q2.person[y]<<'\t'<<Q2.duration[y]<<'\t';
					
					if(durDummy <= 0){
						cout<<"completed"<<endl;
						breakCD++;
						time++;
						Q2.person[Q2.retHead()] = "";
						Q2.deQueue();
						break;
					}
					else if (durDummy > 0){
						cout<<"makeup"<<endl;
					}
					
					time++;					
				}
				
				Q2.remaining[y] = durDummy;
				
				if(durDummy>0){
					y = Q2.retHead();
					temp[0] = Q2.person[y];
					temp[1] = to_string(Q2.arrival[y]);
					temp[2] = to_string(Q2.duration[y]);
					temp[3] = to_string(Q2.remaining[y]);
					//cout<<"sending "<<Q2.person[y]<<" to the end of the queue"<<endl;
					Q2.person[y] = "";
					Q2.deQueue();
					Q2.enQueue(temp);
				}
				else{
					//cout<<"finished with "<<person[x]<<endl;
				//	Q2.deQueue();
				}
				
				
			}
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
	if(count>0) return this->head;
	else return 0;
}

int Queue::retTime(){
	return this->clock;
}

bool Queue::inQueue(string name){
	for(int i = 0; i<size; i++){
		if (name == this->person[i]){
			return true;
		}
	}
	return false;
}
void Queue::setQuantum(int temp){
	this->quantum = temp;
}


//Deandre Hall - 1241692

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct temp{
	string tempname;
	double tempgpa;
	int tempqat;
	string tempgender;
	string temptag;
	double tempscore;
	int size;
}person;

class candidate{
	protected:
		struct node{
			string name;
			double gpa;
			int qat;
			string gender;
			string tag;
			double score;
			node* next;
			node* prev;
		}student;
		
		node* head;
		node* tail;
		
	public:
		candidate(){
			node student;
			student.name = "";
			student.gpa = 0.0;
			student.qat = 0;
			student.gender = "x";
			student.tag = "temp";
			student.score = 0.0;
			student.next = NULL;
			student.prev = NULL;
			head = NULL;
			tail = NULL;
		}
		~candidate(){
			
		}
		void appendNode(node*);
		void setValues(string, double, int, string, string);
		void print(node*);
		node* retHead();
	
};

void sort(temp[], temp[], temp[], int);

int main(int argc, char* argv[]){
	fstream file;
	string fileN;
	string fileName = argv[1];
	int pick;
	size_t pos1 = fileName.find("input=");
	size_t pos2 = fileName.find(";");
	fileN = fileName.substr(pos1 + 6, (pos2 - pos1 - 6));
	file.open(fileN);
	pos1 = fileName.find("pick=");
	pick = stoi(fileName.substr(pos1+5));
	//cout<<"file = "<<fileN<<endl;
	//cout<<"pick = "<<pick<<endl;
	
	string name;
	double gpa;
	int qat;
	string gender;
	string tag;
	candidate cand;
	
	string dummy;
	
	int filePos;
	bool commentTrap = false;
	
	int male = 0;
	int female = 0;
	int other = 0;
	
	while(getline(file, dummy)){
		istringstream input(dummy);
		//filePos = file.tellg();
		//getline(file, dummy);
		//cout<<"!!!test "<<dummy<<endl;
		//dummy = file.peek();
		if(dummy[0]!='#'){
			input>>name>>gpa>>qat>>gender>>tag;
			person.tempname = name;
			person.tempgpa = gpa;
			person.tempqat = qat;
			person.tempgender = gender;
			person.temptag = tag;
			cand.appendNode(cand.retHead());
			if(gender == "female") female++;
			else if(gender == "male") male++;
			else if((gender != "male")||(gender!="female")) other++;
		}
		//file.seekg(filePos);
		/*
		if(commentTrap == false){
			//cout<<"no trap"<<endl;
			file>>name>>gpa>>qat>>gender>>tag;
				
			person.tempname = name;
			person.tempgpa = gpa;
			person.tempqat = qat;
			person.tempgender = gender;
			person.temptag = tag;
			cand.appendNode(cand.retHead());
			if(gender == "female") female++;
			else if(gender == "male") male++;
			else if((gender != "male")||(gender!="female")) other++;
			if(file.eof()) break;
				
			commentTrap = false;
		}
		else if(commentTrap == true){
			//cout<<"trap here"<<endl;
			getline(file, dummy);
			cout<<dummy<<endl;
			if(file.eof()) break;
			commentTrap = false;
		}
		//commentTrap = false;
		
		//if(file.eof()) break;
		*/
	}	
	
	file.close();
	
	//cand.print(cand.retHead());
	
	temp females[female];
	temp males[male];
	temp others[other];

	int xx = 0;
	int xy = 0;
	int yy = 0;
	
	file.open(fileN);
	while(getline(file, dummy)){
		istringstream input(dummy);
		//dummy = file.peek();
		if(dummy[0] != '#'){
			input>>name>>gpa>>qat>>gender>>tag;
			if(gender == "female"){
				females[xx].tempname = name;
				females[xx].tempgpa = gpa;
				females[xx].tempqat = qat;
				females[xx].tempgender = gender;
				females[xx].temptag = tag;
				females[xx].size = female;
				xx++;
			}
			else if(gender == "male"){
				males[xy].tempname = name;
				males[xy].tempgpa = gpa;
				males[xy].tempqat = qat;
				males[xy].tempgender = gender;
				males[xy].temptag = tag;
				males[xy].size = male;
				xy++;
			}
			else if((gender != "male")||(gender!="female")){
				others[yy].tempname = name;
				others[yy].tempgpa = gpa;
				others[yy].tempqat = qat;
				others[yy].tempgender = gender;
				others[yy].temptag = tag;
				others[yy].size = other;
				yy++;
			}
		}
	
	}
	
	file.close();
	
	while(pick>0){
		sort(females, males, others, pick);
		pick--;
	}
	
	
	return 0;
}

void sort(temp females[], temp males[], temp others[], int pick){
	int numFemales = females[0].size;
	int numMales = males[0].size;
	int numOthers = others[0].size;
	int femmax=0;
	int lastFemMax=0;
	int femPos=0;
	int malemax=0;
	int lastMaleMax=0;
	int malePos=0;
	int othermax=0;
	int lastOtherMax=0;
	int otherPos=0;
	int static mult = 100;
	temp toPrint[pick*3];
	int j = (pick*3)-1;
	int x = (pick*2)-1;
	int y = (pick)-1;
	
	for(int k = 0; k<pick; k++){
		
		for(int i = 0; i<numFemales; i++){
			females[i].tempscore = mult*females[i].tempgpa+females[i].tempqat;
			if(females[i].tempscore >= femmax){
				lastFemMax = femmax;
				femmax = females[i].tempscore;
				femPos=i;
			}
			
		}
	
		toPrint[j] = females[femPos];
		femmax = 0;
		j--;
		females[femPos].tempgpa = 0;
		females[femPos].tempqat = 0;
		
		for(int i = 0; i<numMales; i++){
			males[i].tempscore = mult*males[i].tempgpa+males[i].tempqat;
			if(males[i].tempscore >= malemax){
				lastMaleMax = malemax;
				malemax = males[i].tempscore;
				malePos=i;	
			}
			
		}
	
		toPrint[x] = males[malePos];
		malemax = 0;
		x--;
		males[malePos].tempgpa = 0;
		males[malePos].tempqat = 0;
		
		for(int i = 0; i<numOthers; i++){
			others[i].tempscore = mult*others[i].tempgpa+others[i].tempqat;
			if(others[i].tempscore >= othermax){
				lastOtherMax = othermax;
				othermax = others[i].tempscore;
				otherPos=i;
			}
			
		}
	
		toPrint[y] = others[otherPos];
		othermax = 0;
		y--;
		others[otherPos].tempgpa = 0;
		others[otherPos].tempqat = 0;

	}
	
	for(int i = (pick*3)-1; i>=0; i--){
		cout<<toPrint[i].tempname<<endl;
	}
	//cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	
	mult-=10;
}

void candidate::appendNode(node* temp){
	if(temp == NULL){
		node* newNode;
		newNode = new node;
		newNode->name = person.tempname;
		newNode->gpa = person.tempgpa;
		newNode->qat = person.tempqat;
		newNode->gender = person.tempgender;
		newNode->tag = person.temptag;
        newNode->next = NULL;
        newNode->prev = NULL;

        head = newNode;
        tail = newNode;
        return;
	}
	else if(temp->next == NULL){
		node *newNode;
        newNode = new node;
        
		newNode->name = person.tempname;
		newNode->gpa = person.tempgpa;
		newNode->qat = person.tempqat;
		newNode->gender = person.tempgender;
		newNode->tag = person.temptag;
		newNode->next = NULL;
        newNode->prev = NULL;
        
		temp->next = newNode;
		newNode->prev = temp;
		tail = newNode;
		return;
	}
	else{
		appendNode(temp->next);
	}
		
}

void candidate::setValues(string tempName, double tempGpa, int tempQat, string tempGender, string tempTag){
	this->student.name = tempName;
	this->student.gpa = tempGpa;
	this->student.qat = tempQat;
	this->student.gender = tempGender;
	this->student.tag = tempGender;
}

void candidate::print(node* temp){
	if(temp == NULL){
		cout<<endl;
		return;
	}
	else{
		cout<<temp->name<<'\t'<<temp->gpa<<'\t'<<temp->qat<<'\t'<<temp->gender<<'\t'<<temp->tag<<'\t'<<((100*temp->gpa)+temp->qat)<<endl;
		print(temp->next);
	}
}

candidate::node* candidate::retHead(){
	return this->head;
}

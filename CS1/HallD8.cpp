//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;
ifstream inStream;


struct student{
	int id;
	char fname[20];
	char lname[20];
	char email[40];
	double gpa;
	
}studentinfo;

struct roster{
	int recNum;
	student arraystudent[100];
}studentlist;

bool getRecord(int& recNum, int& id, char fname[], char lname[], char email[], double& gpa);
void printMenu();
void idSearch();
void nameSearch();
void printStudents();

int main(){
int i = 0;	

for (int j = 0; j<100; j++){
getRecord(studentlist.recNum, studentlist.arraystudent[i].id,studentlist.arraystudent[i].fname, studentlist.arraystudent[i].lname, studentlist.arraystudent[i].email, studentlist.arraystudent[i].gpa);
i++;
}
printMenu();

system("pause");
return 0;
}

void printMenu(){

int choice;	
	
cout<<"Class Roster"<<endl
<<"Total Students = "<< studentlist.recNum+1 << endl<<endl;

while(true){

cout<<"1. Display all students"<<endl;
cout<<"2. Search for student by ID"<<endl;
cout<<"3. Search for student by Name"<<endl;
cout<<"4. Exit"<<endl;
cout<<">>";
cin>>choice;
cin.ignore(256,'\n');
cout<<endl;

switch(choice){
	case 1: printStudents();break;
	case 2: idSearch();break;
	case 3: nameSearch();break;
	case 4: exit(1);
	default: cout<<"Please enter a correct choice. "<<endl<<endl;
}

}

}

bool getRecord(int& recNum, int& id, char fname[], char lname[], char email[], double& gpa){
   if (recNum==0) {
      inStream.open("prog8in.txt");
      if (inStream.fail()){
         cout<<"File \"prog8in.txt\" cannot be opened."<<endl;
         system("pause"); 
         exit(1);
      } else cout<<"File \"prog8in.txt\" opened."<<endl;
   }         
   inStream >>id >>fname >>lname >>email >>gpa;
   if (inStream.eof()) return false;
   else {
       recNum++;
       return true;
   }      
}

void idSearch(){
cout<<fixed<<setprecision(2);


int id;

cout<<"Enter an ID value to search for: ";
cin>>id;
cout<<endl<<endl;	
getRecord(studentlist.recNum, studentinfo.id, studentinfo.fname, studentinfo.lname, studentinfo.email, studentinfo.gpa);

for (int i = 0; i<100; i++){
	if (id==studentlist.arraystudent[i].id){
			cout<<"Record"<<endl;
			cout<<" Student ID: "<<studentlist.arraystudent[i].id<<endl;
			cout<<" Student Name: "<<studentlist.arraystudent[i].fname<<" "<<studentlist.arraystudent[i].lname<<endl;
			cout<<" Student Email: "<<studentlist.arraystudent[i].email<<endl;
			cout<<" Student GPA: "<<studentlist.arraystudent[i].gpa<<endl<<endl;
}
}
}

void nameSearch(){

cout<<fixed<<setprecision(2);
int i;
bool searching = true;
char name[20];

cout<<"Enter a last name to search for: ";

cin.getline(name,'\n');


cout<<endl<<endl;	

for ( i = 0; i<100; i++){
	
	if ((strcmp(studentlist.arraystudent[i].lname,name)==0)){
			cout<<"Record"<<endl;
			cout<<"Student ID: "<<studentlist.arraystudent[i].id<<endl;
			cout<<"Student Name: "<<studentlist.arraystudent[i].fname<<" "<<studentlist.arraystudent[i].lname<<endl;
			cout<<"Student Email: "<<studentlist.arraystudent[i].email<<endl;
			cout<<"Student GPA: "<<studentlist.arraystudent[i].gpa<<endl<<endl;
			searching = false;
			break;
		}	
	

}

if ((strcmp(studentlist.arraystudent[i].lname,name)>0)||(strcmp(studentlist.arraystudent[i].lname,name)<0)) 
	cout<<"Name not found \a"<<endl;



printMenu();

}

void printStudents(){

cout<<fixed<<setprecision(2);


for (int i = 0; i < 6 ;i++){
	
cout<<setprecision(2);
	
cout<<endl;
cout<<"Record"<<endl;
cout<<" Student ID:"<<studentlist.arraystudent[i].id<<endl;
cout<<" Student Name:"<<studentlist.arraystudent[i].fname << " " <<studentlist.arraystudent[i].lname<<endl;
cout<<" Student Email:"<<studentlist.arraystudent[i].gpa<<endl;
cout<<" Student GPA:"<<studentlist.arraystudent[i].email<<endl<<endl;

}
printMenu();
}


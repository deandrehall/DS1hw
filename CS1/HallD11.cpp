//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <new>
#include <cctype>
#include <string>

using namespace std;
ifstream myfile;

struct student{
	int id;
	char fname[20];
	char lname[20];
	double balance;
}studentinfo;

/*
struct roster{
	int recNum;
	student arraystudent[100];
}studentlist;
*/

class roster{
public:
	int recNum;
	student arraystudent[100];
	bool getRecord(int& recNum, int& id, char fname[], char lname[], double& balance);
	void scanfile();
	void printMenu();
	void idSearch();
	void nameSearch();
	void printStudents();
	void newstudent();
	void deletestudent();
	void save();

}studentlist;



int main(){

studentlist.scanfile();
studentlist.printMenu();

system("pause");
return 0;
}

void roster::scanfile(){

int i = 0;	

for (int j = 0; j<100; j++){
studentlist.getRecord(studentlist.recNum, studentlist.arraystudent[i].id,studentlist.arraystudent[i].fname, studentlist.arraystudent[i].lname, studentlist.arraystudent[i].balance);
i++;
}

}

void roster::printMenu(){

int choice;	
	
cout<<"Class Roster"<<endl
<<"Total Students = "<< studentlist.recNum << endl<<endl;

while(true){

cout<<"1. Display all students"<<endl;
cout<<"2. Search for student by ID"<<endl;
cout<<"3. Add a new student"<<endl;
cout<<"4. Delete a student by ID"<<endl;
cout<<"5. Save student record into file"<<endl;
cout<<"6. Exit"<<endl;
cout<<">>";
cin>>choice;
cin.ignore(256,'\n');
cout<<endl;

switch(choice){
	case 1: printStudents();break;
	case 2: idSearch();break;
	case 3: newstudent();break;
	case 4: deletestudent();break;
	case 5: save();break;
	case 6: exit(1);
	default: cout<<"Please re-enter a correct choice. "<<endl<<endl;
}

}
}

bool roster::getRecord(int& recNum, int& id, char fname[], char lname[],  double& balance){
   if (recNum==0) {
      myfile.open("prog11in.txt");
      
      if (myfile.fail()){
         cout<<"File \"prog11in.txt\" failed to open."<<endl;
         system("pause"); 
    	 exit(1);
         
      } else {
	  		cout<<"File \"prog11in.txt\" opened."<<endl;
 			 }
   }         
   myfile >>id >>fname >>lname >>balance;
   if (myfile.eof()) return false;
   else {
       recNum++;
       return true;
   }      
}

void roster::idSearch(){
cout<<fixed<<setprecision(2);

int id;

cout<<"Enter an ID value to search for: ";
cin>>id;
cout<<endl<<endl;	
getRecord(studentlist.recNum, studentinfo.id, studentinfo.fname, studentinfo.lname, studentinfo.balance);

for (int i = 0; i<100; i++){
	if (id==studentlist.arraystudent[i].id){
			cout<<"Record"<<endl;
			cout<<" Student ID: "<<studentlist.arraystudent[i].id<<endl;
			cout<<" Student Name: "<<studentlist.arraystudent[i].fname<<" "<<studentlist.arraystudent[i].lname<<endl;
			cout<<" Student balance: "<<studentlist.arraystudent[i].balance<<endl<<endl;
}
}
}

void roster::nameSearch(){

cout<<fixed<<setprecision(2);
int i;
bool searching = true;
string name;

cout<<"Enter a last name to search for: ";

getline(cin, name);


cout<<endl<<endl;	

for ( i = 0; i<100; i++){
	
	if (studentlist.arraystudent[i].lname==name){
			cout<<"Record"<<endl;
			cout<<"Student ID: "<<studentlist.arraystudent[i].id<<endl;
			cout<<"Student Name: "<<studentlist.arraystudent[i].fname<<" "<<studentlist.arraystudent[i].lname<<endl;
			cout<<"Student Balance: "<<studentlist.arraystudent[i].balance<<endl<<endl;
			searching = false;
			break;
		}	
	

}

if (studentlist.arraystudent[i].lname!=name) cout<<"Student not found.";
cout<<endl;


printMenu();

}

void roster::printStudents(){

cout<<fixed<<setprecision(2);


for (int i = 0; i < recNum ;i++){
	
cout<<setprecision(2);
	
cout<<endl;
cout<<"Record"<<endl;
cout<<" Student ID:"<<studentlist.arraystudent[i].id<<endl;
cout<<" Student Name:"<<studentlist.arraystudent[i].fname << " " << studentlist.arraystudent[i].lname<<endl;
cout<<" Student GPA:"<<studentlist.arraystudent[i].balance<<endl<<endl;

}
printMenu();
}

void roster::newstudent(){
	int ID;
	char fname[20];
	char lname[20];
	double balance;
	
	ofstream myfile;
	
	//studentlist.recNum++;
	
	cout<<"Enter ID: ";
	cin>>studentlist.arraystudent[studentlist.recNum].id;
	cout<<endl;
	
	cout<<"Enter first name: ";
	cin>>studentlist.arraystudent[studentlist.recNum].fname;
	cout<<endl;
	
	cout<<"Enter last name: ";
	cin>>studentlist.arraystudent[studentlist.recNum].lname;
	cout<<endl;
	
	cout<<"Enter gpa: ";
	cin>>studentlist.arraystudent[studentlist.recNum].balance;
	cout<<endl;
	
	myfile.open("prog10in.txt",ios::app);
	myfile<<endl;
	myfile<<ID<<" "<<studentlist.arraystudent[studentlist.recNum].fname<<" "<<studentlist.arraystudent[studentlist.recNum].lname<<" "<<balance<<endl;
	myfile.close();
	
	studentlist.recNum++;
	scanfile();
	
}

void roster::deletestudent(){
string fname,lname;
int id,target;
double balance;
bool check=false;

cout<<"Enter an ID value to search for: ";
cin>>target;

ifstream list("prog11in.txt");
ofstream copy("copyfile.txt");

while(list>>id>>fname>>lname>>balance){
	
	if(target!=id){
	copy<<endl;
	copy<<id<<" "<<fname<<" "<<lname<<" "<<balance<<endl;
	}
	else check=true;
}
list.clear();
list.seekg(0, ios::beg);
list.close();
copy.close();
delete("prog11in.txt");
rename("copyfile.txt","prog11in.txt");
studentlist.recNum--;
scanfile();

if(check==true) cout<<"The student was sucessfully deleted"<<endl<<endl;
else cout<<"Student data not found."<<endl<<endl;

	
}

void roster::save(){
myfile.close();
cout<<"Saved successfully"<<endl<<endl;
}


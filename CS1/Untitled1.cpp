#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
// Put global constants and variable (limited to one) here
ifstream inStream;



// Definfe the two structs
struct student{int ID;char fname[20];char lname[20];char email[40]; double gpa;} identity;

struct roster{student students[100]; int curRoster;} roster;

 
// list all function prototypes here 
bool getRecord(int& recNum, int& id, char fname[], char lname[], char email[], double& gpa);

void menu();

void name();

void IDs();

void students();


int main(){
    int x=0;
    
    for(int y=0; y<100 ; y++){
            
    getRecord(roster.curRoster, roster.students[x].ID,roster.students[x].fname,roster.students[x].lname,
    roster.students[x].email,roster.students[x].gpa);  x++;  }
    
    menu();
            
    
    
    cout<<endl<<endl;
    
system("pause");
}

// List all function definitions here
void menu(){
     bool done=true;
     
     while(done){
                 
     cout<<endl;
                 
     int option;
     cout<<"1. Display all students"<<endl;
     cout<<"2. Search for student by ID"<<endl;
     cout<<"3. Search for student by name"<<endl;
     cout<<"4. Exit"<<endl;
     cin>>option; cout<<endl;
     switch (option){
     case 1: students();break;
     case 2: IDs();break;
     case 3: name();break;
     case 4: exit(0);break;}} }
     
     
     

void name(){
	
	cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);
    int x;
     char name[20];
     
     cout<<"Enter a last name to search: "; 
    // cin.get(name); 
     cin.getline(name,'\n');
      cout<<endl;
    // cin.get();
     

for ( x = 0; x<100; x++){
	
	if ((strcmp(roster.students[x].lname,name)==0)){
			cout<<"Record"<<endl;
			cout<<"Student ID: "<<roster.students[x].ID<<endl;
			cout<<"Student Name: "<<roster.students[x].fname<<" "<<roster.students[x].lname<<endl;
			cout<<"Student Email: "<<roster.students[x].email<<endl;
			cout<<"Student GPA: "<<roster.students[x].gpa<<endl<<endl;
		
			break;
		}	
		   
		   } 
           }
           

     
     
     

void IDs(){
     cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);

     int IDvalue;
     cout<<"Enter an ID value to search: "; cin>>IDvalue;
     
for(int x=0; x<100; x++){
        if (IDvalue==roster.students[x].ID){
           cout<<"Record"<<endl;
           cout<<"  Student ID:    "<< roster.students[x].ID<<endl;
           cout<<"  Student Name:  "<<roster.students[x].fname<<" "<<roster.students[x].lname<<endl;
           cout<<"  Student Email: "<<roster.students[x].email<<endl;
           cout<<"  Student GPA:   "<<roster.students[x].gpa<<endl; } } }
           
        

void students(){
     cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);

     for(int x=0; x<roster.curRoster+1; x++){
           cout<<"Record"<<endl;
           cout<<"  Student ID:    "<< roster.students[x].ID<<endl;
           cout<<"  Student Name:  "<<roster.students[x].fname<<" "<<roster.students[x].lname<<endl;
           cout<<"  Student Email: "<<roster.students[x].email<<endl;
           cout<<"  Student GPA:   "<<roster.students[x].gpa<<endl;
           cout<<endl; } } 


bool getRecord(int& curRoster, int& id, char fname[], char lname[], char email[], double& gpa){
   if (curRoster==0) {
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
       curRoster++;
       return true;
   }      
}

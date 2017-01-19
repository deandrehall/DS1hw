//Deandre Hall - 1241692

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string>
#include <new>
using namespace std;

void printMenu();

class person
{
	protected:
		string fName, lName, address, zip, phone;
	public:
		
		person(string firstname="", string lastname="", string add="", string zipcode="", string phonenum=""){
			
		};
		
		void setFirstName(){
			cout<<"Enter first name: ";
			cin >> this->fName;
			cout<<endl;
		}
		
		void setLastName(){
			cout<<"Enter last name: ";
			cin >> this->lName;
			cout<<endl;
		}
		
		void setAddress(){
			cout<<"Enter address: ";
			cin >> this->address;
			cout<<endl;
		}
		
		void setZip(){
			cout<<"Enter zip Code: ";
			cin >> this->zip;
			cout<<endl;
		}
		
		void setPhone(){
			cout<<"Enter phone number: ";
			cin >> this->phone;
			cout<<endl;
		}
		
		void setData(){
			
			setFirstName();
			setLastName();
			setAddress();
			setZip();
			setPhone();	
			
		}
		
		void Display(){
			cout<<"First Name: "<<this->fName<<endl;
			cout<<"Last Name: "<<this->lName<<endl;
			cout<<"Address: "<<this->address<<endl;
			cout<<"Zip code: "<<this->zip<<endl;
			cout<<"Phone number:"<<this->phone<<endl<<endl;
		}
		
};

class collegeEmployee: public person
{
	private:
		string SSnumber, salary, deptName;
	public:
		
		collegeEmployee(string firstname="", string lastname="", string add="", string zipcode="", string phonenum="", string SS="", string anualSal="", string department="")
		:person(firstname, lastname,add,zipcode,phonenum)
		{
		
			
		};
		
		void setSSnumber(){
			
			cout<<"Enter Social Security Number: ";
			cin>>this->SSnumber;	
			cout<<endl;
			
		}
		
		void setSalary(){
			cout<<"Enter Annual Salary: ";
			cin>>this->salary;	
			cout<<endl;
		}
		
		void setDeptName(){
			cout<<"Enter Department Name: ";
			cin>>this->deptName;	
			cout<<endl;
		}
		
		void setData(){
			
			setFirstName();
			setLastName();
			setAddress();
			setZip();
			setPhone();	
			setSSnumber();
			setSalary();
			setDeptName();
			
		}
		
		void Display(){
			
			cout<<"First Name: "<<this->fName<<endl;
			cout<<"Last Name: "<<this->lName<<endl;
			cout<<"Address: "<<this->address<<endl;
			cout<<"Zip code: "<<this->zip<<endl;
			cout<<"Phone number:"<<this->phone<<endl<<endl;
			cout<<"Social Security Number: "<<this->SSnumber<<endl;
			cout<<"Salary: "<<this->salary<<endl;
			cout<<"Department Name: "<<this->deptName<<endl;
			
		}
		
};

class student: public person
{
	protected:
		string major, fieldOfStudy, gpa;
	public:
		student(string firstname="", string lastname="", string add="", string zipcode="", string phonenum="", string maj="", string study="", string GPA="")
		:person(firstname, lastname,add,zipcode,phonenum)
		{
		
			
		};
		
		void setMajor(){
			
			cout<<"Enter Major: ";
			cin>>this->major;	
			cout<<endl;
		}
		
		
		void setStudy(){
			cout<<"Enter Field of Study: ";
			cin>>this->fieldOfStudy;	
			cout<<endl;
		}
		
		void setGpa(){
			cout<<"Enter GPA: ";
			cin>>this->gpa;	
			cout<<endl;
		}
		
		void setData(){
			
			setFirstName();
			setLastName();
			setAddress();
			setZip();
			setPhone();	
			setMajor();
			setStudy();
			setGpa();
			
		}
		
		void Display(){
			
			cout<<"First Name: "<<this->fName<<endl;
			cout<<"Last Name: "<<this->lName<<endl;
			cout<<"Address: "<<this->address<<endl;
			cout<<"Zip code: "<<this->zip<<endl;
			cout<<"Phone number:"<<this->phone<<endl;
			cout<<"Major: "<<this->major<<endl;
			cout<<"Field of Study: "<<this->fieldOfStudy<<endl;
			cout<<"GPA: "<<this->gpa<<endl;
		}
};

class faculty: public collegeEmployee
{
	protected:
		bool isTenured;
	public:
		faculty(string firstname="", string lastname="", string add="", string zipcode="", string phonenum="", string SS="", string anualSal="", string department="")
		:collegeEmployee(firstname, lastname, add, zipcode, phonenum, SS, anualSal, department)
		{
			
			
		
	    };
	    
	   	bool setTenure()
		{
			char answer;
			cout<<"Is this faculty member tenured? (Y/N): ";
			cin>>answer;
			
			if (answer=='Y'||answer=='y') this->isTenured = true;
			else this->isTenured = false;
			
			cout<<endl;
		}
		
		void setData(){
			
			setFirstName();
			setLastName();
			setAddress();
			setZip();
			setPhone();	
			setSSnumber();
			setSalary();
			setDeptName();
			setTenure();
		}
		
		void Display(){
			
			cout<<"First Name: "<<this->fName<<endl;
			cout<<"Last Name: "<<this->lName<<endl;
			cout<<"Address: "<<this->address<<endl;
			cout<<"Zip code: "<<this->zip<<endl;
			cout<<"Phone number:"<<this->phone<<endl;
			cout<<"Tenure: "<<this->isTenured<<endl;
			
		}
};


int main() {

collegeEmployee emp[4];
faculty fac[3];
student stud[7];

///// Menu
int choice;	
int empCounter=0;
int facCounter=0;
int studCounter=0;	
while(true){

cout<<"1. Input CollegeEmployee"<<endl;
cout<<"2. Input Faculty"<<endl;
cout<<"3. Input Student"<<endl;
cout<<"4. Exit"<<endl;
cout<<">>";
cin>>choice;
cin.ignore(256,'\n');
cout<<endl;

switch(choice){
	
	case 1: {
	if(empCounter>=4) {
	cout<<"Too many College Employees"<<endl;
	break;
	}
	emp[empCounter].setData();
	empCounter++;
	break;
	}
	
	case 2: {
	if(facCounter>=3) {
	cout<<"Too many College Employees"<<endl;
	break;
	}
	 fac[facCounter].setData();
	 facCounter++;
	 break;
	}
	
	case 3: { 
	if(studCounter>=7) {
	cout<<"Too many College Employees"<<endl;
	break;
	}
	stud[studCounter].setData();
	facCounter++;
	break;
	}	
  	case 4:{
  	
  if(empCounter==0) cout<<"No College Employees to display"<<endl;
  if(facCounter==0) cout<<"No Faculty to display"<<endl;
   if(studCounter==0) cout<<"No Students Employees to display"<<endl;
  	
  	for(int i=0;i<empCounter;i++){
  		cout<<"College Employees////////// "<<endl;
  		emp[i].Display();
  		cout<<endl<<endl;
	}
  	for(int i=0;i<facCounter;i++){
  		cout<<"Faculty//////////////"<<endl;
  		fac[i].Display();
  		cout<<endl<<endl;
  	}
  	for(int i=0;i<studCounter;i++){
  		cout<<"Studnets///////////"<<endl;
  		stud[i].Display();
  		cout<<endl<<endl;
  	}
  	
  	
			exit(1);
    }
	default: cout<<"Please enter a correct choice. "<<endl<<endl;
}

}


system("pause");
return 0;

}







//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>

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



int main(){
	
int i = 0;	

for (int j = 0; j<7; j++){
getRecord(studentlist.recNum, studentlist.arraystudent[i].id,studentlist.arraystudent[i].fname, studentlist.arraystudent[i].lname, studentlist.arraystudent[i].email, studentlist.arraystudent[i].gpa);
i++;
}
cout<<endl;

for (int i = 0; i <6;i++){
	


cout<<"i = "<<i<<endl;
cout<<studentlist.arraystudent[i].id<<endl;
cout<<studentlist.arraystudent[i].fname << " " <<studentlist.arraystudent[i].lname<<endl;
cout<<studentlist.arraystudent[i].gpa<<endl;
cout<<studentlist.arraystudent[i].email<<endl<<endl;


}

system("pause");
return 0;
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

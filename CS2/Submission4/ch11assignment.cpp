	    #include <iostream>
    #include <string>
    using namespace std;
     
    class Student
    {
    	private:
    		string studFirstName,studLastName;
    		float studExam1, studExam2,studExam3,studAvg;
    		char studGrade;
     
    	public:
     
    		Student(string fn="", string ln = "", float e1 = 0, float e2 = 0, float e3 = 0){
				studFirstName=fn;
				studLastName=ln;
				studExam1=e1;
				studExam2=e2;
				studExam3=e3;
			} //Constructor
     
    		float computeAvg(float e1, float e2, float e3);
    		void displayGrade(float avg);
    		void setValues(string fn, string ln, float e1, float e2, float e3);
     
    };
    
    class gradStudent: public Student
    {	
    	private:
    		string bsDegreeName,progName;
    		float bsGPA;
    		
    	public:
    		gradStudent(string fn, string ln, float e1, float e2, float e3, string degreeName, string prog, float GPA);
    		
    		
    	
	};
    
   gradStudent::gradStudent(string fn="", string ln = "", float e1 = 0, float e2 = 0, float e3 = 0, string degreeName="", string prog="", float GPA=0)
    		:Student(fn,ln,e1,e2,e3)
    {
    	bsDegreeName=degreeName;
    	progName=prog;
    	bsGPA=GPA;
	}
    
    float Student::computeAvg(float ex1, float ex2, float ex3){
    	
    	studAvg=(studExam1 + studExam2 + studExam3)/3;
    	return studAvg;
    	
    }
    
    void Student::displayGrade(float avg){
    	
    float GPA = 0;
	
    	if (avg >= 90){
			studGrade = 'A';
			GPA=4;
		}
		else if (avg >= 80){
			studGrade = 'B';
			GPA=3;
		}
		else if (avg >= 70){
			studGrade = 'C';
			GPA=2;
		}
		else if (avg >= 60){
			studGrade = 'D';
			GPA=1;
		}
		else{
			studGrade = 'F';
			GPA=0;
		}
		
	cout << "\t Average: " << avg << " -> " << studGrade << endl;
	cout << "\t GPA: " << GPA <<endl<<endl;
		
	}

    int main(){
    	
    string fName, lName, degreeName, prog;
    float ex1, ex2, ex3, avg, GPA;
    gradStudent objStud;
 
    	
    		cout << "Enter the student's first and last name: ";
			cin >> fName >> lName;
			cout << endl;
			cout << "Enter the first three exam grades: ";
			cin >> ex1 >> ex2 >> ex3;
    		cout << endl;
    		cout << "Enter the degree and program name: ";
    		cin >> degreeName >> prog;
    		cout<< endl;
    		
    		
    		objStud = gradStudent(fName,lName,ex1,ex2,ex3,degreeName,prog,GPA);
    		avg=objStud.computeAvg(ex1,ex2,ex3);
    		objStud.displayGrade(avg);
    	

    	return 0;
    }

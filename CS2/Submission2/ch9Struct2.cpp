//Deandre Hall
//w207047058


#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string studFirstName, studLastName;

	int studExam1, studExam2, studExam3; // 0 - 100

	double studAvg;

	char studGrade;	// A-F
};

int main() {

	Student stud[3];
	char Grade;
	int highestAvg = stud[0].studAvg;

	for (int i = 0; i <3; i++)
	{
		//Input data
		cout << "Enter student's first and last name: ";
		cin >> stud[i].studFirstName >> stud[i].studLastName;
		cout << "Enter three Exams: ";
		cin >> stud[i].studExam1 >> stud[i].studExam2 >> stud[i].studExam3;

		//Process data
		stud[i].studAvg = (stud[i].studExam1 + stud[i].studExam2 + stud[i].studExam3) / 3;

		if (stud[i].studAvg >= 90)
			Grade = 'A';
		else if (stud[i].studAvg >= 80)
			Grade = 'B';
		else if (stud[i].studAvg >= 70)
			Grade = 'C';
		else if (stud[i].studAvg >= 60)
			Grade = 'D';
		else
			Grade = 'F';

		stud[i].studGrade = Grade;

		
		for (int i = 0; i < 3; i++){
			if (highestAvg < stud[i].studAvg)
				highestAvg = stud[i].studAvg;
		}

		//Add the code to display the Student record for each student.
	}
		
	for (int i = 0; i < 3; i++)
	{
		cout << "Student[" << i + 1 << "] :" << endl;
		cout << "\t" << stud[i].studFirstName << " " << stud[i].studLastName << endl;
		cout << "\t Exams: " << stud[i].studExam1 << " " << stud[i].studExam2 << " " << stud[i].studExam3 << endl;

		if (highestAvg == stud[i].studAvg)
			cout << "\t Average: "  << stud[i].studAvg << " -> " << stud[i].studGrade << " ** HIGHEST AVG **" << endl;
		else
			cout << "\t Average: " << stud[i].studAvg << " -> " << stud[i].studGrade << endl;
	}



	system("pause");
	return 0;
}

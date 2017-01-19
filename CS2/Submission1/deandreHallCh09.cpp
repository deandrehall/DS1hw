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

	Student stud1;
	char Grade;

	for (int i = 0; i <3; i++)
	{
		//Input data
		cout << "Enter student's first and last name: ";
		cin >> stud1.studFirstName >> stud1.studLastName;
		cout << "Enter three Exams: ";
		cin >> stud1.studExam1 >> stud1.studExam2 >> stud1.studExam3;

		//Process data
		stud1.studAvg = (stud1.studExam1 + stud1.studExam2 + stud1.studExam3) / 3;

		if (stud1.studAvg >= 90)
			Grade = 'A';
		else if (stud1.studAvg >= 80)
			Grade = 'B';
		else if (stud1.studAvg >= 70)
			Grade = 'C';
		else if (stud1.studAvg >= 60)
			Grade = 'D';
		else
			Grade = 'F';

		stud1.studGrade = Grade;
		//Add the code to display the Student record for each student.

		cout << endl << endl;
		cout << "\t" << stud1.studFirstName << " " << stud1.studLastName << endl;
		cout << "\t Exams: " << stud1.studExam1 << " " << stud1.studExam2 << " " << stud1.studExam3 << endl;
		cout << "\t Average: " << stud1.studAvg << " -> " << stud1.studGrade << endl;
		cout << endl << endl;

	}

	system("pause");
	return 0;
}

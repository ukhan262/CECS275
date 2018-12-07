/*
Umar Khan
014477331
CECS 275
Program 4
Scantron Program Using Classes
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// constant variables
const int  MAXQUESTIONS = 50;
const int  MAXSTUDENTS = 30;

// class definition
class Student
{
	// class private variables
private:
	int studId;
	int score;
public:

	// constructor with zero parameters
	Student()
	{
		studId = 0;
		score = 0;
	}

	// constructor with two parameters
	Student(int id, int marks)
	{
		studId = id;
		score = marks;
	}

	// setter methods to set the values
	// of the private variables
	void setStudId(int id)
	{
		studId = id;
	}

	void setScore(int marks)
	{
		score = marks;
	}

	// getter methods to get the values of the
	// private variables
	int getStudId()
	{
		return studId;
	}

	int getScore()
	{
		return score;
	}

	// print() method to print the student id and score in
	// a format.
	void print()
	{
		cout << studId << setw(15) << score << "\n";
	}
};

// functions to sort the students array and to print the requried information in the given format
void sortStudentArray(Student *students, int size);
void printAllStudentData(Student *students, int size);

// main function
int main()
{
	// create the student objects
	Student *students;

	// initialize the array
	students = new Student[MAXSTUDENTS];

	// declare the int pointer to hold the correct answers
	int *correctAnswers;

	// declare and initialize the variable to hold the number of
	// values read from the file
	int size = 0;
	int score = 0;

	// create the file object
	ifstream fileIn("lab4.txt");

	// declare the other required variables
	int numQuestions;
	int studId; 

	// to keep count of the correct answers
	int correct = 0;

	// if file in unble to open then
	// print an error message and stop the application
	if(!fileIn)
	{
		cout << "Unable to open the file. Try again later!\n\n";
		system("Pause");
		return 0;
	}

	// read the number of questions value from the 
	// text file present at the first line
	fileIn >> numQuestions;

	// initialize the array questions
	correctAnswers = new int[numQuestions];

	// variable used to read each answer of the student read from the file
	int quest = 0;

	// loop to read the correct answers from the second line of the file
	for(int i = 0; i < numQuestions; i++)
	{
		fileIn >> correctAnswers[i];
	}

	// loop till end of the file is reached
	while(!fileIn.eof())
	{	
		// set correct variable to zero
		correct = 0;

		// read the student id from the file
		fileIn >> studId;

		// loop to read the each answer of the student provided
		for(int i = 0; i < numQuestions; i++)
		{
			// read the test answer
			fileIn >> quest;

			// check against the correct answer
			if(quest == correctAnswers[i])
				// if matches increment the correct variable by 1
				correct++;
		}

		// now find the total score by multiplying each correct answer by 5
		score = correct * 5;

		// set the student id and final score of the student
		students[size].setStudId(studId);
		students[size].setScore(score);

		// increment the size
		size++;
	}
	fileIn.close();

	// call the printAllStudentsData() function by passing the students array and size
	printAllStudentData(students, size);
	system("pause");
	return 0;
}

// definition of the sortStudentArray(): This accepts a student class array pointer and
// its size. This function is used to sort the array with respect to the student score
void sortStudentArray(Student *students, int size)
{
	// declare the student object temp 
	Student temp;

	// loop through each value of student
	for(int i = 0; i < size; i++)
	{
		// loop to swap the values if the current student value is lesser than next student scores
		for(int j = 0; j < size - 1; j++)
		{
			// condition to check the score of the student at j is less than
			// score of the student at j+1
			if(students[j].getScore() < students[j + 1].getScore())
			{
				// if the condition is true swap the values
				temp = students[j];
				students[j] = students[j+1];
				students[j+1] = temp;
			}
		}
	}
}

// printAllStudentData() function:  This accepts a student class array pointer and
// its size. This function is used print the sorted student data, frequency of each score
// and average score of the class
void printAllStudentData(Student *students, int size)
{
	// call the sortStudentArray() function by passing the array and size
	sortStudentArray(students, size);

	// declare and define the required variables
	int  totalScore = 0;
	int average = 0;
	int *valuesScores = new int[20];
	int j = 0;
	int *frequency;

	// print the header
	cout << "Student ID" << setw(10) << "Score" << endl;
	cout << "==============================" << endl;

	// print the values of student id and score
	for(int i = 0; i < size; i++)
	{
		students[i].print();
	}
	cout << "==============================" << endl;

	// print the number of students taken test
	cout << "Tests Graded = " << size << endl;
	cout << "==============================" << endl;
	
	// create the frequency array
	frequency = new int[MAXQUESTIONS * 4];

	// intialize the frequency with 0
	for(int i = 0; i < MAXQUESTIONS * 4; i++)
	{
		frequency[i] = 0;
	}
	
	// find the frequency of each score
	for(int i = 0; i < size; i++)
	{	
		// logic to get the unique score values
		if(frequency[students[i].getScore()] == 0)
		{
			valuesScores[j] = students[i].getScore();
			j++;
		}

		// logic to increment the count of the score found
		frequency[students[i].getScore()]++;
	}

	// loop through unique values 
	for(int i = 0; i < j; i++)
	{	
		// display the value and its frequency
		cout  << valuesScores[i] <<"\t"<<frequency[valuesScores[i]]<< endl;

		// calculate the total score secured by the overall students
		totalScore += valuesScores[i] * frequency[valuesScores[i]];
	}
	cout << "==============================" << endl;

	// calculate the average score
	average = totalScore / size;

	// display the average
	cout << "Class Average = " << average << endl;
	cout << "==============================" << endl << endl;
}


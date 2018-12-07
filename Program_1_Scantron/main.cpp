/*
Umar Khan
CECS 275
Program 1
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// readAnswers function implementation
// a single function (called with different parameters) 
// to read the answer key and the student responses
void readAnswers(ifstream &infile, int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		infile >> arr[i];
	}
}

// computeTotalScore function implementation
// a function that take the answer key and student response as parameters 
// and then computes the score for that student 
// The score is returned as int by the function.
int computeTotalScore(int answers[], int responses[], int numberOfQuestions)
{
	int totalScore = 0;
	int correctAnswers = 0;

	for (int i = 0; i < numberOfQuestions; i++)
	{
		if (answers[i] == responses[i])
			correctAnswers++;
	}

	totalScore = correctAnswers * (100 / numberOfQuestions);

	return totalScore;
}


// start main function
int main()
{
	// asks the user for the name of the file
	string filename;
	cout << "Enter file name: ";
	cin >> filename;

	// open the input file
	ifstream infile;
	infile.open(filename.c_str());

	// return from the program if the input file does not exist
	if (!infile)
	{
		cout << filename << " file does not exist!" << endl;
		return 1;
	}

	// create the arrays
	int scoresFrequency[101] = {0}; // a score frequency count
	int answers[51]; // array for correct answers
	int responses[51]; // array for user answers

	// declare the required variables
	int numberOfQuestions;
	int studentID;
	int studentTotalScore;
	int classTotalScore = 0;
	int classAverage = 0;
	int testsGraded = 0;	

	// read the number of questions and correct answers from the file
	infile >> numberOfQuestions;
	if (infile)
	{
		// call the readAnswers function
		readAnswers(infile, answers, numberOfQuestions);
	}

	cout << endl << left << setw(12) << "Student ID" << right << setw(7) << "Score" << endl;
	cout << "===================" << endl;

	// read the student's id and student's answers from the file
	infile >> studentID;
	while (infile)
	{
		// call the readAnswers function
		readAnswers(infile, responses, numberOfQuestions);

		// call the computeTotalScore function
		studentTotalScore = computeTotalScore(answers, responses, numberOfQuestions);
		
		// increment the counter of frequency count
		scoresFrequency[studentTotalScore]++;

		// calculate the class total score
		classTotalScore += studentTotalScore;

		// count tests graded
		testsGraded++;

		// print the student's id and student's total score
		cout << left << setw(12) << studentID << right << setw(5) << studentTotalScore << endl;

		// read the next student's id
		infile >> studentID;
	}

	// calculate the class average
	classAverage = classTotalScore / testsGraded;
	
	// print the tests graded
	cout << "===================" << endl;
	cout << "Tests graded = " << testsGraded << endl;
	cout << "===================" << endl;

	// print the scores frequency count
	cout << left << setw(7) << "Score" << right << setw(12) << "Frequency" << endl;
	cout << "===================" << endl;
	for (int i = 100; i >= 0; i--)
	{
		if (scoresFrequency[i] > 0)
		{
			cout << setw(3) << i << setw(12) << scoresFrequency[i] << endl;
		}
	}
	cout << "===================" << endl;

	// print the class average
	cout << "Class Average = " << classAverage << endl << endl;

	infile.close();

	system("pause");
	return 0;
}


/*
Umar Khan
014477331
CECS 275
03/14/2017
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_SCORE = 100;

//function prototype
bool readarray(fstream &, int[], int);
int gradeOneTest(int[], int[], int);


//declaring first struct Student
struct student {
	int studentid;
	int grade;
};
//declaring the second struct Class
struct Class{
	int size;
	student maximumStudents_ID_Scores[50];
};

int main() {
	struct Class NumofStudents;
	fstream infile;
	int key[50], answers[50], num_questions;
	int frequency[101] = { 0 };
	NumofStudents.size = 0;
	double average = 0;
	string filename;
	int count = 0;

	cout << "Enter file name:";
	cin >> filename;

	infile.open(filename, ios::in);

	infile >> num_questions;

	readarray(infile, key, num_questions);

	cout << "Student ID    Score" << endl;
	cout << "===================" << endl;


	while (!infile.eof()) {
		infile >> NumofStudents.maximumStudents_ID_Scores[NumofStudents.size].studentid;
		readarray(infile, answers, num_questions);
		NumofStudents.maximumStudents_ID_Scores[NumofStudents.size].grade = gradeOneTest(key, answers, num_questions);
		frequency[NumofStudents.maximumStudents_ID_Scores[NumofStudents.size].grade]++;
		average += NumofStudents.maximumStudents_ID_Scores[NumofStudents.size].grade;
		NumofStudents.size = NumofStudents.size + 1;
		count++;
	}

	//bubble sort referencing C++ library and AlgoList website
	bool swapped = true;
	int j = 0;
	int tmp;
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < count - j; i++) {
			if (NumofStudents.maximumStudents_ID_Scores[i].grade < NumofStudents.maximumStudents_ID_Scores[i + 1].grade) {
				//grades assigned in the descending order followed by the Student ID
				tmp = NumofStudents.maximumStudents_ID_Scores[i].grade;
				NumofStudents.maximumStudents_ID_Scores[i].grade = NumofStudents.maximumStudents_ID_Scores[i + 1].grade;
				NumofStudents.maximumStudents_ID_Scores[i + 1].grade = tmp;
				tmp = NumofStudents.maximumStudents_ID_Scores[i].studentid;
				NumofStudents.maximumStudents_ID_Scores[i].studentid = NumofStudents.maximumStudents_ID_Scores[i + 1].studentid;
				NumofStudents.maximumStudents_ID_Scores[i + 1].studentid = tmp;
				swapped = true;
			}
		}
	}

	//This is to display the grades corresponding with their ID after the sort
	for (int i = 0; i < count; i++) {
		cout << NumofStudents.maximumStudents_ID_Scores[i].studentid << setw(12) << NumofStudents.maximumStudents_ID_Scores[i].grade << endl;
	}
	//Displaying the header of the file	
	cout << "===================" << endl;
	cout << "Tests graded = " << NumofStudents.size << endl;
	cout << "===================" << endl;
	cout << "Score" << setw(14) << "Frequency" << endl;
	cout << "===================" << endl;

	//counting the frequency of the scores repeated in this  loop
	for (int i = 100; i > 0; i--) {
		if (frequency[i] != 0)
			cout << setw(3) << i << setw(12) << frequency[i] << endl;
	}
			cout << "===================" << endl;

	//Displaying the average for the scores in the class
	cout << "Class Average = " << average / NumofStudents.size << endl;
	system("pause");
	return 0;
}
bool readarray(fstream &file, int array[], int size) {
	for (int i = 0; i< size; i++)
		file >> array[i];
	return file.eof();
}

int gradeOneTest(int key[], int answers[], int size) {
	int misses = 0;

	for (int i = 0; i< size; i++)
		if (key[i] != answers[i])
			misses++;
	return MAX_SCORE - (MAX_SCORE / size) * misses;
}
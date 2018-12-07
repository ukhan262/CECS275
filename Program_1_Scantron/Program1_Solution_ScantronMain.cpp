#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_SCORE = 100;

bool readarray(fstream &file, int array[], int size){
	for(int i=0; i< size; i++)
		file >> array[i];
	return file.eof();
}

int gradeOneTest(int key[], int answers[],  int size){
	int misses = 0;

	for(int i=0; i< size; i++)
		if(key[i] != answers[i])
			misses++;
	return MAX_SCORE - (MAX_SCORE/size) * misses;
}


int main(){
	fstream infile;
	int key[50], answers[50], num_questions;
	int frequency[101] = {0};
	int studentID, score, numTests=0;
	double average=0;
	string filename;

	cout << "Enter file name:";
	cin >> filename;

	infile.open(filename, ios::in);

	infile >> num_questions;

	readarray(infile, key, num_questions);
	
	cout << "Student ID    Score" << endl;
	cout << "===================" << endl;
	while(!infile.eof()){
		infile >> studentID;
		readarray(infile, answers, num_questions);
		score = gradeOneTest(key, answers,num_questions) ;
		frequency[score]++;
		average += score;
		cout << studentID << setw(12) << score << endl;
		numTests++;
	}
	cout << "===================" << endl;
	cout << "Tests graded = " << numTests << endl;
	cout << "===================" << endl;
	cout << "Score" << setw(14) <<"Frequency" << endl;
	cout << "===================" << endl;
	for(int i=100;i>0;i--)
		if(frequency[i]!=0)
			cout << setw(3) << i << setw(12)<< frequency[i] << endl;
	cout << "===================" << endl;
	cout << "Class Average = " << average / numTests << endl;
	return 0;
}

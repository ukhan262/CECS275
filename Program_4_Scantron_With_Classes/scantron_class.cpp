/*
Umar khan
CECS 275
014477331
Program 4 revised
*/
#include <iostream>
#include <fstream>
#include <string>
#pragma once

using namespace std;

class Class{
	
	private:
		static const int MAX_STUDENTS = 30;
		static const int POSSIBLE_SCORE = 100;
		//variables to calculate scores and array for holding the frequency of the scores
		int total_questions;
		int average;
		int total_score;
		int score_count[POSSIBLE_SCORE];
		//pointers for the answer key and responses
		int *key;
		int *response;
		
		ifstream infile;
		string file_name;
		
		class Student{
			int student_ID;
			int grade;
			//making this class friend of "Class" in order to access its function in another class
			friend Class;
			
		}

		Student *array[MAX_STUDENTS];

	public:
	//getter and setters for accessing the file
		string get_file(){
			return file_name;
		}
		void set_file(){
			cout << "Enter the File name: " << endl;
			cin << file_name;
		}
		void set_class_size(){
			class_size++;
		}
	//function to set the scores and compare them to the key given in the text file
		int set_score(){
			int correct = 0;
			for(int i = 1, i < total_questions; i++){
				if (key[i] == response[i]){
					correct++;
				}
			}
			int score = 0;
			score = correct * 5;
			return score;	
		}
	//function for counting the scores
		void counter(int score){
			score_count[score]++; //the score from the function set_score	
		}
		
	//getters and setters for getting the ID of the students
		void get_id(int i){
			return array[i].student_ID;
		}
		void set_id(int i){
			array[i].student_ID = response[i];
		}
		
	//getters and setters for total number of questions
		int get_question(){
			return total_questions;
		}
		int set_questions(string file){
			if(!fileIn){
				cout << "Unable to open the file. Try again later!\n\n";
				system("Pause");
				return 0;
				}
				
			// read the number of questions value from the 
			// text file present at the first line
			
			fileIn >> total_questions;
			return total_questions;
		}
		
	//setter and getters for the total scores
		int get_total_scores(){
			return total_score;
		}
		int set_total_scores(int add){
			return total_score += add;
		}
	
	ifstream get_In_File(){
		return fileIn;
	}
	
	//function to get the responses from the text file 
		int get_response(){
			for (int i = 0; i < total_questions; i++)
				if(!get_In_File.eof()){
					get_In_File() >> response[i]
				}
			return 0; 
		}
		int get_class_size(){
			return class_size;
		}
	
	//setters and getters for average
		int get_average(){
			return average;
		}
		int set_average(){
			average = total_score / class_size;
		}
	//function to sort out the scores
	//bubble sort referencing C++ library and AlgoList website
	//same as used in the Program 2 but this time it has been stored with in the function
		void sort(){
			bool swapped = true;
			int j = 0;
			int tmp;
			while (swapped) {
				swapped = false;
				j++;
				for (int i = 0; i < count - j; i++) {
					if (array[i].grade < array[i + 1].grade) {
						//grades assigned in the descending order followed by the Student ID
						tmp = array[i].grade;
						array[i].grade = array[i + 1].grade;
						array[i + 1].grade = tmp;
						tmp = array[i].studentid;
						array[i].studentid = array[i + 1].studentid;
						array[i + 1].studentid = tmp;
						swapped = true;
					}
				}
			}
		}
	//function to print everything that is done in the class
		void print_all(){
			// print the header
			cout << "Student ID" << setw(10) << "Score" << endl;
			cout << "==============================" << endl;
			for (int i = 0; i < total_questions; i++){
				cout <, array[i].student_ID << setw(10) << array[i].grade << endl;
			}
			cout << "=================" << endl;
			cout << "Tests Graded = " << get_class_size << endl;
			cout << "=================" << endl;
			cout << "Score" << setw(3) ,, "Frequency" << endl;
			cout << "=================" << endl;
			
			for (int i = POSSIBLE_SCORE){
				if (score_count[i] > 0){
					cout << setw(4) << i << setw(10 << score_count[i] << endl;
				}
			}
			cout << "=================" << endl;
			cout << " Class Average = " << get_average() << endl;
			
			
		}
		
}
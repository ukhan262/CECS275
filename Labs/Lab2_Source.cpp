/*
Umar Khan
014477331
CECS 275
Lab 2
*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream infile;
	infile.open("Text.txt", ios::in);
	if (infile.fail()) {
		cout << "file not found" << endl;
		return 0;
	}
	
	cout << "ID" << setw(8) << "Rate" << setw(8) << "Hours" << setw(8) << "Wages" << endl;

	int rate, hours, id, overtimeHours;
	double wages = 0, totalWages = 0;

	while (infile >> id >> rate >> hours) {
		
		if (hours <= 40) {
			wages = rate * hours;
			cout << id << setw(8) << rate << setw(8) << hours << " " << fixed << setprecision(2) << wages << endl;
			totalWages += wages;
		}
		else {
			overtimeHours = hours - 40; 
			wages = rate * 40 + (rate * overtimeHours * 1.5);
			cout << id << setw(8) << rate << setw(8) << hours << " " << fixed << setprecision(2) << wages << endl;
			totalWages += wages;
		}	
	

	}
	cout << "Total Wages " << setw(15) << totalWages << endl;
	


	system("pause");
}
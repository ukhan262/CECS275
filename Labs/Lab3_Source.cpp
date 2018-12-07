/*
Umar Khan
014477331
CECS 275
Lab 3
*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void PrintHeader() {
	cout << "ID" << setw(8) << "Rate" << setw(8) << "Hours" << setw(8) << "Wages" << endl;

}

double gross_pay(int id, int rate, int hours) {
	double wage = 0;
	if (hours <= 40) {
		wage = rate * hours;
	}
	else {
		int overtimeHours;
		overtimeHours = hours - 40;
		wage = rate * 40 + (rate * overtimeHours * 1.5);
	}
	return wage;
}
void print_all(int id, int rate, int hours, double wage) {
	cout << id << setw(8) << rate << setw(8) << hours << " " << fixed << setprecision(2) << wage << endl;
}

void totalWage_print(double totalWage) {
	cout << "Total wages : " << totalWage<< endl;
}
int main() {
	int id, rate, hours;
	double totalWage = 0;
	fstream infile;
	infile.open("Text.txt", ios::in);
	if (infile.fail()) {
		cout << "file not found" << endl;
		return 0;
	}
	PrintHeader();
	while (!infile.eof()) {
		infile >> id >> rate >> hours;
		double wage;
		wage = gross_pay(id, rate, hours);
		print_all(id, rate, hours, wage);
		totalWage += wage;
	}

	totalWage_print(totalWage);
	infile.close();
	system("pause");
}
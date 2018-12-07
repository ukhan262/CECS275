/*
Umar Khan
Student ID 014477331
CECS 275
01/31/2017
*/

#include <iostream>
using namespace std;
int main()
{
	double feet;
	double inches;
	double totalCM;
	cout << "This program will convert feet to inches and display the answer in inches.\n";
	cout << "Please enter the feet.";
	cin >> feet;
	cout << "PLease enter the inches.";
	cin >> inches;
	feet = feet * 30.48;
	inches = inches * 2.54;
	totalCM = feet + inches;
	cout << "The total inches are " << totalCM << " centimeters.";

	system("pause");
}

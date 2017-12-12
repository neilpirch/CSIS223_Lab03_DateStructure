// Lab03-DateStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct dateType
{
	int month;
	int day;
	int year;
};

dateType getDate();
int ageInYears(dateType birthdate, dateType today);
bool isEligible(int currAge, char sex);

int main()
{
	dateType currDate;
	dateType dob;
	char gender;
	int age;

	cout << endl << "Enter current date ..." << endl;
	currDate = getDate();

	cout << "__________________________" << endl << endl;
	cout << "Gender M/F - Q Quits:  ";
	cin >> gender;

	while (gender != 'Q' && gender != 'q')
	{
		gender = toupper(gender);

		cout << endl << "Enter date of birth ..." << endl;
		dob = getDate();

		age = ageInYears(dob, currDate);

		cout << endl << "  Gender:  " << gender << "     Age:  " << age << "         ";

		if (isEligible(age, gender))
			cout << "Eligible";
		else
			cout << "Not Eligible";

		cout << endl << endl;

		cout << "________________________" << endl << endl;
		cout << "Gender M/F - Q Quits:  ";
		cin >> gender;
	}
	
	
	cout << endl;
	system("pause");
	return 0;
}

dateType getDate()
{
	dateType inputDate;

	cout << endl << "  Enter month [1-12]:  ";
	cin >> inputDate.month;

	cout << endl << "  Enter day of month:  ";
	cin >> inputDate.day;

	cout << endl << "  Enter year as YYYY:  ";
	cin >> inputDate.year;

	return inputDate;
}

int ageInYears(dateType birthDate, dateType today)	// calculate age
{
	int calcAge;
	
	calcAge = today.year - birthDate.year;

	if (today.month < birthDate.month)
		calcAge--;

	else if (today.month = birthDate.month)
		if (today.day < birthDate.day)
			calcAge--;

	return calcAge;
}

bool isEligible(int currAge, char sex)				// determine eligibility
{
	bool elig = false;

	if (sex == 'F' && currAge >=62)
	{
		elig = true;
	}

	if (sex == 'M' && currAge >= 65)
	{
		elig = true;
	}

	return elig;
}









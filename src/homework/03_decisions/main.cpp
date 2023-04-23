//write include statements
#include "decisions.h"

int main() 
{
	int option = 0;
	cout << "MAIN MENU\n";
	cout << "1-Letter grade using if\n";
	cout << "2-Letter grade using switch\n";
	cout << "3-Exit\n";

	cin >> option;

	if(option == 1)
	{
		auto grade = 0;
		cout << "Enter grade number between 0 and 100: ";
		cin >> grade;

		auto result = get_letter_grade_using_if(grade);
		cout << result << endl;
	}

	else if(option == 2)
	{
		auto grade = 0;
		cout << "Enter grade number between 0 and 100: ";
		cin >> grade;

		auto result = get_letter_grade_using_switch(grade);
		cout << result << endl;
	}

	else if(option == 3)
		return 0;
}
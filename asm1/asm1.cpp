#include <iostream>
using namespace std;


struct student
{
	int id; //ID of students
	float grade; //Grade of students
} s[100];

void displayOption() {
	cout << "=============MENU============ \n";
	cout << "1. Input the information of students \n";
	cout << "2. Display information \n";
	cout << "3. Find highest grade \n";
	cout << "4. Find lowest grade \n";
	cout << "0. Exit !!! \n";
}

void enterStudent(int& n) {
	do {
		cout << "Enter the number of students :";
		cin >> n;
		if (n < 0 || n > 50) {
			cout << "Enter wrong!! Please try again: \n";
		}
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". \n";
			cout << "Student's ID: ";
			cin >> s[i].id;

			cout << "Student's Grade: ";
			cin >> s[i].grade;
			if (s[i].grade < 0 || s[i].grade > 10)
			{
				cout << "Enter wrong!";
				cout << "Student's Grade: ";
				cin >> s[i].grade;
			}
		}
	} while (n <= 0 || n >= 50);
}

void printInfoStudent(int& n) {

	for (int i = 0; i < n; i++)
	{
		cout << "Student " << i + 1 << ".\n";
		cout << "ID :" << s[i].id << endl;
		cout << "Grade :" << s[i].grade << endl;
	}
}

void findMax(float max, int& n) {
	int maxID = s[0].id;
	max = s[0].grade;
	for (int i = 0; i < n; i++)
	{

		if (max < s[i].grade)
		{
			max = s[i].grade;
			maxID = s[i].id;
		}
	}
	cout << "Highest score :\n";
	cout << "ID : " << maxID << endl;
	cout << "Grade : " << max << endl;
}

void findMin(float min, int& n) {
	int minID = s[0].id;
	min = s[0].grade;
	for (int i = 0; i < n; i++)
	{

		if (min > s[i].grade)
		{
			min = s[i].grade;
			minID = s[i].id;
		}
	}
	cout << "Lowest score :\n";
	cout << "ID : " << minID << endl;
	cout << "Grade : " << min << endl;
}

void clearScreen() {
	system("cls");
}

void main() {

	int choice; //variables use to input data in to the menu option
	int n{}; //variables use to input the number of students
	float max{}, min{}; //variables use in function find highest and lowest grade of student

	do
	{
		displayOption();
		cin >> choice;
		clearScreen();
		switch (choice)
		{
		case 0:
			cout << "========Exit the program========";
			cout << endl;
			break;
		case 1:
			enterStudent(n);
			break;
		case 2:
			printInfoStudent(n);
			break;
		case 3:
			findMax(max, n);
			break;
		case 4:
			findMin(min, n);
			break;
		default:
			if (choice < 0 || choice > 4)
			{
				cout << "Try again !! \n\n";
			}
			break;
		}
	} while (choice != 0);

}
#include <iostream>
#include <string>

using namespace std;

// Global Variable
bool running;

void mainMenu(short& currentChoice);
void estimateHeight();
bool inputGender();
short inputHeight(string parent);

int main()
{
	running = true;
	short currentChoice;

	while(running) mainMenu(currentChoice);

	return 0;
}

void mainMenu(short& currentChoice)
{
	cout << "Main Menu\n"<< endl;
	cout << "1:\tEstimate Height of a Child"<< endl;
	cout << "0:\tExit"<< endl;
	cout << "Enter choose:\t";
	cin >> currentChoice;

	if(currentChoice == 1) estimateHeight();
	else if(currentChoice == 0) running = false;
}

void estimateHeight()
{
	enum Gender
	{
		FEMALE = false,
		MALE = true
	};
	bool gender = inputGender();

	short father = inputHeight("father");
	short mother = inputHeight("mother");

	float height = 0.0;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	switch (gender)
	{
		case MALE:
			height = ((mother * (13.0 / 12.0)) + father) / 2.0;
			cout << "\nThe height of this male child is " << height << " inches." << endl;
			break;
		case FEMALE:
			height = ((father * (12.0 / 13.0)) + mother) / 2.0;
			cout << "\nThe height of this female child is " << height << " inches." << endl;
			break;
	}
}

bool inputGender()
{
	bool error = false;
	bool choose;
	string gender;
	do
	{
		cout << "\nSelect Gender(M of Male, F for Female):\t";
		cin >> gender;
		if(gender == "M")
		{
			error = false;
			choose = true;
		}
		else if(gender == "F")
		{
			error = false;
			choose = false;
		}
		else {error = true;}
	}
	while(error);
	return choose;
}

short inputHeight(string parent)
{
	short height;

	cout << "\nWhat is the height of the biological " << parent << " in inches?:\t";
	cin >> height;

	return height;
}

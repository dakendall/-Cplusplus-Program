#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int hours = 0;				//24-hour clock hours
int minutes = 0;			//24-hour clock minutes
int seconds = 0;			//24-hour clock seconds
int twelveHours = 0;		//12-hour clock hour



//displays AM or PM for the twelve hour clock
string timeOfDay() {					
	string timeOfDay;

	if (hours < 13) {
		timeOfDay = "A M";
	}
	else {
		timeOfDay = "P M";
	}

	return timeOfDay;
}

//keeps track of time
void workingClock() {
	seconds++;
	if (seconds == 60) {
		minutes++;
		seconds = 0;

		if (minutes == 60) {
			hours++;
			minutes = 0;

			if (hours == 24) {
				
				hours = 0;
				minutes = 0;
				seconds = 0;	
			}
		}
	}
}

//adds an hour to clocks
void addOneHour() {
	if (hours == 23) {
		hours = 0;
	}
	else {
		hours++;
	}
}

//adds a minute to clocks
void addOneMinute() {
	if (minutes == 59) {
		minutes = 0;
		addOneHour();
	}
	else {
		minutes++;
	}
}

//adds a second to clocks
void addOneSecond() {
	if (seconds == 59) {
		seconds = 0;
		addOneMinute();
	}
	else {
		seconds++;
	}
}

//Displays the menu
void displayMenu() {
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour\t *" << endl;
	cout << endl;
	cout << "* 2 - Add One Minute\t *" << endl;
	cout << endl;
	cout << "* 3 - Add One Second\t *" << endl;
	cout << endl;
	cout << "* 4 - Exit Program\t *" << endl;
	cout << "**************************" << endl;
}

//Shows the clock
void displayClock() {
	boolean isValid = false;

	while (!isValid) {
		system("cls");										//clears screen

		workingClock();

		//12 hour clock
		if (hours <= 12) {
			twelveHours = hours;
		}
		else {
			twelveHours = hours - 12;
		}

		cout << "**************************";
		cout << "\t**************************" << endl;
		cout << "*\t12-Hour Clock\t * ";
		cout << "\t*\t24-Hour Clock\t *" << endl;
		cout << "*\t" << setw(2) << setfill('0') << twelveHours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << timeOfDay() << "\t *";
		cout << "\t*\t  " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " \t *" << endl;
		cout << "**************************";
		cout << "\t**************************" << endl;
		
		Sleep(1000);										//delays a second

		isValid = true;										//breaks loop
	}
}

int main() {
	char menuOption = '0';									//user input
	displayClock();											//shows clock

	while (menuOption != '4') {

		displayMenu();										//shows menu
		cin >> menuOption;									//reads user input

		switch (menuOption) {
		case '1':											//adds a hour to clock
			addOneHour();
			displayClock();
			break;

		case'2':											//adds a minute to clock
			addOneMinute();		
			displayClock();
			break;

		case'3':											//adds a second to clock
			addOneSecond();		
			displayClock();
			break;

		case'4':											//quits
			break;

		default:											//default if one of the options isn't chosen
			displayClock();
			cout << "That is not an option" << endl;
		}
	}
	return 0;
}
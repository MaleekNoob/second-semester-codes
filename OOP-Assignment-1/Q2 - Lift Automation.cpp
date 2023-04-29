/*
Name: Maleek Hussain Ali
Roll Number: 22i-1526
Section: B
*/

#include<iostream>
using namespace std;

int liftup(int, int);

int liftdown(int, int);

void optionValidation(int& n) {   //Validates user's option input
	while ((n < 1) || (n > 4)) {
		cout << endl << "\nInvalid Input\nPlease enter valid input: ";
		cin >> n;
	}
}

void floorValidation(int& n) {  //Validates user's floor number input
	while ((n < -1) || (n > 4)) {
		cout << endl << "\nInvalid floor\nPlease select valid floor number: ";
		cin >> n;
	}
}

int lift_operating_system(int requested_floor, int current_floor, char lift_status)
{
	//all lift related logic will be written in this bloack along with validation. In this funcation, decide
	//if the lift goes up or down
	if (lift_status == 'W') {
		if (requested_floor > current_floor) {
			current_floor = liftup(current_floor, requested_floor);
		}
		else {
			current_floor = liftdown(current_floor, requested_floor);
		}
	}
	else {
		cout << "\nLift is not working at the moment due to some technical issues\nIf you want you can turn lift status to \'Working\' ";
	}
	return current_floor;
}
int liftup(int current_floor, int requested_floor)
{
	//recurrsive funcation to take lift up
	if (current_floor == requested_floor) {
		return requested_floor;
	}
	else {
		return liftup(current_floor + 1, requested_floor);
	}
}
int liftdown(int current_floor, int requested_floor)
{
	//recurrsive funcation to bring the lift down
	if (current_floor == requested_floor) {
		return requested_floor;
	}
	else {
		return liftup(current_floor - 1, requested_floor);
	}
}
char halt_lift(char status)
{
	//halts the lift, no up and down operation can be performed. Stored H for halting
	status = 'H';
	cout << "\nLift has stopped working";
	return status;
}
char un_halt_lift(char status)
{
	//Unhatls the lift. Store W which represents that the lift is working
	status = 'W';
	cout << "\nLift has started working";
	return status;

}
int main()
{
	int total_floors = 6; // total number of floors
	int current_floor = -1; // starts with basement
	int requested_service; //choice of user
	int requested_floor; //floor the lift goes on
	char status = 'W'; //W for working , H for halted
	while (1)
	{
		cout << endl << "--------------------------------------------------FAST NUCES ISLAMABAD LIFT----------------------------------------------------" << endl;
		cout << "Please select a funcation of your choice";
		cout << endl << "1. Go to a specific floor";
		cout << endl << "2. Halt Lift";
		cout << endl << "3. Unhalt Lift";
		cout << endl << "4. Exit";
		cout << endl;
		cout << "\nEnter option: ";
		cin >> requested_service;
		optionValidation(requested_service);
		switch (requested_service)
		{
		case 1:
			cout << endl << "Enter Floor of choice ";
			cin >> requested_floor;
			floorValidation(requested_floor);
			cout << "\nYour current floor is " << lift_operating_system(requested_floor, current_floor, status);//arguments 
			//your code here
			break;
		case 2:
			status = halt_lift(status);
			break;
		case 3:
			status = un_halt_lift(status);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "\nWrong input\nPlease try again: ";
			break;
			//
		}
	}

	return 0;
}

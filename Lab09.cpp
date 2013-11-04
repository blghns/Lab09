//Bilgehan Saglik Comp128
//Wentworth Institute of Technology
//Lab09 Student Billing System
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	//Variable Declerations
	ifstream inputFileStream;
	ofstream outputFileStream;
	char lastName[200], firstName[200];
	double hours;

	inputFileStream.open("StudentsInfo.txt");
	outputFileStream.open("OutputFile.txt");
	
	outputFileStream.setf(ios::fixed);
	outputFileStream.setf(ios::showpoint);
	outputFileStream.setf(ios::right);

	while(inputFileStream >> lastName >> firstName >> hours)
		{
			outputFileStream << lastName << ", " << firstName << endl;
			outputFileStream.precision(1);
			outputFileStream << "hours" << setfill('.') << setw(29) << hours << endl;
			
			double bill, regularHours, regularBill, overloadHours, overloadBill, underloadHours, underloadBill;

			if(hours >= 12 && hours <= 18){
				regularHours = hours;
				regularBill = 7000;
				overloadHours = 0;
				overloadBill = 0;
				underloadHours = 0;
				underloadBill = 0;
			}
			else if(hours < 12){
				regularHours = 0;
				regularBill = 0;
				overloadHours = 0;
				overloadBill = 0;
				underloadHours = hours;
				underloadBill = hours * 450;
			}
			else if(hours > 18){
				regularHours = 18;
				regularBill = 7000;
				overloadHours = hours - 18;
				overloadBill = overloadHours * 400;
				underloadHours = 0;
				underloadBill = 0;
			}
			
			bill = regularBill + overloadBill + underloadBill;
			
			outputFileStream.precision(1);
			outputFileStream << "regular hours" << setfill('.') << setw(21) << regularHours << endl;

			outputFileStream.precision(2);
			outputFileStream << "regular bill" << setw(23) << regularBill << endl;

			outputFileStream.precision(1);
			outputFileStream << "overload hours" << setw(20) << overloadHours << endl;

			outputFileStream.precision(2);
			outputFileStream << "overload bill" << setw(22) << overloadBill << endl;

			outputFileStream.precision(1);
			outputFileStream << "underload hours" << setw(19) << underloadHours << endl;

			outputFileStream.precision(2);
			outputFileStream << "underload bill" << setw(21) << underloadBill << endl;

			outputFileStream << "total bill" << setw(25) << bill << endl;

			outputFileStream << "----------------------------------" << endl;
		}

	inputFileStream.close();
	outputFileStream.close();
	return 0;
}
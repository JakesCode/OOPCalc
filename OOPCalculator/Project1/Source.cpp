/* multiply two numbers (using only the '+' operator) */
#include <iostream>		//for I/O routines
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

const int maxNumOfCalculations = 6;

int main() 			// multiply two numbers
{
	void doACalculation(int calculationArray[][maxNumOfCalculations], int);
	bool wantToContinue();
	int calculations = 0;

	int calculationArray[3][maxNumOfCalculations];

	do
	{
		doACalculation(calculationArray, calculations);
		calculations++;
	} while (wantToContinue() && calculations != maxNumOfCalculations);
	
	cout << "What filename should the calculations be written to? (i.e. 'calculations'): ";
	string filename;
	cin >> filename;

	ofstream calculationsFile;
	calculationsFile.open(filename + ".txt");

	cout << "Calculations:" << endl;
	calculationsFile << "Calculations:\n";
	for (int x = 0; x < calculations; x++)
	{
		cout << calculationArray[x][0] << " * " << calculationArray[x][1] << " = " << calculationArray[x][2] << endl;
		calculationsFile << calculationArray[x][0] << " * " << calculationArray[x][1] << " = " << calculationArray[x][2] << endl;
	}

	calculationsFile.close();

	cout << "Program ended. Press any key to exit!" << endl;
	system("pause");	//to hold the output screen
	return 0;
}

void doACalculation(int calculationArray[][maxNumOfCalculations], int calculations)
{
	void multiply(int, int, int*);
	int number1, number2, product;
	cout << "\nPlease enter number 1: ";
	cin >> number1;
	cout << "Please enter number 2: ";
	cin >> number2;
	multiply(number1, number2, &product);
	calculationArray[calculations][0] = number1;
	calculationArray[calculations][1] = number2;
	calculationArray[calculations][2] = product;
	cout << "The product is: " << product << "\n\n";
}

bool wantToContinue()
{
	cout << "Would you like to continue (Y/N)? ";
	char option;
	cin >> option;
	return (toupper(option) == 'Y');
}

void multiply(int num1, int num2, int* prod)
{
	assert(num1 >= 0 && num2 >= 0);
	*prod = 0;
	for (int time(0); time < num1; ++time)
		*prod = *prod + num2;
}
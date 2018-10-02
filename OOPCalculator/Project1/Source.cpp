/* multiply two numbers (using only the '+' operator) */
#include <iostream>		//for I/O routines
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

const int maxNumOfCalculations = 6;

int main() 			// multiply two numbers
{
	void doACalculation(int calculationArray[][maxNumOfCalculations], int); // Forward declaration //
	bool wantToContinue();

	int calculations = 0;
	int calculationArray[3][maxNumOfCalculations]; // This will hold a maximum of three calculations //
	// It is a 2D array, so for each array entry there is a corresponding array (of size maxNumOfCalculations) //
	// This array will hold data in the order number1, number2, and then product //

	do
	{
		doACalculation(calculationArray, calculations);
		calculations++;
	} while (wantToContinue() && calculations != maxNumOfCalculations);
	
	cout << "What filename should the calculations be written to? (i.e. 'calculations'): ";
	string filename;
	cin >> filename; // Allow the user to input a chosen filename //
	ofstream calculationsFile;
	calculationsFile.open(filename + ".txt"); // Open a new file for writing //

	cout << "Calculations:" << endl;
	calculationsFile << "Calculations:\n"; // Write the string to the file //
	for (int x = 0; x < calculations; x++)
	{
		cout << calculationArray[x][0] << " * " << calculationArray[x][1] << " = " << calculationArray[x][2] << endl;
		calculationsFile << calculationArray[x][0] << " * " << calculationArray[x][1] << " = " << calculationArray[x][2] << endl; // Write score string to file //
	}

	calculationsFile.close(); // Close the file //

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
	calculationArray[calculations][0] = number1; // Insert the data into the nested array at the predetermined positions (see declaration above for more information) //
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
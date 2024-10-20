/*
 * Calculator.cpp
 *
 *  Date: 9/10/2023
 *  Author: Armon Wilson
 */

#include <iostream>

using namespace std;

/*  General fixes in main():
*   Added missing ";" where needed.
*	End brackets were placed where beginning brackets should be, correct brackets placed "{".
*   Added end brackets "}" to "if" statements where needed.
*/

void main()
{
	//char statement[100];              // Don't know what this is supposed to do and don't think it belongs. Commented out with no new bugs . 
	int op1;
	int op2;							// Placed variable initialization on two lines and corrected syntax. 
	char operation;
	char answer = 'Y';					// Changed "" to '' for "char" instead of string.
	
	
	
	/* Added a boolean for loop and locking answer to just y or n.
	*  Otherwise, any input other than y would have terminated the loop.   
	*/
	bool keepGoing = true;				


	while (keepGoing == true) {		// added an "or" operand for char case.

		cout << "Enter expression" << endl;
		cin >> op1;
		cin >> operation;
		cin >> op2;														//Changed to proper variable input. 

		if (operation == '+') {											// Changed "" to '' for "char". Removed spaces
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;	// Corrected >> to <<.
		}
		if (operation == '-') {
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;	// Corrected >> to <<.
		}
		if (operation == '*') {
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;	// Corrected "/" to "*".
		}
		if (operation == '/') {
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;	// Corrected "*" to "/". 
		}
		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;

		// Added a while loop for variable "Answer" verification. User's input has to be a "y" or a "n". 

		while (!(((answer == 'Y') || (answer == 'y')) || ((answer == 'n') || (answer == 'N')))) {
			cout << "Try again!" << endl << "Enter Y or N." << endl;
			cin >> answer;
		}
		if ((answer == 'Y') || (answer == 'y'))  {						
		continue;
		}
		else if ((answer == 'n') || (answer == 'N')) {		
			// End statement is here.
			cout << "Program Finished." << endl;						
			keepGoing = false;
		}
	}
}






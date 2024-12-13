#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#include "misc.h"
#include "basic_opps.h"
//#include "complex_opps.h"
using namespace std;

int main()
{
    long double operation;
    cout << "Enter an operation\n[1]-Add\n[2]-Subtract\n[3]-Division\n[4]-Multiplication\n[5]Exponentiation\n[6]Rooting\n";
    cin >> operation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int range[] = {1, 6};
    
    while (operation < range[0] || operation > range[1]) {
        cout << "Please enter a valid input: "; 
        cin >> operation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    enum Operations op = static_cast<Operations>(static_cast<int>(operation));
    long double result;

    if (op < 5)
    {
        vector<long double> nums;
        string input = "";
        cout << "Input all the numbers you would like to " << operation_to_string(op) <<": ";
        bool minNumbersEntered = false;
        bool emptyInput = false;

        while (true)  
        {
            getline(cin, input);

            minNumbersEntered = (nums.size() >= 2) ? true : false;

            if (input.empty()) 
            {
                emptyInput = true;
                if (!minNumbersEntered) cout << "\nYou need to input at least 2 numbers to run this calculator in this mode." << endl;
            }
            else{
                emptyInput = false;
            }

            if (!emptyInput)
            {
                try {
                    nums.push_back(stold(input));
                }
                catch (const invalid_argument& e) {
                    cout << "Invalid input. Please enter a valid number.\n";
                }                
            }

            if (minNumbersEntered && emptyInput) break;
        }

        switch (op)
        {
            case ADD:
                result = add(nums);
                break;
            case SUB:
                result = subtract(nums);
                break;
            case MUL:
                result = multiply(nums);
                break;
            case DIV:
                result = divide(nums);
                break;
        }
    }
    else{
        long double first;
        long double second;
        cout << "Input the number to be modified: ";
        cin >> first;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input the power/n-root power: ";
        cin >> second;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(op)
        {
            case EXP:
                result = exponentiation(first, second);
                break;
            case ROT:
                result = root(first, second, 1e-20);
                break;
        }
    }


    cout << "Result of the operation is: " << result << endl;

    return 0;
}
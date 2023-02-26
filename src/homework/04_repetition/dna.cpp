//add include statements
#include "dna.h"
//add function(s) code here
int factorial(int num)
{
    auto sum = 1;
    while (num > 0)
    {
        sum *= num;
        num--;
    }

    return sum;
}

int gcd(int num1, int num2)
{
    while (num1 != num2)
    {
        auto temp = num1;
        if (num1 < num2)
        {
            num1 = num2;
            num2 = temp;
        }
        else if (num1 > num2)
            num1 -= num2;
    }

    return num1;
}

void run_menu()
{
    char choice;
    bool exitMenu = false;
    auto option1 = 0, option2 = 0;

    do {
        cout << "MENU" << endl;
        cout << "1-Factorial" << endl;
        cout << "2-Greatest Common Divisor" << endl;
        cout << "3-Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter a number: ";
            cin >> option1;
            cout << factorial(option1) << endl;
            break;
        case '2':
            cout << "Enter two numbers: ";
            cin >> option1 >> option2;
            cout << gcd(option1, option2) << endl;
            break;
        case '3':
            cout << "Are you sure you want to exit? (y/n): ";
            char confirmExit;
            cin >> confirmExit;
            if (confirmExit == 'y' || confirmExit == 'Y') {
                exitMenu = true;
            }
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (!exitMenu);

    cout << "Exiting program..." << endl;
}
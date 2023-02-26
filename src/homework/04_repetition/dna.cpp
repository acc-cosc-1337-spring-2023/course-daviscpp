//add include statements
#include "dna.h"

//add function(s) code here
int factorial(int num)
{
    auto sum = 1;
    while(num > 0)
    {
        sum *= num;
        num--;
    }

    return sum;
}

int gcd(int num1, int num2)
{
    while(num1 != num2)
    {
        auto temp = num1;
        if (num1 < num2)
        {
            num1 = num2;
            num2 = temp;
        }
        else if(num1 > num2)
            num1 -= num2;
    }

    return num1;
}

void display_menu()
{  
    cout << "1-Factorial\n";
    cout << "2-Greatest Common Divisor\n";
    cout << "3-Exit\n";
}

void run_menu()
{
    auto option = 0;

    do
    {
        display_menu();
        cout << "Enter menu option: ";
        cin >> option;

        handle_menu_option(option);
    }
    while(option != 3);
}

void handle_menu_option(int num)
{
    auto option1 = 0, option2 = 0;
    auto choice = 'c';

    switch(num)
    {
        case 1:
            cout << "Enter a number: ";
            cin >> option1;
            cout <<  "Factorial of " << option1 << " is: " << factorial(option1) << endl;
        case 2:
            cout << "Enter two numbers: ";
            cin >> option1 >> option2;
            cout << "GCD is: " << gcd(option1, option2) << endl;
        case 3:
            cout << "Are you sure you want to exit?\n";
            cout << "Y / N: ";
            cin >> choice;

            if(choice == 'Y' || 'y')
                return;

            else if(choice == 'N' || 'n')
                run_menu();
        default:
            cout << "Not a valid option";
    }
}
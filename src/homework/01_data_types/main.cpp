//write include statements
#include "data_types.h"

//write namespace using statement for cout
#include <iostream>

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/

int main()
{
	int num = 0;
	std::cin >> num;

	int result = multiply_numbers(num);
	std::cout << result << std::endl;

	int num1 = 4;
	result = multiply_numbers(num1);
	std::cout << result;
	
	return 0;
}
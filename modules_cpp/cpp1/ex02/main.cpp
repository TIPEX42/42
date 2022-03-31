#include <string>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";

	const char *stringPTR = string.c_str();
	std::string &stringREF = string;

	std::cout << "Adress of string :" << &string << std::endl;
	std::cout << "Adress pointed by stringPTR :" << (void *)stringPTR << std::endl;
	std::cout << "Adress of stringREF :" << &stringREF << std::endl;

	std::cout << "Value of string :" << string << std::endl;
	std::cout << "Value pointed by stringPTR :" << stringPTR << std::endl;
	std::cout << "Value of stringREF :" << stringREF << std::endl;
}
#include "D.hpp"
#include <iostream>

D1::D1() : Base()
{
	std::cout << "D1 Default Constructor\n";
}

D1::D1( std::string name, int num = 0) : Base(name, num)
{
	std::cout << "D1 Param Constructor\n";
}
D1::~D1()
{
	std::cout << "D1 Default Destructor\n";
}
void D1::action( std::string str)
{
	std::cout << "D1 Action " << str << std::endl;
}

D2::D2() : Base()
{
	std::cout << "D2 Default Constructor\n";
}
D2::D2( std::string name, int num = 0) : Base(name, num)
{
	std::cout << "D2 Param Constructor\n";
}
D2::~D2()
{
	std::cout << "D2 Default Destructor\n";
}
void D2::action( std::string str)
{
	std::cout << "D2 Action " << str << std::endl;
}
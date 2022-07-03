#include "F.hpp"
#include <iostream>

F::F() : Base(), D1(), D2()
{
	this->_name = "final_null";
	std::cout << "F Default Constructor\n";
}
F::F( std::string name, int num = 0) : Base(name + "_base", num), D1(), D2()
{
	this->_name = name;
	std::cout << "F Param Constructor\n";
}
F::~F()
{
	std::cout << "F Default Destructor\n";
}

void F::action( std::string str )
{
	std::cout << "F Action : " << _name << std::endl;
	Base::action(str);
	D1::action(str);
	D2::action(str);
}
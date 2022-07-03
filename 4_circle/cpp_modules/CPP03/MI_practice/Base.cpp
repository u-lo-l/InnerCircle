#include "Base.hpp"
#include <iostream>

Base::Base() : _name("NULL")
{
	std::cout << "Base Default Constructor\n";
	_num = -1;
}
Base::Base( std::string name, int num = 0) : _name(name), _num(num)
{
	std::cout << "Base Param Constructor\n";
}
Base::~Base()
{
	std::cout << "Base Default Destructor\n";
}
void Base::action( std::string str )
{
	std::cout << "Base Action " << _name << " | "<< str << std::endl;
}

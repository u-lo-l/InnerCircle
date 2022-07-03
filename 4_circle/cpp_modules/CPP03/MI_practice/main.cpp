#include "F.hpp"
#include <iostream>
int main()
{
	Base b1;
	b1.action("b1b1");
	std::cout << std::endl;
	Base b2("base", 10);
	b2.action("b2b2");
	std::cout << std::endl;
	std::cout << std::endl;

	D1	d1_1;
	d1_1.action("d11d11");
	std::cout << std::endl;
	D1	d1_2("d1", 20);
	d1_2.action("d12d12");
	std::cout << std::endl;
	std::cout << std::endl;

	D2	d2_1;
	d2_1.action("d21d21");
	std::cout << std::endl;
	D2	d2_2("d2", 30);
	d2_2.action("d22d22");
	std::cout << std::endl;
	std::cout << std::endl;

	F	f_1;
	f_1.action("f1f1");
	std::cout << std::endl;
	F	f_2("f", 30);
	f_2.action("f2f2");
	std::cout << std::endl;
	std::cout << std::endl;

}
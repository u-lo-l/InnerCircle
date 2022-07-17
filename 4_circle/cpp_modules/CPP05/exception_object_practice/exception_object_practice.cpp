#include <iostream>
#include <cmath>
#include "exception_object_practice.hpp"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;

	while (std::cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			std::cout << "H : " << z << std::endl;
			std::cout << "G : " << gmean(x, y) << std::endl;
		}
		catch (Hmean & hm)
		{
			hm.msg();
			continue ;
		}
		catch (Gmean & gm)
		{
			gm.msg();
			break ;
		}
	}
}

double hmean(double a, double b)
{
	if (a == -b)
		throw Hmean(a, b);
	return 2 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw Gmean(a, b);
	return std::sqrt(a * b);
}

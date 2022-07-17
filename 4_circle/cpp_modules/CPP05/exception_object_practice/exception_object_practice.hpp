#ifndef EXCEPT_HPP
# define EXCEPT_HPP

#include <iostream>

class Hmean
{
	private :
		double v1;
		double v2;
	public :
		Hmean( double a = 0, double b = 0 ) : v1(a), v2(b) { }
		void msg( void );
};

inline void Hmean::msg()
{
	std::cout << "Hmean : Wrong params" << std::endl;
}

class Gmean
{
	private :
		double v1;
		double v2;
	public :
		Gmean( double a = 0, double b = 0 ) : v1(a), v2(b) { }
		void msg( void );
};

inline void Gmean::msg()
{
	std::cout << "Gmean : Wrong params" << std::endl;
}

#endif

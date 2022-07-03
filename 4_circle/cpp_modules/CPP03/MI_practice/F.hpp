#ifndef F_HPP
# define F_HPP

#include "D.hpp"

class F : public D1, public D2
{
private :
	std::string _name;
public :
	F();
	F( std::string name , int num);
	virtual ~F();

	virtual void action( std::string str );
};

#endif
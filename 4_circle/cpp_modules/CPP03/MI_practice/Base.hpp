#ifndef BASE_HPP
# define BASE_HPP

#include <string>

class Base
{
private :
	std::string _name;
	int _num;
public :
	Base();
	Base( std::string name , int num);
	virtual ~Base();

	virtual void action( std::string str);
};

#endif
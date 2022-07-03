#ifndef D_HPP
# define D_HPP

#include "Base.hpp"

class D1 : virtual public Base
{
public:
	D1();
	D1( std::string name , int num );
	virtual ~D1();

	virtual void action( std::string str);

};

class D2 : virtual public Base
{
public :
	D2();
	D2( std::string name , int num);
	virtual ~D2();

	virtual void action( std::string str);
};
#endif
#ifndef ACLASS_HPP
# define ACLASS_HPP

#include <...>

class AClass
{
public:
	AClass( void );
	AClass( AClass& c );
	AClass& operator=( AClass& c);
	~AClass( void );

private:

};

#endif
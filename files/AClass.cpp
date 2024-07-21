#include "include/AClass.hpp"
#include <iostream>

AClass::AClass( void ) : ... {
	std::cout << "\x1B[2m[AClass Default constructor called]\x1B[22m\n";
}

AClass::AClass( AClass& c ) {
	std::cout << "\x1B[2m[AClass Copy constructor called]\x1B[22m\n";
	*this = c;
}

AClass& AClass::operator=( AClass& c ) {
	std::cout << "\x1B[2m[AClass Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		//...
	}
	return (*this);
}

AClass::~AClass( void ) {
	std::cout << "\x1B[2m[AClass Destructor called]\x1B[22m\n";
}

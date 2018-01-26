
#include "abstractvm.hpp"

const char	*CommandException::SyntaxError::what(void) const throw()
{
	return ("Syntax Error\n");
}

const char	*CommandException::RangeError::what(void) const throw()
{
	return ("Range Error\n");
}

const char	*CommandException::FalseAssert::what(void) const throw()
{
	return ("False Assert\n");
}

const char	*CommandException::LackOfValues::what(void) const throw()
{
	return ("Lack of values to perform operation\n");
}

const char	*CommandException::ZeroDivision::what(void) const throw()
{
	return ("Division by zero encountered\n");
}

const char	*CommandException::EmptyStack::what(void) const throw()
{
        return ("Stack is empty\n");
}

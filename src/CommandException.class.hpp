#ifndef COMMANDEXCEPTION_CLASS_HPP
#define COMMANDEXCEPTION_CLASS_HPP

#include "abstractvm.hpp"

class	CommandException
{
public:
	class	SyntaxError : public std::exception
	{
		const char	*what(void) const throw();
	};
	class	RangeError : public std::exception
	{
		const char	*what(void) const throw();
	};
	class	FalseAssert : public std::exception
	{
		const char	*what(void) const throw();
	};
	class	LackOfValues : public std::exception
	{
		const char	*what(void) const throw();
	};
	class	ZeroDivision : public std::exception
	{
		const char	*what(void) const throw();
	};
	class	EmptyStack : public std::exception
	{
		const char	*what(void) const throw();
	};
};

#endif


#include "abstractvm.hpp"

std::string	StrMath::Add(std::string s1, std::string s2)
{
	double a = strtod(s1.c_str(), nullptr);
	double b = strtod(s2.c_str(), nullptr);
	std::stringstream c;

	c << a + b;
	return (c.str());
}

std::string	StrMath::Sub(std::string s1, std::string s2)
{
	double a = strtod(s1.c_str(), nullptr);
	double b = strtod(s2.c_str(), nullptr);
	std::stringstream c;

	c << a - b;
	return (c.str());
}

std::string	StrMath::Mul(std::string s1, std::string s2)	
{
	double a = strtod(s1.c_str(), nullptr);
	double b = strtod(s2.c_str(), nullptr);
	std::stringstream c;

	c << a * b;
	return (c.str());
}

std::string	StrMath::Div(std::string s1, std::string s2)
{
	double a = strtod(s1.c_str(), nullptr);
	double b = strtod(s2.c_str(), nullptr);
	std::stringstream c;

	c << a / b;
	return (c.str());
}

std::string	StrMath::Mod(std::string s1, std::string s2)
{
	double a = strtod(s1.c_str(), nullptr);
	double b = strtod(s2.c_str(), nullptr);
	std::stringstream c;

	c << fmod(a, b);
	return (c.str());
}

void	StrMath::checkRange(std::string s, eOperandType t)
{
	long int n = strtol(s.c_str(), nullptr, 10);
	
	if ((t == Int8 && (n > CHAR_MAX || n < CHAR_MIN)) ||
	    (t == Int16 && (n > SHRT_MAX || n < SHRT_MIN)) ||
	    (t == Int32 && (n > INT_MAX || n < INT_MIN)))
	{
		throw CommandException::RangeError();
	}
}

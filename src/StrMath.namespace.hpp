#ifndef STRMATH_NAMESPACE_HPP
#define STRMATH_NAMESPACE_HPP

#include "abstractvm.hpp"

namespace	StrMath
{
	std::string	Add(std::string s1, std::string s2);
	std::string	Sub(std::string s1, std::string s2);
	std::string	Mul(std::string s1, std::string s2);
	std::string	Div(std::string s1, std::string s2);
	std::string	Mod(std::string s1, std::string s2);

	void	checkRange(std::string s, eOperandType t);
}

#endif

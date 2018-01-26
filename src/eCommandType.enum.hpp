#ifndef ECOMMANDTYPE_ENUM_HPP
#define ECOMMANDTYPE_ENUM_HPP

#include "abstractvm.hpp"

enum	eCommandType
{
	Push,
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Print,
	Exit
};

#endif

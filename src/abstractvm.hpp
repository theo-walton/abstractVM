#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include <regex>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <fstream>

#include "CommandException.class.hpp"

#include "eCommandType.enum.hpp"
#include "eOperandType.enum.hpp"

#include "StrMath.namespace.hpp"

#include "IOperand.class.hpp"
#include "Int8.class.hpp"
#include "Int16.class.hpp"
#include "Int32.class.hpp"
#include "Float.class.hpp"
#include "Double.class.hpp"
#include "OperandCreate.class.hpp"

#include "Global.struct.hpp"

#include "OperandStack.class.hpp"
#include "CommandStack.class.hpp"

enum	eCommandType;
enum	eOperandType;

class	IOperand;
class	Int8;
class	Int16;
class	Int32;
class	Float;
class	Double;

struct	Global;

class	CommandStack;
class	OperandStack;

#endif

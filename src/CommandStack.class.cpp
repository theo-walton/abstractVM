
#include "abstractvm.hpp"

CommandStack::CommandStack(void)
{
	_exit = false;
}

CommandStack::~CommandStack(void)
{
	_stack.clean();
}

CommandStack::CommandStack(CommandStack &obj)
{
	*this = obj;
}

CommandStack	&CommandStack::operator = (const CommandStack &obj)
{
	if (this != &obj)
	{
		_stack = obj._stack;
		_type = obj._type;
		_command = obj._command;
		_value = obj._value;
		_exit = obj._exit;
	}
	return (*this);
}

void	CommandStack::rangeCheck(std::string value, eOperandType type)
{
	//get the number between the brackets
	value.erase(0, value.find('(') + 1);	
	value.erase(value.find(')'));
	
	long int n = strtol(value.c_str(), nullptr, 10);
	double f = strtod(value.c_str(), nullptr);


	if ((type == Int8 && n <= CHAR_MAX && n >= CHAR_MIN) ||
	    (type == Int16 && n <= SHRT_MAX && n >= SHRT_MIN) ||
	    (type == Int32 && n <= INT_MAX && n >= INT_MIN) ||
	    ((type == Float || type == Double) && isfinite(f)))
	{
		_value = value;
		_type = type;
	}
	else
	{
		throw RangeError();
	}
}

void	CommandStack::parseValue(std::string value)
{
	if (std::regex_match(value, std::regex("int8\\([-]?[0-9]+\\)")))
	{
		rangeCheck(value, Int8);
	}
	else if (std::regex_match(value, std::regex("int16\\([-]?[0-9]+\\)")))
	{
		rangeCheck(value, Int16);
	}
	else if (std::regex_match(value, std::regex("int32\\([-]?[0-9]+\\)")))
	{
		rangeCheck(value, Int32);
	}
	else if (std::regex_match(value, std::regex("float\\([-]?[0-9]+[.][0-9]+\\)")))
	{
		rangeCheck(value, Float);
	}
	else if (std::regex_match(value, std::regex("double\\([-]?[0-9]+[.][0-9]+\\)")))
	{
		rangeCheck(value, Double);
	}
	else
	{
		throw SyntaxError();		
	}
}

void	CommandStack::parseCommand(std::string command)
{
	if (std::regex_match(command, std::regex("push.*")))
	{
		_command = Push;
	}
	else if (command == "pop")
	{
		_command = Pop;		
	}
	else if (command == "dump")
	{
		_command = Dump;
	}
	else if (std::regex_match(command, std::regex("assert.*")))
	{
		_command = Assert;
	}
	else if (command == "add")
	{
		_command = Add;		
	}
	else if (command == "sub")
	{
		_command = Sub;
	}
	else if (command == "mul")
	{
		_command = Mul;
	}
	else if (command == "div")
	{
		_command = Div;
	}
	else if (command == "mod")
	{
		_command = Mod;
	}
	else if (command == "print")
	{
		_command = Print;
	}
	else if (command == "exit")
	{
		_command = Exit;
	}
	else
	{
		throw SyntaxError();
	}
}

void	CommandStack::runOperation(void)
{
	if (_command == Push)
	{
		_stack.push(Global::factory.createOperand(_type, _value));
	}
	else if (_command == Pop)
	{
		_stack.pop();
	}
	else if (_command == Dump)
	{
		_stack.dump();
	}
	else if (_command == Assert)
	{
		_stack.assert(Global::factory.createOperand(_type, _value));
	}
	else if (_command == Add)
	{
		_stack.add();
	}
	else if (_command == Sub)
	{
		_stack.sub();
	}
	else if (_command == Mul)
	{
		_stack.mul();
	}
	else if (_command == Div)
	{
		_stack.div();
	}
	else if (_command == Mod)
	{
		_stack.mod();
	}
	else if (_command == Print)
	{
		_stack.print();
	}
	else if (_command == Exit)
	{
		_exit = true;
	}
}


void	CommandStack::removeComments(std::string &line)
{

	//remove text after comment char
	if (line.find(';') != std::string::npos)
		line.erase(line.find(';'));

	//remove ending whitespace
	line.erase(line.find_last_not_of(' ') + 1);

}


void	CommandStack::executeLine(std::string line)
{
	removeComments(line);
	if (line.empty())
		return;
	parseCommand(line);
	if (_command == Push || _command == Assert)
	{
		line.erase(0, line.find(' ') + 1);
		parseValue(line);
	}
	if (!_exit)
		runOperation();
}

bool	CommandStack::shouldExit(void)
{
	return (_exit);
}

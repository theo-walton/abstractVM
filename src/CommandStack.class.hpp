#ifndef COMMANDSTACK_CLASS_HPP
#define COMMANDSTACK_CLASS_HPP

#include "abstractvm.hpp"

class	CommandStack : public CommandException
{
	OperandStack _stack;
	
	eOperandType _type;
	eCommandType _command;
	std::string _value;
	bool _exit;
       
	void	parseCommand(std::string command);
	void	parseValue(std::string value);
	void	rangeCheck(std::string value, eOperandType type);
	void	runOperation(void);
	void	removeComments(std::string &line);
	
public:

	CommandStack(void);
	virtual	~CommandStack(void);
	CommandStack(CommandStack &obj);
	CommandStack	&operator = (const CommandStack &obj);

	
	void	executeLine(std::string line);
	bool	shouldExit(void);
};

#endif

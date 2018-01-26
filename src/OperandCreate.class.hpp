#ifndef OPERANDCREATE_CLASS_HPP
#define OPERANDCREATE_CLASS_HPP

#include "abstractvm.hpp"

class	OperandCreate
{
private:

	IOperand const	*createInt8(std::string const &value) const;
	IOperand const	*createInt16(std::string const &value) const;
	IOperand const	*createInt32(std::string const &value) const;
	IOperand const	*createFloat(std::string const &value) const;
	IOperand const	*createDouble(std::string const &value) const;
	
public:

	IOperand const *createOperand(eOperandType type, std::string const &val) const;
};

#endif

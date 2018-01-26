
#include "abstractvm.hpp"

IOperand const	*OperandCreate::createInt8(std::string const &value) const
{
	return (new Int8::Int8(value));
}

IOperand const	*OperandCreate::createInt16(std::string const &value) const
{
	return (new Int16::Int16(value));
}

IOperand const	*OperandCreate::createInt32(std::string const &value) const
{
	return (new Int32::Int32(value));
}

IOperand const	*OperandCreate::createFloat(std::string const &value) const
{
	return (new Float::Float(value));
}

IOperand const	*OperandCreate::createDouble(std::string const &value) const
{
	return (new Double::Double(value));
}

IOperand const	*OperandCreate::createOperand(eOperandType type,
					      std::string const &val) const
{
	if (type == Int8)
		return createInt8(val);
	else if (type == Int16)
		return createInt16(val);
	else if (type == Int32)
		return createInt32(val);
	else if (type == Float)
		return createFloat(val);
	else if (type == Double)
		return createDouble(val);
	else
		return nullptr;
}

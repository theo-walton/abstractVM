
#include "abstractvm.hpp"

Int16::Int16(void)
{
}

Int16::~Int16(void)
{
}

Int16::Int16(Int16 &obj)
{
	*this = obj;
}

class Int16	&Int16::operator = (Int16 &obj)
{
	if (this != &obj)
	{
		_value = obj._value;
	}
	return (*this);
}

Int16::Int16(std::string value)
{
	_value = value;
}

int	Int16::getPrecision(void) const
{
	return (1);
}

eOperandType	Int16::getType(void) const
{
	return (::Int16);
}

std::string const	&Int16::toString(void) const
{
	return (_value);
}

IOperand const	*Int16::operator + (IOperand const &rhs) const
{
	eOperandType t;

	if (this->getPrecision() > rhs.getPrecision())
		t = this->getType();
	else
		t = rhs.getType();

	std::string result = StrMath::Add(this->toString(), rhs.toString());

	StrMath::checkRange(result, t);
	return Global::factory.createOperand(t, result);
}

IOperand const	*Int16::operator - (IOperand const &rhs) const
{
	eOperandType t;

	if (this->getPrecision() > rhs.getPrecision())
		t = this->getType();
	else
		t = rhs.getType();

	std::string result = StrMath::Sub(this->toString(), rhs.toString());

	StrMath::checkRange(result, t);
	return Global::factory.createOperand(t, result);
}

IOperand const	*Int16::operator * (IOperand const &rhs) const
{
	eOperandType t;

	if (this->getPrecision() > rhs.getPrecision())
		t = this->getType();
	else
		t = rhs.getType();

	std::string result = StrMath::Mul(this->toString(), rhs.toString());

	StrMath::checkRange(result, t);
	return Global::factory.createOperand(t, result);
}

IOperand const	*Int16::operator / (IOperand const &rhs) const
{
	eOperandType t;

	if (this->getPrecision() > rhs.getPrecision())
		t = this->getType();
	else
		t = rhs.getType();

	std::string result = StrMath::Div(this->toString(), rhs.toString());

	StrMath::checkRange(result, t);
	return Global::factory.createOperand(t, result);
}

IOperand const	*Int16::operator % (IOperand const &rhs) const
{
	eOperandType t;

	if (this->getPrecision() > rhs.getPrecision())
		t = this->getType();
	else
		t = rhs.getType();

	std::string result = StrMath::Mod(this->toString(), rhs.toString());

	StrMath::checkRange(result, t);
	return Global::factory.createOperand(t, result);
}

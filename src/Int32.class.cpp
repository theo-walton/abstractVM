
#include "abstractvm.hpp"

Int32::Int32(void)
{
}

Int32::~Int32(void)
{
}

Int32::Int32(Int32 &obj)
{
	*this = obj;
}

class Int32	&Int32::operator = (Int32 &obj)
{
	if (this != &obj)
	{
		_value = obj._value;
	}
	return (*this);
}

Int32::Int32(std::string value)
{
	_value = value;
}

int	Int32::getPrecision(void) const
{
	return (2);
}

eOperandType	Int32::getType(void) const
{
	return (::Int32);
}

std::string const	&Int32::toString(void) const
{
	return (_value);
}

IOperand const	*Int32::operator + (IOperand const &rhs) const
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

IOperand const	*Int32::operator - (IOperand const &rhs) const
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

IOperand const	*Int32::operator * (IOperand const &rhs) const
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

IOperand const	*Int32::operator / (IOperand const &rhs) const
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

IOperand const	*Int32::operator % (IOperand const &rhs) const
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


#include "abstractvm.hpp"

Float::Float(void)
{
}

Float::~Float(void)
{
}

Float::Float(Float &obj)
{
	*this = obj;
}

class Float	&Float::operator = (Float &obj)
{
	if (this != &obj)
	{
		_value = obj._value;
	}
	return (*this);
}

Float::Float(std::string value)
{
	_value = value;
}

int	Float::getPrecision(void) const
{
	return (3);
}

eOperandType	Float::getType(void) const
{
	return (::Float);
}

std::string const	&Float::toString(void) const
{
	return (_value);
}

IOperand const	*Float::operator + (IOperand const &rhs) const
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

IOperand const	*Float::operator - (IOperand const &rhs) const
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

IOperand const	*Float::operator * (IOperand const &rhs) const
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

IOperand const	*Float::operator / (IOperand const &rhs) const
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

IOperand const	*Float::operator % (IOperand const &rhs) const
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


#include "abstractvm.hpp"

Int8::Int8(void)
{
}

Int8::~Int8(void)
{
}

Int8::Int8(Int8 &obj)
{
	*this = obj;
}

class Int8	&Int8::operator = (Int8 &obj)
{
	if (this != &obj)
	{
		_value = obj._value;
	}
	return (*this);
}

Int8::Int8(std::string value)
{
	_value = value;
}

int	Int8::getPrecision(void) const
{
	return (0);
}

eOperandType	Int8::getType(void) const
{
	return (::Int8);
}

std::string const	&Int8::toString(void) const
{
	return (_value);
}

IOperand const	*Int8::operator + (IOperand const &rhs) const
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

IOperand const	*Int8::operator - (IOperand const &rhs) const
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

IOperand const	*Int8::operator * (IOperand const &rhs) const
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

IOperand const	*Int8::operator / (IOperand const &rhs) const
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

IOperand const	*Int8::operator % (IOperand const &rhs) const
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

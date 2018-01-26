
#include "abstractvm.hpp"

Double::Double(void)
{	
}

Double::~Double(void)
{
}

Double::Double(Double &obj)
{
	*this = obj;
}

class Double	&Double::operator = (Double &obj)
{
	if (this != &obj)
	{
		_value = obj._value;
	}
	return (*this);
}

Double::Double(std::string value)
{
	_value = value;
}

int	Double::getPrecision(void) const
{
	return (4);
}

eOperandType	Double::getType(void) const
{
	return (::Double);
}

std::string const	&Double::toString(void) const
{
	return (_value);
}

IOperand const	*Double::operator + (IOperand const &rhs) const
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

IOperand const	*Double::operator - (IOperand const &rhs) const
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

IOperand const	*Double::operator * (IOperand const &rhs) const
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

IOperand const	*Double::operator / (IOperand const &rhs) const
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

IOperand const	*Double::operator % (IOperand const &rhs) const
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

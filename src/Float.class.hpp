#ifndef FLOAT_CLASS_HPP
#define FLOAT_CLASS_HPP

#include "abstractvm.hpp"

class	Float : public IOperand
{
	Float(void);
	
	std::string _value;

public:

	Float(std::string value);
	virtual	~Float(void);
	Float(Float &obj);
	Float	&operator = (Float &obj);
	
	int getPrecision( void ) const;
	eOperandType getType( void ) const;

	IOperand const *operator + (IOperand const &rhs) const;
	IOperand const *operator - (IOperand const &rhs) const;
	IOperand const *operator * (IOperand const &rhs) const;
	IOperand const *operator / (IOperand const &rhs) const;
	IOperand const *operator % (IOperand const &rhs) const;

	std::string const & toString( void ) const;
};

#endif

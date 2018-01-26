#ifndef INT8_CLASS_HPP
#define INT8_CLASS_HPP

#include "abstractvm.hpp"

class	Int8 : public IOperand
{
	Int8(void);
	
	std::string _value;

public:

	Int8(std::string value);
	virtual	~Int8(void);
	Int8(Int8 &obj);
	Int8	&operator = (Int8 &obj);
	
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

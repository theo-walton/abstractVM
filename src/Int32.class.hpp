#ifndef INT32_CLASS_HPP
#define INT32_CLASS_HPP

#include "abstractvm.hpp"

class	Int32 : public IOperand
{
	Int32(void);
	
	std::string _value;

public:

	Int32(std::string value);
	virtual	~Int32(void);
	Int32(Int32 &obj);
	Int32	&operator = (Int32 &obj);
	
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

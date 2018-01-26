#ifndef INT16_CLASS_HPP
#define INT16_CLASS_HPP

#include "abstractvm.hpp"

class	Int16 : public IOperand
{
	Int16(void);
	
	std::string _value;
	
public:

	Int16(std::string value);
	virtual ~Int16(void);
	Int16(Int16 &obj);
	Int16	&operator = (Int16 &obj);
	
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

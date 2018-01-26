#ifndef DOUBLE_CLASS_HPP
#define DOUBLE_CLASS_HPP

#include "abstractvm.hpp"

class	Double : public IOperand
{
	Double(void);
	
	std::string _value;

public:

	Double(std::string value);
	virtual	~Double(void);
	Double(Double &obj);
	Double	&operator = (Double &obj);		
	
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

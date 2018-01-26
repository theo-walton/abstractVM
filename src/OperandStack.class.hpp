#ifndef OPERANDSTACK_CLASS_HPP
#define OPERANDSTACK_CLASS_HPP

#include "abstractvm.hpp"

class	OperandStack : public CommandException
{
	std::vector<IOperand const *> _stack;

public:

	OperandStack(void);
	virtual ~OperandStack(void);
	OperandStack(OperandStack &obj);
	OperandStack	&operator = (const OperandStack &);
	
	void	push(IOperand const *);
	void	pop(void);
	void	dump(void);
	void	assert(IOperand const *);
	void	add(void);
	void	sub(void);
	void	mul(void);
	void	div(void);
	void	mod(void);
	void	print(void);
	void	exit(void);

	void	clean(void);
};

#endif

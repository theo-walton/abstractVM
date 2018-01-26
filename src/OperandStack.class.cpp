
#include "abstractvm.hpp"

OperandStack::OperandStack(void)
{	
}

OperandStack::~OperandStack(void)
{
}

OperandStack::OperandStack(OperandStack &obj)
{
	*this = obj;
}

OperandStack	&OperandStack::operator = (const OperandStack &)
{
	return (*this);
}

void	OperandStack::push(IOperand const *n)
{
	_stack.push_back(n);
}

void	OperandStack::pop(void)
{
	if (!_stack.size())
	{
		throw EmptyStack();
	}
	_stack.erase(_stack.end() - 1);	
}

void	OperandStack::dump(void)
{
	for (int i = _stack.size() - 1; i >= 0; i--)
	{
		Global::outStream << _stack[i]->toString() << std::endl;
	}
}

void	OperandStack::assert(IOperand const *n)
{
	if (!_stack.size())
	{
		throw EmptyStack();
	}
	
	if ((_stack[_stack.size() - 1]->getType() != n->getType()) ||
	    (_stack[_stack.size() - 1]->toString() != n->toString()))
	{
		throw FalseAssert();		
	}
}

void	OperandStack::add(void)
{
	if (_stack.size() < 2)
	{
		throw LackOfValues();
	}
	
	IOperand const *a;
	IOperand const *b;

	a = _stack.back();
	_stack.pop_back();
	b = _stack.back();
	_stack.pop_back();
	
	try
	{
		_stack.push_back(*b + *a);
	}
	catch (std::exception &e)
	{
		delete a;
		delete b;
		throw e;
	}
}

void	OperandStack::sub(void)
{
	if (_stack.size() < 2)
	{
		throw LackOfValues();
	}

	IOperand const *a;
	IOperand const *b;

	a = _stack.back();
	_stack.pop_back();
	b = _stack.back();
	_stack.pop_back();

	try
	{
		_stack.push_back(*b - *a);
	}
	catch (std::exception &e)
	{
		delete a;
		delete b;
		throw e;
	}
}

void	OperandStack::mul(void)
{
	if (_stack.size() < 2)
	{
		throw LackOfValues();
	}

	IOperand const *a;
	IOperand const *b;

	a = _stack.back();
	_stack.pop_back();
	b = _stack.back();
	_stack.pop_back();

	try
	{
		_stack.push_back(*b * *a);
	}
	catch (std::exception &e)
	{
		delete a;
		delete b;
		throw e;
	}
}

void	OperandStack::div(void)
{
	if (_stack.size() < 2)
	{
		throw LackOfValues();
	}

	IOperand const *a;
	IOperand const *b;

	a = _stack.back();
	_stack.pop_back();
	b = _stack.back();
	_stack.pop_back();

	if (strtod(a->toString().c_str(), nullptr) == 0)
	{
		delete a;
		delete b;
		throw ZeroDivision();
	}

	try
	{
		_stack.push_back(*b / *a);
	}
	catch (std::exception &e)
	{
		delete a;
		delete b;
		throw e;
	}
}

void	OperandStack::mod(void)
{
	if (_stack.size() < 2)
	{
		throw LackOfValues();
	}

	IOperand const *a;
	IOperand const *b;

	a = _stack.back();
	_stack.pop_back();
	b = _stack.back();
	_stack.pop_back();

	if (strtod(a->toString().c_str(), nullptr) == 0)
	{
		delete a;
		delete b;
		throw ZeroDivision();
	}
	
	_stack.push_back(*b % *a);
	delete a;
	delete b;
}

void	OperandStack::print(void)
{
	if (!_stack.size())
	{
		throw EmptyStack();
	}
	long int n = strtol(_stack.back()->toString().c_str(), nullptr, 10);

	Global::outStream << static_cast<char>(n) << std::endl;
}

void	OperandStack::exit(void)
{
	std::exit(1);	
}

void	OperandStack::clean(void)
{
	while (_stack.size())
	{
		delete _stack.back();
		_stack.pop_back();
	}
}

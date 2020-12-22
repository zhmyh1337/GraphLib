#pragma once

#include <string>

#include "IVisitor.h"

class IBase
{
public:
	virtual void Accept(IVisitor* visitor) = 0;
};

class A : public IBase
{
public:
	int X = 1337;

	void Accept(IVisitor* visitor) override
	{
		visitor->VisitA(this);
	}
};

class B : public IBase
{
public:
	std::string Method()
	{
		return "abacaba";
	}

	void Accept(IVisitor* visitor) override
	{
		visitor->VisitB(this);
	}
};

class C : public IBase
{
public:
	int Sum(int a, int b)
	{
		return a + b;
	}

	void Accept(IVisitor* visitor) override
	{
		visitor->VisitC(this);
	}
};

class D : public A
{
public:
	int Y = 2;
	float Method()
	{
		return (float)X / Y;
	}

	void Accept(IVisitor* visitor) override
	{
		visitor->VisitD(this);
	}
};

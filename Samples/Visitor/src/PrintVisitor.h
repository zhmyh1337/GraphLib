#pragma once

#include <iostream>

#include "IVisitor.h"
#include "Classes.h"

class PrintVisitor : public IVisitor
{
public:
	void VisitA(A* obj) override
	{
		std::cout << "Visiting A: " << obj->X << std::endl;
	}

	void VisitB(B* obj) override
	{
		std::cout << "Visiting B: " << obj->Method() << std::endl;
	}

	void VisitC(C* obj) override
	{
		std::cout << "Visiting C: " << obj->Sum(2, 3) << std::endl;
	}

	void VisitD(D* obj) override
	{
		std::cout << "Visiting D: " << obj->Method() << std::endl;
	}
};

#pragma once

class A;
class B;
class C;
class D;

class IVisitor
{
public:
	virtual void VisitA(A* obj) = 0;
	virtual void VisitB(B* obj) = 0;
	virtual void VisitC(C* obj) = 0;
	virtual void VisitD(D* obj) = 0;
};

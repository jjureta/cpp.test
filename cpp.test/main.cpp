//
//  main.cpp
//  cpp.virtual
//
//  Created by Josip Jureta on 2016-06-04.
//  Copyright © 2016 Josip Jureta. All rights reserved.
//

#include "stdafx.h"

#include <iostream>
#include <memory>

#include "../include/test_ptr.hpp"
#include "../include/test_case.hpp"

class Base {
public:
	Base() {
		std::cout << "Base()" << std::endl;
	}

	~Base() {
		std::cout << "~Base()" << std::endl;
	}

	void say_hi() const {
		std::cout << "Base::say_hi()" << std::endl;
	}

	virtual void say_hi_virtual() const {
		std::cout << "Base::say_hi()" << std::endl;
	}
};

class BaseVirtualDestructor {
public:
	BaseVirtualDestructor() {
		std::cout << "BaseVirtualDestructor()" << std::endl;
	}

	virtual ~BaseVirtualDestructor() {
		std::cout << "~BaseVirtualDestructor()" << std::endl;
	}

	void say_hi() const {
		std::cout << "BaseVirtualDestructor::say_hi()" << std::endl;
	}

	virtual void say_hi_virtual() const {
		std::cout << "BaseVirtualDestructor::say_hi_virtual()" << std::endl;
	}
};

class Derived: public Base {
public:
	Derived() {
		std::cout << "Derived()" << std::endl;
	}

	~Derived() {
		std::cout << "~Derived()" << std::endl;
	}
};

class DerivedVirtualDestructor: public BaseVirtualDestructor {
public:
	DerivedVirtualDestructor() {
		std::cout << "DerivedVirtualDestructor()" << std::endl;
	}

	~DerivedVirtualDestructor() {
		std::cout << "~DerivedVirtualDestructor()" << std::endl;
	}
};

class NonVirtualBase1 : public BaseVirtualDestructor {
public:
	NonVirtualBase1() {
		std::cout << "NonVirtualBase1()" << std::endl;
	}

	~NonVirtualBase1() {
		std::cout << "~NonVirtualBase1()" << std::endl;
	}
};

class NonVirtualBase2 : public BaseVirtualDestructor {
public:
	NonVirtualBase2() {
		std::cout << "NonVirtualBase2()" << std::endl;
	}

	~NonVirtualBase2() {
		std::cout << "~NonVirtualBase2()" << std::endl;
	}
};

class VirtualBase1: public virtual BaseVirtualDestructor {
public:
	VirtualBase1() {
		std::cout << "VirtualBase1()" << std::endl;
	}

	~VirtualBase1() {
		std::cout << "~VirtualBase1()" << std::endl;
	}
};

class VirtualBase2: public virtual BaseVirtualDestructor {
public:
	VirtualBase2() {
		std::cout << "VirtualBase2()" << std::endl;
	}

	~VirtualBase2() {
		std::cout << "~VirtualBase2()" << std::endl;
	}
};

class NonVirtualBase: public NonVirtualBase1, NonVirtualBase2 {
public:
	NonVirtualBase() {
		std::cout << "NonVirtualBase()" << std::endl;
	}

	~NonVirtualBase() {
		std::cout << "~NonVirtualBase()" << std::endl;
	}
};

class VirtualBase : public virtual VirtualBase1, virtual VirtualBase2 {
public:
	VirtualBase() {
		std::cout << "VirtualBase()" << std::endl;
	}

	~VirtualBase() {
		std::cout << "~VirtualBase()" << std::endl;
	}
};

void test_virtual() {
	{
		test_case t1("dlete derived class pointer");
		{
			std::unique_ptr<Derived> pb(new Derived);
		}
	}

	{
		test_case t1("delete base class pointer");
		{
			std::unique_ptr<Base> pa(new Derived);
		}
	}

	{
		test_case t1("delete derived class pointer (virtual destructor)");
		{
			std::unique_ptr<DerivedVirtualDestructor> pb(
					new DerivedVirtualDestructor);
		}
	}

	{
		test_case t1("delete base class pointer (virtual destructor)");
		{
			std::unique_ptr<BaseVirtualDestructor> pa(
					new DerivedVirtualDestructor);
		}
	}

	{
		test_case t1("calling method from non virtual inheritance");
		{
			NonVirtualBase nvb;

			// error: multiple base classes
			// nvb.say_hi();
		}
	}

	{
		test_case t1("calling method from virtual inheritance");
		{
			VirtualBase vb;

			vb.say_hi();
		}
	}

	std::cout << "-------------------------------------------" << std::endl;
	{
		// error: ambiguos conversion from derived class NonVirtualBase to base class NonVirtualBase1
		// std::unique_ptr<NonVirtualBase1> pa(new NonVirtualBase);
	}

	std::cout << "-------------------------------------------" << std::endl;
	{
		std::unique_ptr<VirtualBase1> pa(new VirtualBase);
	}
}

int main(int argc, const char * argv[]) {
	//test_ptr();

	test_virtual();

	return 0;
}

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

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    
    ~A() {
        std::cout << "~A()" << std::endl;
    }
    
    void say_hi() {
        std::cout << "A::say_hi()" << std::endl;
    }
};

class AV {
public:
    AV() {
        std::cout << "AV()" << std::endl;
    }
    
    ~AV() {
        std::cout << "~AV()" << std::endl;
    }
};

class BA : public A {
public:
    BA() {
        std::cout << "BA()" << std::endl;
    }
    
    ~BA() {
        std::cout << "~BA()" << std::endl;
    }
};

class X : public A {
public:
    X() {
        std::cout << "X()" << std::endl;
    }
    
    ~X() {
        std::cout << "~X()" << std::endl;
    }
};

class Y : public A {
public:
    Y() {
        std::cout << "Y()" << std::endl;
    }
    
    ~Y() {
        std::cout << "~Y()" << std::endl;
    }
};

class Z : public X,Y {
public:
    Z() {
        std::cout << "Z()" << std::endl;
    }
    
    ~Z() {
        std::cout << "~Z()" << std::endl;
    }
};

void test_virtual() {
	{
		test_case t1("derived class pointor");
		{
			std::unique_ptr<BA> pb(new BA);
		}
	}

	{
		test_case t1("base class pointor");
		{
			std::unique_ptr<A> pa(new BA);
		}
	}

	{
		Z z;

		// error: multiple base classes
		// z.say_hi();
	}

	std::cout << "-------------------------------------------" << std::endl;
	{
		// error: ambiguos conversion from derived class Z to base class A
		// std::unique_ptr<A> pa(new Z);
	}

	std::cout << "-------------------------------------------" << std::endl;
	{
		std::unique_ptr<X> pa(new Z);
	}
}

int main(int argc, const char * argv[]) {
	test_ptr();

    return 0;
}

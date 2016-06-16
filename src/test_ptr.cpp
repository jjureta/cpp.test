/*
 * test_ptr.cpp
 *
 *  Created on: 2016-06-15
 *      Author: j_jur_000
 */
#include "stdafx.h"

#include <iostream>
#include <memory>
#include <vector>

#include "../include/test_case.hpp"
#include "../include/a.hpp"

using namespace std;

/**
 * auto_ptr
 */
void test_auto_ptr() {
	{
		{
			test_case t1("auto_ptr scope");
			{
				auto_ptr<A> pta( new A);
			}
		}

		{
			test_case t2("auto_ptr copy constructor");
			{
				auto_ptr<A> pta( new A);
				auto_ptr<A> ptb = pta;

				cout << "pta: " << pta.get() << endl;
				cout << "ptb: " << ptb.get() << endl;
			}
		}

		{
			test_case t3("auto_ptr copy constructor in function call");
			{
				auto_ptr<A> pta( new A);

				call_by_value(pta);

				cout << "pta: " << pta.get() << endl;
			}
		}

		{
			test_case t4("auto_ptr in containers ");
			{
				auto_ptr<A> pta( new A);

				vector<auto_ptr<A> > v;

				//v.push_back(pta);

				cout << "pta: " << pta.get() << endl;
			}
		}
	}
}

/**
 * unique_ptr
 */
void test_unique_ptr() {
	{
		{
			test_case t1("unique_ptr scope");
			{
				unique_ptr<A> pta( new A);
			}
		}

		{
			test_case t2("unique_ptr copy constructor");
			{
				unique_ptr<A> pta( new A);
				//unique_ptr<A> ptb = pta;

				cout << "pta: " << pta.get() << endl;
				//cout << "ptb: " << ptb.get() << endl;
			}
		}

		{
			test_case t3("unique_ptr copy constructor in function call");
			{
				unique_ptr<A> pta( new A);

				//call_by_value(pta);

				cout << "pta: " << pta.get() << endl;
			}
		}

		{
			test_case t4("unique_ptr in containers ");
			{
				auto_ptr<A> pta( new A);

				vector<auto_ptr<A> > v;

				//v.push_back(pta);

				cout << "pta: " << pta.get() << endl;
			}
		}
	}
}

/**
 * shared_ptr
 */
void test_shared_ptr() {
	{
		{
			test_case t1("shared_ptr scope");
			{
				shared_ptr<A> pta( new A);
			}
		}

		{
			test_case t2("shared_ptr copy constructor");
			{
				shared_ptr<A> pta( new A);
				shared_ptr<A> ptb = pta;

				cout << "pta: " << pta.get() << endl;
				cout << "ptb: " << ptb.get() << endl;
			}
		}

		{
			test_case t3("shared_ptr copy constructor in function call");
			{
				shared_ptr<A> pta( new A);
				call_by_value(pta);
				cout << "pta: " << pta.get() << endl;
			}
		}

		{
			test_case t4("shared_ptr in containers ");
			{
				const shared_ptr<A> pta( new A);
				vector<shared_ptr<A> > v;
				v.push_back(pta);


				cout << "pta: " << pta.get() << endl;
			}
		}
	}
}

void test_ptr() {
	test_auto_ptr();

	test_unique_ptr();

	test_shared_ptr();
}

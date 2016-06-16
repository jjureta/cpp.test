/*
 * a.hpp
 *
 *  Created on: 2016-06-15
 *      Author: j_jur_000
 */

#ifndef A_HPP_
#define A_HPP_

#include <iostream>

using namespace std;

class A {
public:
	~A() {
		cout << "~A()" << endl;
	}
};

template<typename T>
void call_by_value(const T t) {

}

#endif /* A_HPP_ */

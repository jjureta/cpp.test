/*
 * test_case.hpp
 *
 *  Created on: 2016-06-15
 *      Author: j_jur_000
 */

#ifndef TEST_CASE_HPP_
#define TEST_CASE_HPP_

#include <string>
#include <iostream>

class test_case {
public:
	test_case(const std::string& tn) : test_case_name(tn) {
		std::cout << "Start test case: " << test_case_name << std::endl;
	}

	test_case(const char* tn) : test_case_name(std::string(tn)) {
		std::cout << "Start test case: " << test_case_name << std::endl;
	}

	~test_case() {
		std::cout << "End test case: " << test_case_name << std::endl;
	}

private:
	const std::string test_case_name;
};

#endif /* TEST_CASE_HPP_ */



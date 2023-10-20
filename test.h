#ifndef _test_h_
#define _test_h_

#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "task2.h"

template<class T, class U>
void assert_equal(const T& expr, const U& expr_true,
	const std::string& expr_str, const std::string& expr_true_str, const std::string& hint){
	if (typeid(expr).name() == typeid(expr_true).name()){
		std::cout << "BAD - type " << expr_str << " != type " << expr_true_str << " : " << std::endl;
		return;
	}
	if (expr == expr_true){
		std::cout << "OK" << std::endl;
		return;
	}
	std::cout << "BAD - " << expr_str << " != " << expr_true_str;
	if (hint != ""){
		std::cout << " : " << hint << std::endl;
		return;
	}
	std::cout << std::endl;

}

void assert_test(bool expr, const std::string& expr_str, const std::string& hint);

template<class T>
void run_test(T f_test, std::string f_test_str){
	std::cerr << "RUN_TEST\t" << f_test_str << std::endl;
	f_test();
	std::cerr << "test end" << std::endl;
}

void test_RationalAdd();

#define ASSERT(expr) assert_test(expr, #expr, "")
#define ASSERT_HINT(expr, hint) assert_test(expr, #expr, hint)
#define ASSERT_EQUAL(expr, expr_true) assert_equal(expr, expr_true, #expr, #expr_true, "")
#define ASSERT_EQUAL_HINT(expr, expr_true, hint) assert_equal(expr, expr_true, #expr, #expr_true, hint)
#define RUN_TEST(func) run_test(func, #func)

#endif

#include "test.h"

void assert_test(bool expr, const std::string& expr_str, const std::string& hint){
	if (expr){
		std::cout << "OK" << std::endl;
		return;
	}
	std::cout << "BAD - " << expr_str << " : " << hint << std::endl;
}

void test_RationalAdd(){
	{
		Rational a(1, 7);
		Rational b(4, 5);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 33 && c.denominator() == 35));
	}
	{
		Rational a(1, 8);
		Rational b(1, 4);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 3 && c.denominator() == 8));
	}
	{
		Rational a(1, 4);
		Rational b(5, 6);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 13 && c.denominator() == 12));
	}
	{
		Rational a(1, 7);
		Rational b(1, 5);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 12 && c.denominator() == 35));
	}
	{
		Rational a(1);
		Rational b(1, 5);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 6 && c.denominator() == 5));
	}
	{
		Rational a(1);
		Rational b(1);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 2 && c.denominator() == 1));
	}
	{
		Rational a(1);
		Rational b;
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 1 && c.denominator() == 1));
	}
	{
		Rational a(1, 128);
		Rational b(1, 2);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 65 && c.denominator() == 128));
	}
	{
		Rational a;
		Rational b;
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 0 && c.denominator() == 1));
	}
	{
		Rational a(1024, 128);
		Rational b(133, 64);
		Rational c = Rational::Add(a, b);
		ASSERT((c.numerator() == 1290 && c.denominator() == 128));
	}
}
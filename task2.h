#ifndef _task2_h_
#define _task2_h_

#include <iostream>

class Rational {
	private:
		int numerator_;
		int denominator_;
		int gcd(int a, int b);
	public:
		Rational();
		Rational(int numerator);
		Rational(int numerator, int denominator);

		Rational operator+(const Rational& num);
		Rational operator-(const Rational& num);
		Rational operator*(const Rational& num);
		Rational operator/(const Rational& num);

		static Rational Add(const Rational& a, const Rational& b);

		int numerator() const {return numerator_;}
		int denominator() const {return denominator_;}
};

std::ostream& operator<<(std::ostream& s, const Rational& a);

#endif

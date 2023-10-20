#ifndef _task2_h_
#define _task2_h_

class Rational {
	private:
		int numerator_;
		int denominator_;
		int gcd(int a, int b);
	public:
		Rational();
		Rational(int numerator);
		Rational(int numerator, int denominator);

		static Rational Add(const Rational& a, const Rational& b);

		int numerator() const {return numerator_;}
		int denominator() const {return denominator_;}
};

#endif

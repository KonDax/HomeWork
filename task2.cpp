#include "task2.h"

Rational Rational::operator+(const Rational& b){
	int NOD = gcd(denominator_, b.denominator());
        int numer = numerator_*b.denominator()/NOD+b.numerator()*denominator_/NOD;
        int denomer = denominator_*b.denominator()/NOD;
        return Rational(numer, denomer);
}

Rational Rational::operator*(const Rational& b){
        return Rational(numerator_*b.numerator(), denominator_*b.denominator());
}

Rational Rational::operator-(const Rational& b){
        int NOD = gcd(denominator_, b.denominator());
        int numer = (numerator_*b.denominator()/NOD)-(b.numerator()*denominator_/NOD);
        int denomer = denominator_*b.denominator()/NOD;
        return Rational(numer, denomer);
}

Rational Rational::operator/(const Rational& b){
        if (b.numerator() == 0)
                return Rational();
	return Rational(numerator_*b.denominator(), denominator_*b.numerator());
}

std::ostream& operator<<(std::ostream& s, const Rational& a){
        s << a.numerator() << " / " << a.denominator();
        return s;
}

int Rational::gcd(int a, int b){
        if (a > b){
                a = a + b;
                b = a - b;
                a = a - b;
        }
        if (a == b - a | a == b)
                return a;
        return gcd(a, b - a);
}

Rational::Rational(){
	numerator_ = 0;
	denominator_ = 1;
}

Rational::Rational(int numerator){
        numerator_ = numerator;
        denominator_ = 1;
}

Rational::Rational(int numerator, int denominator){
        numerator_ = numerator;
        denominator_ = denominator;
	if (numerator < 0)
		numerator = -1*numerator;
	if (denominator < 0)
		denominator = -1*denominator;
	if (numerator_ != 0){
		int gcd_int = gcd(numerator, denominator);
		numerator_ /= gcd_int;
		denominator_ /= gcd_int;
	}
	if (denominator_ < 0){
		denominator_ = -1 * denominator_;
		numerator_ = -1 * numerator_;
	}
}

Rational Rational::Add(const Rational& a, const Rational& b){
	Rational r;
        int NOD = r.gcd(a.denominator(), b.denominator());
        int numer = a.numerator()*b.denominator()/NOD+b.numerator()*a.denominator()/NOD;
        int denomer = a.denominator()*b.denominator()/NOD;
        return Rational(numer, denomer);
}

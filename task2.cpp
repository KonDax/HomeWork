#include "task2.h"

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
}

Rational Rational::Add(const Rational& a, const Rational& b){
        Rational r;
        int NOD = r.gcd(a.denominator(), b.denominator());
        int numer = a.numerator()*b.denominator()/NOD+b.numerator()*a.denominator()/NOD;
        int denomer = a.denominator()*b.denominator()/NOD;
        return Rational(numer, denomer);
}
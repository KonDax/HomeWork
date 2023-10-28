#include <iostream>
#include "test.h"

int main(){
	/*
	 * Раньне при компиляции cat_ создавался в момент Cat cat_ с конструктором по умолчанию, которого нет
	 * теперь Witch(const std::string& catName) : cat_(catName) {}
	 *
	 * cat_ всё равно создаётся в момент Cat cat_, но теперь подставляется catName
	 */
	RUN_TEST(test_Rational);
	RUN_TEST(test_operatorPlus);
	RUN_TEST(test_operatorMinus);
	RUN_TEST(test_operatorMyltiply);
	RUN_TEST(test_operatorDivide);
	
	std::cout << Rational(6, -5) / Rational(-5, 6) << std::endl;

	return 0;
}

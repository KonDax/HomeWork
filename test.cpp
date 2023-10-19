#include "test.h"

void assert_test(bool expr, const std::string& expr_str, const std::string& hint){
	if (expr){
		std::cout << "OK" << std::endl;
		return;
	}
	std::cout << "BAD - " << expr_str << " : " << hint << std::endl;
}

void test_ParseText(){
	FILE* f = fopen("test.txt", "w");
	{
		
	}
	fclose(f);
}
void test_CountWords();

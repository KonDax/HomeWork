#include <iostream>

int main(){
	/*
	 * Раньне при компиляции cat_ создавался в момент Cat cat_ с конструктором по умолчанию, которого нет
	 * теперь Witch(const std::string& catName) : cat_(catName) {}
	 *
	 * cat_ всё равно создаётся в момент Cat cat_, но теперь подставляется catName
	 */

	return 0;
}

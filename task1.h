#ifndef _ControlWork_20_10_2023_
#define _ControlWork_20_10_2023_

#include <string>

class Cat {
	public:
		Cat() = delete;
		Cat(const std::string& name){
			name_ = name;
		}
		std::string GetName() const {
			return name_;
		}
	private:
		std::string name_;
};

class Witch {
	public:
		Witch(const std::string& catName) : cat_(catName) {}
	private:
		Cat cat_;
};

#endif

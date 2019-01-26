#include <iostream>

#include <cassert>

#include <tuple.hpp>

class A {
private:
	int n;

public:
	A(int const n = 0): n{n} {}
	A(A const &a) noexcept = default;
	A(A &&a) noexcept = default;
	A &operator =(A const &) noexcept = default;
	A &operator =(A &&) noexcept = default;
	operator int() const noexcept {return n;}
};

using namespace version3;

auto getPerson() {
	A const a{146};
	std::string const name = "Petia";
	std::string const secondName = "Ivanoff";
	std::size_t const age = 23;
	std::string const department = "Sale";
	return custom_make_tuple(a, name, secondName, age, department);
}

void checkcopy() {
	A a;
	std::string name, secondName, department;
	std::size_t age;
	auto const person{getPerson()};

	custom_tie(a, name, secondName, age, department) = person;

	assert(a == 146);
	assert(name == "Petia");
	assert(secondName == "Ivanoff");
	assert(age == 23);
	assert(department == "Sale");
}

void checkmove() {
	A a;
	std::string name, secondName, department;
	std::size_t age;

	custom_tie(a, name, secondName, age, department) = getPerson();

	assert(a == 146);
	assert(name == "Petia");
	assert(secondName == "Ivanoff");
	assert(age == 23);
	assert(department == "Sale");
}

int main() {
	checkcopy();
	checkmove();
	std::cout << "OK" << std::endl;
	return 0;
}


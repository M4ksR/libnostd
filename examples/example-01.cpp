#include <iostream>
#include "libnostd/libnostd.hpp"
#include "libnostd/math/core.hpp"

int main() {
	println("LIBNOSTD");
	unsigned long mod = 1001;
	std::cout << "prod(2, 10, 1001) = " << math::prod(2, 10, mod) << std::endl;
	std::cout << "9! mod 1001 = " << math::factorial(9, mod) << std::endl;
	std::cout << "invmod(9!, 1001) = " << math::invmod( math::factorial(9, mod), mod) << std::endl;
	auto a = math::factorial(9, mod);
	auto b = math::invmod(a, mod);
	unsigned long x = 0;
	unsigned long y = 0;
	std::cout << "gcd(a, mod) = " << math::gcdex(a, mod, x, y) << std::endl;
	std::cout << "gcd(b, mod) = " << math::gcdex(b, mod, x, y) << std::endl;
	return 0;
}

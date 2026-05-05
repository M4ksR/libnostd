/**
 * @file
 * @brief Core utils for computer science
 * @date 2026-04-21
 * @authors svpogozhev
 * @copyright MIT License
 */
#include <string>
#include <algorithm>

namespace cs {

	std::string dec2hex(unsigned int decimal) {
		std::string hexademal;
		hexademal.reserve(20);
		const char hex_digits[] = "0123456789ABCDEF";
		do {
			// hexademal = hex_digits[decimal%16] + hexademal;
			hexademal += hex_digits[decimal%16];
			decimal /= 16;
		} while(decimal > 0);

		std::reverse(hexademal.begin(), hexademal.end());

		return hexademal;
	}

	unsigned int hex2dec(const std::string & hexademal) {
		unsigned int decimal = 0;
		int maxsize = sizeof(decimal) * 2;
		int cnt = 0;
		for(const char ch : hexademal) {
			unsigned int tmp = 0;
			if (std::isdigit(ch)) {
				tmp = ch - '0';
			} else if (std::isalpha(ch)) {
				tmp = std::toupper(ch) - 'A' + 10;
				if (tmp > 15) {
					tmp = 0;
					break;
				}
			} else {
				break;
			}
			decimal = decimal * 16 + tmp;
			++cnt;
			if (cnt >= maxsize) {
				break;
			}
		}
		return decimal;
	}

	std::string dec2bin(unsigned int decimal){
		std::string binary;
		binary.reserve(sizeof(decimal) * 8);
		do {
			binary += std::to_string(decimal % 2);
			decimal >>= 1;
		} while (decimal != 0);
		std::reverse(binary.begin(), binary.end());
		return binary;
	}
}

/**
 * @file
 * @brief Core utils for mathematics
 * @version 0.1.0
 * @date 2026-04-21
 * @authors svpogozhev
 * @copyright MIT License
 */
#include <cmath>

namespace math {

	double square(double num) {
		return num * num;
	}

	double fast_power(double base, unsigned long long exp) {
		double v = 1.0;
		while(exp!=0) {
			if ( exp & 1ULL ) {
				v *= base;
			}
			base *= base;
			exp >>= 1;
		}
		return v;
	}

	double sqrt_heron(double num) {
		if (num <= 0.0) {
			return 0.0;
		}
		double xn = num;
		double xn1 = num / 2.0;
		double eps = 1e-14;
		do {
			xn = xn1;
			xn1 = (xn + num / xn) / 2.0;
		} while(fabs(xn1 - xn) > eps);
		return xn;
	}
}

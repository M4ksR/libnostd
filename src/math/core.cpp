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

    unsigned long factorial(unsigned long n, unsigned long m) {
		unsigned long result = 1UL;
		for (unsigned long i = 1; i < n; ++i) {
			result *= (i + 1);
			result %= m;
		}
		return result;
	}

    unsigned long prod(unsigned long a, unsigned long b, unsigned long m) {
		if (b < a){
			unsigned long tmp = a;
			a = b;
			b = tmp;
		}
		unsigned long result = a;
		while(a < b){
			++a;
			result *= a;
			result %= m;
		}
		return result;
	}

	unsigned long binpowmod(unsigned long a, unsigned long deg, unsigned long m) {
		unsigned long result = 1UL;
		while (deg != 0) {
			if ( (deg & 1) ) {
				result = (result * a) % m;
			}
			a = (a * a) % m;
			deg >>= 1;
		}
		return result;
	}

	unsigned long invmod(unsigned long a, unsigned long m) {
		return binpowmod(a, m-2, m);
	}

	unsigned long gcdex(unsigned long a, unsigned long b, unsigned long &x, unsigned long &y){
		if (a == 0) {
			x = 0;
			y = 1;
			return b;
		}
		unsigned long x1 = 0;
		unsigned long y1 = 0;
		unsigned long d = gcdex(b%a, a, x1, y1);
		x = y1 - (b / a) * x1;
		y = x1;
		return d;
	}

}

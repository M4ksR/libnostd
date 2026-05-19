#include "libnostd/math/core.hpp"

namespace math {
	namespace statistics {

    	unsigned long binomial(unsigned long n, unsigned long k, unsigned long m) {
			if ((k == 0) || (k == n)) return 1UL;
			if (k > n) return 0UL;
			return (prod(k+1, n, m) * invmod(factorial(n-k, m), m)) % m;
		}

		double mean(const double M[], int n) {
			if (n < 1) {
				return 0;
			}
			double result = 0;
			for(int i = 0; i < n; ++i) {
				result += M[i];
			}
			result /= static_cast<double>(n);
			return result;
		}

        double var(const double M[], int n) {
            if (n < 1) {
                return 0;
            }
            double result1 = 0;
			double result2 = 0;
            for(int i = 0; i < n; ++i) {
                result1 += M[i];
				result2 += M[i] * M[i];
            }
			result1 /= static_cast<double>(n);
            return result2 / static_cast<double>(n) - result1 * result1;
        }

	}
}

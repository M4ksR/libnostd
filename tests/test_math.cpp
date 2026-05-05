#include <gtest/gtest.h>

#include "libnostd/math/core.hpp"

TEST(MATH, square) {
	EXPECT_DOUBLE_EQ(math::square(2), 4);
    EXPECT_DOUBLE_EQ(math::square(1), 1);

    using math::square;
    EXPECT_DOUBLE_EQ(square(0), 0);
    EXPECT_DOUBLE_EQ(square(100), 1e4);
    EXPECT_DOUBLE_EQ(square(-10), 100);
    EXPECT_DOUBLE_EQ(square(2.5), 6.25);
    EXPECT_DOUBLE_EQ(square(0.1), 1e-2);
}

TEST(MATH, sqrt_heron) {
	double tol = 1e-9;
	using math::sqrt_heron;
    EXPECT_NEAR(sqrt_heron(0.0), 0, tol);
    EXPECT_NEAR(sqrt_heron(1.0), 1, tol);
	EXPECT_NEAR(sqrt_heron(4.0), 2, tol);
    EXPECT_NEAR(sqrt_heron(100.0), 10, tol);
    EXPECT_NEAR(sqrt_heron(625.0), 25, tol);
	srand(1);
	for (int i = 0; i < 100; ++i) {
		double tmp = rand()/1000.0;
		double s = sqrt_heron(tmp);
		EXPECT_NEAR(s * s, tmp, tol);
	}
}

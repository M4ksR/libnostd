#include <gtest/gtest.h>

#include "libnostd/cs/core.hpp"

TEST(CS, dec2hex) {
	using cs::dec2hex;
	EXPECT_TRUE(dec2hex(0) == std::string("0"));
    EXPECT_TRUE(dec2hex(1) == std::string("1"));
    EXPECT_TRUE(dec2hex(15) == std::string("F"));
    EXPECT_TRUE(dec2hex(16) == std::string("10"));
    EXPECT_TRUE(dec2hex(32) == std::string("20"));
    EXPECT_TRUE(dec2hex(63) == std::string("3F"));
	EXPECT_TRUE(dec2hex(4294967295U) == std::string("FFFFFFFF"));
}

TEST(CS, hex2dec) {
	using cs::hex2dec;
	EXPECT_TRUE(hex2dec("0") == 0);
	EXPECT_TRUE(hex2dec("1") == 1);
	EXPECT_TRUE(hex2dec("F") == 15);
    EXPECT_TRUE(hex2dec("10") == 16);
    EXPECT_TRUE(hex2dec("20") == 32);
    EXPECT_TRUE(hex2dec("3F") == 63);
    EXPECT_TRUE(hex2dec("FFFFFFFF") == 4294967295U);

	EXPECT_TRUE(hex2dec("abba") == 43962);
    EXPECT_TRUE(hex2dec("aBbA") == 43962);
    EXPECT_TRUE(hex2dec("abba 123") == 43962);
    EXPECT_TRUE(hex2dec("abba-8") == 43962);
    EXPECT_TRUE(hex2dec("-2A") == 0);
    EXPECT_TRUE(hex2dec("3FH5") == 63);
    EXPECT_TRUE(hex2dec("H20") == 0);
    EXPECT_TRUE(hex2dec("C2H5OH") == 194);
	if (sizeof(unsigned int) == 4){
	    EXPECT_TRUE(hex2dec("FFFFFFFF1") == hex2dec("FFFFFFFF"));
	} else if (sizeof(unsigned int) == 8){
        EXPECT_TRUE(hex2dec("FFFFFFFFFFFFFFFF1") == hex2dec("FFFFFFFFFFFFFFFF"));
    }
}

TEST(CS, dec2bin) {
	using cs::dec2bin;
	EXPECT_TRUE( dec2bin(0) == std::string("0") );
    EXPECT_TRUE( dec2bin(1) == std::string("1") );
    EXPECT_TRUE( dec2bin(2) == std::string("10") );
    EXPECT_TRUE( dec2bin(10) == std::string("1010") );
    EXPECT_TRUE( dec2bin(15) == std::string("1111") );
    EXPECT_TRUE( dec2bin(16) == std::string("10000") );
    EXPECT_TRUE( dec2bin(256) == std::string("100000000") );
}

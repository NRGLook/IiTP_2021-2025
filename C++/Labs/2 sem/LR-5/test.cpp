#include "pch.h"
#include<gtest/gtest.h>
#include <cmath>
#include<iostream>
#include <iomanip>
int rec(int val_1, int val_2) {
	int F;

	if (val_1 > val_2)
	{
		return 0;
	}

	if (val_2 % 10 > 0)
	{
		F = val_2 % 10;
	}
	else if (val_2 == 0)
	{
		F = 0;
	}
	else
	{
		F = val_2 / 10;
	}
	return rec(val_1, val_2 - 1) + F;
}


TEST(LR31,input1)
{
  EXPECT_EQ(46, rec(1,10));
  EXPECT_TRUE(true);
}

TEST(LR31, input2)
{
	EXPECT_EQ(48, rec(10, 20));
	EXPECT_TRUE(true);
}

TEST(LR31, input3)
{
	EXPECT_EQ(52, rec(30, 40));
	EXPECT_TRUE(true);
}

TEST(LR31, input4)
{
	EXPECT_EQ(NULL, rec(-1, -1));
	EXPECT_TRUE(true);
}

unsigned long long output(unsigned long long k, unsigned long long n, unsigned long long m)
{
	if (!n)
	{
		return 1;
	}
	if (n % 2)
	{
		return (k * output((k * k) % m, n / 2, m)) % m;
	}
	else
	{
		return output((k * k) % m, n / 2, m);
	}
}

TEST(LR32, input1)
{
	EXPECT_EQ(736, output(1234, 1234, pow(10,4)));
	EXPECT_TRUE(true);
}
TEST(LR32, input2)
{
	EXPECT_EQ(39087387, output(2323, 99999999999, pow(10, 8)));
	EXPECT_TRUE(true);
}
TEST(LR32, input3)
{
	EXPECT_EQ(494777344, output(4, 99999, pow(10, 9)));
	EXPECT_TRUE(true);
}
TEST(LR32, input4)
{
	EXPECT_EQ(91255296, output(888, 888,pow(10,8)));
	EXPECT_TRUE(true);
}
int NODget(int val) {
	int NOD = val;
	if (val == 1) return 1;
	else {
		while ((val % NOD) || !(NOD % 2)) {
			NOD--;
		}
		return NOD;
	}
}
TEST(LR33, input1)
{
	EXPECT_EQ(1,NODget(1));
	EXPECT_TRUE(true);
}
/*TEST(LR33, input2)
{
	EXPECT_EQ(168, NODget(22));
	EXPECT_TRUE(false);
}
TEST(LR33, input3)
{
	EXPECT_EQ(21, NODget(7));
	EXPECT_TRUE(true);
}*/












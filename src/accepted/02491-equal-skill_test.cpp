#include "02491-equal-skill.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(EqualSkill, BasicTest) {
	Solution solution;

	EXPECT_EQ(22, solution.dividePlayers({5, 3, 7, 1}));
	EXPECT_EQ(22, solution.dividePlayers({3,2,5,1,3,4}));
	EXPECT_EQ(12, solution.dividePlayers({3,4}));
	EXPECT_EQ(-1, solution.dividePlayers({1, 1, 2, 3}));
}

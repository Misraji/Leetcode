#include "02517-candy-basket.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(CandyBasket, BasicTests) {
	Solution solution;

	std::vector<int> vec1 = {13, 5, 1, 8, 21, 2};
	EXPECT_EQ(solution.maximumTastiness(vec1, 3), 3);


	std::vector<int> vec2 = {1,3,1};
	EXPECT_EQ(solution.maximumTastiness(vec2, 2), 2);

	std::vector<int> vec3 = {7, 7, 7, 7};
	EXPECT_EQ(solution.maximumTastiness(vec3, 2), 0);
}

#include "00016-3sum-closest.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(SumClosest, BasicTest) {
	Solution solution;
	
	std::vector<int> nums = {-1, 2, 1, -4};
	EXPECT_THAT(solution.threeSumClosest(nums, 1), 2);

	nums = {0, 0, 0};
	EXPECT_THAT(solution.threeSumClosest(nums, 1), 0);

}

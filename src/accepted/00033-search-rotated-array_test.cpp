#include "00033-search-rotated-array.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(SearchRotated, EmptyTest) {
	Solution solution;
	std::vector<int> vec;

	EXPECT_THAT(-1, solution.search(vec, 1));
}

TEST(SearchRotated, BasicTest) {
	Solution solution;

	std::vector<int> vec1 = {4, 5, 6, 7, 0, 1, 2};
	EXPECT_THAT(4, solution.search(vec1, 0));
	EXPECT_THAT(-1, solution.search(vec1, 3));

	vec1 = {1};
	EXPECT_THAT(-1, solution.search(vec1, 0));
}

TEST(SearchRotated, ErrorTest) {
	Solution solution;

	std::vector<int> vec = {4,5,6,7,8,1,2,3};
	EXPECT_THAT(4, solution.search(vec, 8));

	vec = {1,3};
	EXPECT_THAT(0, solution.search(vec, 1));

	vec = {3, 1};
	EXPECT_THAT(1, solution.search(vec, 1));
}

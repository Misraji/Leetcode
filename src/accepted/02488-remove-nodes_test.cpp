#include "02488-remove-nodes.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::ElementsAre;

TEST(RemoveNodes, BasicTest) {
 	const std::vector<int> vec = {5};
	ListNode* list = createList(vec);
	ListNode* result = Solution().removeNodes(list);
	EXPECT_THAT(createVector(result), ElementsAre(5));
}

TEST(RemoveNodes, AllTests) {
 	const std::vector<int> vec1 = {5, 2};
	ListNode* list1 = createList(vec1);
	ListNode* result1 = Solution().removeNodes(list1);
	EXPECT_THAT(createVector(result1), ElementsAre(5,2));

 	const std::vector<int> vec2 = {5,2,13,8};
	ListNode* list2 = createList(vec2);
	ListNode* result2 = Solution().removeNodes(list2);
	EXPECT_THAT(createVector(result2), ElementsAre(13,8));

 	const std::vector<int> vec3 = {1,1,1,1};
	ListNode* list3 = createList(vec3);
	ListNode* result3 = Solution().removeNodes(list3);
	EXPECT_THAT(createVector(result3), ElementsAre(1));
}

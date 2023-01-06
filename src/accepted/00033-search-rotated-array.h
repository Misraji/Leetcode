#ifndef SRC_00033_SEARCH_ROTATED_ARRAY_H
#define SRC_00033_SEARCH_ROTATED_ARRAY_H

#include <vector>

class Solution {
	public:
		static constexpr int kNotFound = -1;
		int search(const std::vector<int>&nums, int target); 

	private:
		int findStart(const std::vector<int>& nums);
};

#endif // SRC_00033_SEARCH_ROTATED_ARRAY_H

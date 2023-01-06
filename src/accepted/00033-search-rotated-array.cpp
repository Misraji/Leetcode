#include "00033-search-rotated-array.h"

#include <iostream>

int Solution::findStart(const std::vector<int>& nums) {
	int lower = 0;
	int upper = nums.size() - 1;

	while (lower < upper) {
		int middle = (lower + upper)/2;
		if (nums[middle] < nums[upper]) {
			upper = middle;

		} else {
			lower = middle + 1; 
		}
	}
	return lower;
}

int Solution::search(const std::vector<int>& nums, int target) {
	if (nums.empty()) {
		return kNotFound;
	}

	int start_index = findStart(nums);
	std::cerr << "start_index = " << start_index << std::endl;

	int lower, upper;
	if (start_index == 0) {
		lower = 0;
		upper = nums.size() - 1;

	} else {
		const bool in_second = (target <= nums.back());
		lower = in_second? start_index : 0;
		upper = in_second? nums.size() - 1: start_index - 1;
	}

	while (lower <= upper) {
		int middle = lower + (upper - lower)/2;
		if (nums[middle] == target) {
			return middle;

		} else if (target < nums[middle]) {
			upper = middle - 1;

		} else {
			lower = middle + 1;
		}
	}
	return kNotFound;
}

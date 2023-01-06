#include "00016-3sum-closest.h"

#include <iostream>

int Solution::bruteforce(const std::vector<int>& nums, int target) {
	int current = 1000000;
	int current_diff = abs(target - current);

	for (size_t i = 0; i < nums.size(); i++) {
		for (size_t j = i+1; j < nums.size(); j++) {
			for (size_t k = j+1; k < nums.size(); k++) {
				const int sum = nums[i] + nums[j] + nums[k];
				const int diff = abs(target - sum);
				if (diff < current_diff) {
					current = sum;
					current_diff = diff;
				}
			}
		}
	}
	return current;
}

int Solution::threeSumClosest(const std::vector<int>& nums, int target) {
	// return bruteforce(nums, target);
	return -1;
}

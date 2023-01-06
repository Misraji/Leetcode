#ifndef SRC_ACCEPTED_00016_3SUM_CLOSEST_H
#define SRC_ACCEPTED_00016_3SUM_CLOSEST_H

#include <vector>

class Solution {
	public:
		int threeSumClosest(const std::vector<int>& nums, int target);

	private:
		int bruteforce(const std::vector<int>& nums, int target);
};

#endif  // SRC_ACCEPTED_00016_3SUM_CLOSEST_H

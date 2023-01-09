#include "02501-longest-square-streak.h"

#include <algorithm>
#include <unordered_map>

int Solution::longestSquareStreak(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());

	std::unordered_map<int64_t, int> square_count;
	int max_streak = 1; 

	for (auto itr = nums.rbegin(); itr != nums.rend(); itr++) {
		const int64_t value = *itr;
		const int64_t square = value * value;
		auto count_itr = square_count.find(square);

		int current_streak;
		if (count_itr == square_count.end()) {
			current_streak = 1;

		} else {
			current_streak = count_itr->second + 1;
			square_count.erase(count_itr);
		}
		square_count[value] = current_streak;
		max_streak = std::max(max_streak, current_streak);	
	}

	return max_streak > 1?  max_streak: -1;

}

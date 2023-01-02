#ifndef SRC_ACCEPTED_02517_CANDY_BASKET_H
#define SRC_ACCEPTED_02517_CANDY_BASKET_H

#include <vector>

// TODO(ashishmisra): Sort the input price vector. Then it becomes a dynamic
// programming problem. Divide every interval in 1/2 and select the interval
// that represents the maximum of difference.
class Solution {
	public:
		int maximumTastiness(std::vector<int>& price, int k);

	private:
		int maximumTastiness(const std::vector<int>& price, int i, int j, int k);
};

#endif  // SRC_ACCEPTED_02517_CANDY_BASKET_H

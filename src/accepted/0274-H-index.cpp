#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

class Solution {
	public:
    	int hIndex(vector<int>& citations);
};

int Solution::hIndex(vector<int>& citations) {

	sort(citations.begin(), citations.end());

	int index = 0;
	auto itr = citations.rbegin();
	
	for( ; itr != citations.rend(); itr++) {
		if (++index > *itr) {
			break;
		}
	}	

    if (itr == citations.rend()) {
        return index;
    }
    
	return index-1;
}

int main(int argc, const char **argv) {

	Solution ans;
	int arr1[] = {3, 0, 6, 1, 5};
	vector<int> vec1(arr1, arr1+5);

	int index = ans.hIndex(vec1);
	cout << index << endl;
}

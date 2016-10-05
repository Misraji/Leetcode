#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <queue>
using std::priority_queue;

#include <utility>
using std::pair;
using std::make_pair;

#include <map>
using std::map;

class CompareKeyCount {
	public:
		bool operator()(pair<int, int> &val1, pair<int,int> &val2) const {
			return (val1.second < val2.second);
		}
};


class Solution {
	public:
    	vector<int> topKFrequent(vector<int>& nums, int k);
        
};

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {

		vector<int> result;
		map<int, pair<int, int> > values_map;
		priority_queue<pair<int, int> , vector< pair<int, int> >, CompareKeyCount > values_queue;
 
		for(int i=0; i < nums.size(); i++) {
			int val = nums[i];
			values_map[val].first = val;
			values_map[val].second++;
		}

		auto values_it = values_map.begin();
		for( ; values_it != values_map.end() ; values_it++) {
			values_queue.push(values_it->second);
		}		

		for(int i=0; i < k; i++) {
			pair<int, int> curr_max = values_queue.top();
			result.push_back(curr_max.first);
			values_queue.pop();
		}

		return result;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	cout << output << endl;
}

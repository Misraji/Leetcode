#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::copy;

#include <map>
using std::map;

#include <set>
using std::set;

#include <iterator>
using std::back_inserter;
using std::ostream_iterator;

#include <utility>
using std::pair;
using std::make_pair;

class Solution {
	public:
    	vector<vector<int> > combinationSum(vector<int>& candidates, int target);

	private:
		void findCombination(vector<int>& candidates, int target, 
				map<int, set<vector<int> > > &solution_map) ;

};

void Solution::findCombination(vector<int>& candidates, int target, 
	map<int, set<vector<int> > > &solution_map) {

	//	End of recursion.
	if (solution_map.count(target) > 0) {
		return ;
	}

	solution_map.insert(make_pair(target, set<vector<int> >() ));
	set<vector<int> > &result = solution_map[target];

	for(auto itr = candidates.begin(); itr != candidates.end(); ++itr) {
	
		// 0 makes no difference to a target. Ignore it.
		// TODO: What if 0 was the target??
		if (*itr == 0) {
			continue;	
		}
	
		if (*itr < target) {
			
			int new_target = (target - *itr);
			// Recursion call with smaller target value;
			findCombination(candidates, new_target, solution_map);
			set<vector<int> > &new_solution = solution_map[new_target];
		
			// TODO: What if no solution could be found of the new_target
			// Is that correctly handled here??

			for(auto set_itr = new_solution.begin(); set_itr != new_solution.end(); set_itr++ ) {
					
				const vector<int> &new_curr_sol = *set_itr;
				vector<int> result_mem;

				result_mem.push_back(*itr);
				copy(new_curr_sol.begin(), new_curr_sol.end(), back_inserter(result_mem));

				sort(result_mem.begin(), result_mem.end());
				result.insert(result_mem);
			}	

			
		} else if (*itr == target) {
			
			vector<int> solution;
			solution.push_back(target);
			result.insert(solution) ;

		} else {
			// Rest of the elements are bigger than the target element.
			// Get out of the loop.
			break;
		}	
	}	
	
}

vector<vector<int> > Solution::combinationSum(vector<int>& candidates, int target) {

	map<int, set<vector<int> > > solution_map;
	sort(candidates.begin(), candidates.end());

	findCombination(candidates, target, solution_map);

	set<vector<int > > &result = solution_map[target];
	return vector<vector<int > >(result.begin(), result.end());
}

int main(int argc, const char **argv) {

	Solution ans;

	int arr1[] = {2, 3, 6, 7};
	vector<int> vec1(arr1, arr1+4);

	vector<vector<int> > output = ans.combinationSum(vec1, 7);

	for (int i = 0; i < output.size() ; i++) {
		vector<int> &curr = output[i];
		copy(curr.begin(), curr.end(), ostream_iterator<int>(cout, ","));
		cout << endl;
	}
}

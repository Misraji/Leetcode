#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <utility>
using std::pair;

#include <queue>
using std::queue;
using std::make_pair;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
    	vector<vector<int> > levelOrderBottom(TreeNode* root);

	private:
		void traverse(queue<pair<TreeNode *, int> > &node_queue, 
				vector<vector<int> > &result, int level);
};


void Solution::traverse(queue<pair<TreeNode *, int> > &node_queue, 
		vector<vector<int> > &result, const int level) {
	
	vector<int> values;

	if (node_queue.empty()) {
		return;
	}

	do {
		pair<TreeNode*, int> curr = node_queue.front();
		if (curr.second == level) {

			TreeNode *curr_node = curr.first;

			if (curr_node != NULL) {
				node_queue.push(make_pair(curr_node->left, (level+1)));
				node_queue.push(make_pair(curr_node->right, (level+1)));
				values.push_back(curr_node->val);
			}

			node_queue.pop();

		} else {
			break;
		}

	} while(1);

	traverse(node_queue, result, (level+1));
	result.push_back(values);
}

vector<vector<int> > Solution::levelOrderBottom(TreeNode* root) {
	
	vector<vector<int> > result;
	queue<pair<TreeNode *, int> > node_queue;

	node_queue.push(make_pair(root, 0));
	traverse(node_queue, result, 0);

	return result;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	cout << output << endl;
}

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

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
    	int kthSmallest(TreeNode* root, int k);

};

int numNodes(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}

int Solution::kthSmallest(TreeNode* root, int k) {
		
	if ((root->left == NULL) && (root->right == NULL)){
		return root->val;
	}	

	int num_left = numNodes(root->left);

	if (k == (num_left + 1)) {
		return root->val;
	}

	if (k <= num_left) {
		return this->kthSmallest(root->left, k);
	}	

	return this->kthSmallest(root->right, (k - num_left - 1));
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	cout << output << endl;
}

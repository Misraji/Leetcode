#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	/** @param head The linked list's head.
        	Note that the head is guaranteed to be not null, so it contains at least one node. */
    	Solution(ListNode* head);
        
    	/** Returns a random node's value. */
    	int getRandom();

	private:
};

Solution::Solution(ListNode* head) {

}

int Solution::getRandom() {

}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}

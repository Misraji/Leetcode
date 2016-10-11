#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

/**
 * Definition for singly-linked list.
 *
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* oddEvenList(ListNode* head);
};

ListNode* Solution::oddEvenList(ListNode* head) {
	// All argument checks.
	if (head == NULL) {
		return head;
	}

	// All variable initializations
	// Dummy head variables.
	ListNode *odd_head = new ListNode(0);
	ListNode *even_head = new ListNode(0);
	ListNode *curr_odd = odd_head, *curr_even = even_head;

	ListNode *curr = head;
	ListNode *new_head = NULL;

	int count = 1;
	while (curr) {
		
		if (count % 2) {
			// Odd numbered node.
			curr_odd->next = curr;
			curr_odd = curr;

		} else {
			// Even numbered node.
			curr_even->next = curr;
			curr_even = curr;
		}
		curr = curr->next;
		count++;
	}

	curr_odd->next = curr_even->next = NULL;

	// Note that there will always be atleast one odd node (1st node)
	curr_odd->next = even_head->next;
	new_head = odd_head->next;

	delete odd_head;
	delete even_head;

	return new_head;
}

int main(int argc, const char **argv) {

	Solution ans;
	ListNode *result = NULL;

	ListNode *one = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *three = new ListNode(3);
	
	one->next = two; two->next = three; three->next = 0;
	
	result = ans.oddEvenList(one);

	cout << "New List: ";
	while (result) {
		cout << result->val << ", " ;
		result = result->next;
	}
	cout << endl;
	
}

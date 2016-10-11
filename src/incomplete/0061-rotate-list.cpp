#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k);
};

ListNode* Solution::rotateRight(ListNode* head, int k) {

	if ((head == NULL) || (k <= 0)) {
		return head;
	}

	int length = 0;
	int shift_num = 0;
	ListNode *curr = head, *prev = NULL, *new_head = NULL, *new_head_prev = NULL;

	for ( ListNode *curr = head ; curr != NULL; curr = curr->next, ++length)
		;

	shift_num = k % length;

	if (shift_num == 0) {
		return head;
	}

	// Create a gap of shift_num nodes 
	for (int i = 0; i < shift_num; i++) {
		curr = curr->next;
	} 
	new_head = head;

	// Move curr all the way to the end of the list.
	// new_head will then point to shift_num nodes away from the end.
	while (curr) {

		new_head_prev = new_head;
		new_head = new_head->next;

		prev = curr;
		curr = curr->next;
	}

	// Dissociate first part of the list from head.
	new_head_prev->next = NULL;
	// Attach last node (prev) to the original head, thus completing the
	// rotation.
	prev->next = head;

	return new_head;	
}

int main(int argc, const char **argv) {

	Solution ans;

	ListNode *first = new ListNode(1);
	ListNode *second = new ListNode(2);
	ListNode *third = new ListNode(3);
	ListNode *curr = NULL;

	first->next = second;
	second->next = third;

	// Print original list
	curr = first;
	cout << "Original list : ";
	while(curr) {
		cout << curr->val << ", " ;
		curr = curr->next;
	}
	cout << endl;

	ListNode *result = ans.rotateRight(first, 4);

	// Print result
	curr = result;
	cout << "Rotated List : ";
	while(curr) {
		cout << curr->val << ", " ;
		curr = curr->next;
	}
	cout << endl;

	first->next = NULL;
	result = ans.rotateRight(first, 99);

	// Print result
	curr = result;
	cout << "Rotated List : ";
	while(curr) {
		cout << curr->val << ", " ;
		curr = curr->next;
	}
	cout << endl;


}

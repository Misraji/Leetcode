#ifndef SRC_ACCEPTED_02448_REMOVE_NODES_H
#define SRC_ACCEPTED_02448_REMOVE_NODES_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct ListNode {
	public:
		int val;
		ListNode* next;
		ListNode(): val(0), next(nullptr) {}
		ListNode(int x): val(x), next(nullptr) {}
		ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* reverse(ListNode* root);

ListNode* createList(const std::vector<int>& values);
std::vector<int> createVector(const ListNode* root);

class Solution {
	public:
		ListNode* removeNodes(ListNode* head);
};

#endif // SRC_ACCEPTED_02448_REMOVE_NODES_H

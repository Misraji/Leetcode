#include "02488-remove-nodes.h"

namespace {

std::string print(const ListNode* root) {
	std::ostringstream result;
	while (root) {
	    result << root->val <<", ";
		root = root->next;
	}
	return result.str();
}

}  // namespace 

ListNode* reverse(ListNode* root) {
	if (root == nullptr) {
		return root;
	}

	auto* prev = root;
	auto* current = root->next;

	while (current) {
		auto* next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	root->next = nullptr;
	return prev;
}

ListNode* createList(const std::vector<int>& values) {
	if (values.empty()) {
		return nullptr;
	}

	ListNode* current = new ListNode(values[0]);
	ListNode* head = current;

	int i = 0;
	while (++i < values.size()) {
		current->next = new ListNode(values[i]);
		current = current->next;
	}
	return head;
}

std::vector<int> createVector(const ListNode* root) {
	std::vector<int> result;
	while (root) {
		result.push_back(root->val);
		root = root->next;
	}
	return result;
}


ListNode* Solution::removeNodes(ListNode* head) {
	if (head == nullptr) {
		return head;
	}

	auto* result = reverse(head);
	auto* current = result;
	auto* next = current->next;

	while (next) {
		if (next->val <= current->val) {
			auto* tmp = next;
			current->next = next->next;
			next = current->next;
			delete tmp;

		} else {
			current = next;
			next = current->next;
		}
	}
	// Reverse current.
	return reverse(result);
}

/*
int main(int argc, const char** argv) {
	// const std::vector<int> vec = {5};
	// const std::vector<int> vec = {5, 2};
	const std::vector<int> vec = {5, 2, 13, 8};
	// const std::vector<int> vec = {1,1,1,1};
	ListNode* list = createList(vec);
	std::cout << "input = " << print(list) << std::endl;
	
	ListNode* result = Solution().removeNodes(list);
	std::cout << "result = " << print(result) << std::endl;
}
*/

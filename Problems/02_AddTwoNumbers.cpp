#include <iostream>

// Question
/*
	2. Add Two Numbers - July 24th, 2023
	You are given two non-empty linked lists representing two non-negative integers.
	The digits are stored in reverse order, and each of their nodes contains a single digit.
	Add the two numbers and return the sum as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

// Examples
/*
	Example 1:
	Input: l1 = [2,4,3], l2 = [5,6,4]
	Output: [7,0,8]
	Explanation: 342 + 465 = 807.

	Example 2:
	Input: l1 = [0], l2 = [0]
	Output: [0]

	Example 3:
	Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
	Output: [8,9,9,9,0,0,0,1]
*/

// Constraints
/*
	The number of nodes in each linked list is in the range [1, 100].
	0 <= Node.val <= 9
	It is guaranteed that the list represents a number that does not have leading zeros.
*/

namespace Question_002
{
	struct ListNode
	{
		int val;
		ListNode* next;

		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* node = new ListNode(0);
		ListNode* currNode = node;
		int carry = 0;

		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			const int x = l1 ? l1->val : 0;
			const int y = l2 ? l2->val : 0;
			const int sum = carry + x + y;
			carry = sum / 10;

			currNode->next = new ListNode(sum % 10);
			currNode = currNode->next;

			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}

		return node->next;
	}
}

//using namespace Question_002;
//// Test the code using the examples
//int main()
//{
//	// LinkedList 1
//	ListNode node3 = ListNode(3, nullptr);
//	ListNode node2 = ListNode(4, &node3);
//	ListNode node1 = ListNode(2, &node2);
//
//	// LinkedList 2
//	ListNode node6 = ListNode(4, nullptr);
//	ListNode node5 = ListNode(6, &node6);
//	ListNode node4 = ListNode(5, &node5);
//
//	// Output List
//	ListNode* node = AddTwoNumbers(&node1, &node4);
//
//	std::cout << "[";
//	while (node->next != nullptr)
//	{
//		std::cout << node->val << ",";
//		node = node->next;
//	}
//	std::cout << node->val;
//	std::cout << "]";
//}
//#include <iostream>
//#include <array>
//
//// Question
///*
//	86. Partition List - August 15th, 2023
//	Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//	You should preserve the original relative order of the nodes in each of the two partitions.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: head = [1,4,3,2,5,2], x = 3
//	Output: [1,2,2,4,3,5]
//
//	Example 2:
//	Input: head = [2,1], x = 2
//	Output: [1,2]
//*/
//
//// Constraints
///*
//	The number of nodes in the list is in the range [0, 200].
//	-100 <= Node.val <= 100
//	-200 <= x <= 200
//*/
//
//namespace Question_86
//{
//	//Definition for singly - linked list.
//	struct ListNode
//	{
//		int val;
//		ListNode* next;
//		ListNode() : val(0), next(nullptr) {}
//		ListNode(int x) : val(x), next(nullptr) {}
//		ListNode(int x, ListNode* next) : val(x), next(next) {}
//	};
//
//	void QuickPrint(ListNode* node)
//	{
//		std::cout << "[ ";
//		while (node != nullptr)
//		{
//			std::cout << node->val << ", ";
//			node = node->next;
//		}
//		std::cout << "]" << std::endl;
//	}
//
//	ListNode* Partition(ListNode* head, int x)
//	{
//		ListNode lessTail;
//		ListNode greatTail;
//		std::array<ListNode*, 2> p = { &lessTail, &greatTail };
//
//		for (; head; head = head->next) 
//		{
//			const bool cond = head->val >= x; // gives us the index of what list we should use
//			p[cond]->next = head;
//			p[cond] = p[cond]->next;
//		}
//
//		p[1]->next = nullptr;			// Set the end of the list to null
//		p[0]->next = greatTail.next;	// Conjoin the two list
//
//		return lessTail.next;
//	}
//
//}
//
//using namespace Question_86;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 1, 2, 2, 4, 3, 5
//	ListNode head1(1);
//	head1.next = new ListNode(4);
//	head1.next->next = new ListNode(3);
//	head1.next->next->next = new ListNode(2);
//	head1.next->next->next->next = new ListNode(5);
//	head1.next->next->next->next->next = new ListNode(2);
//	QuickPrint(Partition(&head1, 3));
//
//	// Example 2 = 1, 2
//	ListNode head2(2);
//	head2.next = new ListNode(1);
//	QuickPrint(Partition(&head2, 2));
//}
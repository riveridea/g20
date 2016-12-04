/*
Given a list, rotate the list to the right by k places, 
where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/


/* CPP */
#include <iostream>
#include <string>
using namespace std;

/* Definition for singly-linked list */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution 
{
	
public:
	ListNode* rotateRight(ListNode *head, int k) {

		// simple case1 & case2
		if (NULL == head || 0 == k) {
			return head;
		}		

		ListNode *first = head;
		int length = 0;

		// get the length of the list
		while (NULL != first) {
			first = first->next;
			length++;
		}

		// reset first to head
		first = head;
		ListNode *second = head;
		// get mod cal for K
		k = k % length;

		if (0 == k) {
		    return head;
		}

		while (k > 0) {
			second = second->next;
			k--;
		}

		while (NULL != second->next) {
			first = first->next;
			second = second->next;
		}

		// temp pointer for the head of new list
		ListNode *helper = first->next;
		second->next = head;
		first->next = NULL;

		return helper;
	}
};
/* 
Check whether the given Linked List length is even or odd?

Use a 2x pointer. Take a pointer which moves at 2x [2 nodes at a time]. At the end, if the length is even then pointer will be NULL otherwise it will point to last node.
*/

/* CPP */
#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int IsLinkedListLengthEven(ListNode* head)
    {
    	while (head && head->next->next)
    	{
    		head = head->next->next;
    	}

    	if (head == NULL)
    	{
    		return 1; // means it is even
    	}
    	else
    	{
    		return 0; // means it is odd
    	}
    }
}
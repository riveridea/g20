/*
Problem-32 Reverse the linked list in pairs. If you have a linked list that holds 
1->2->3->4->x, then after the function has been called, the linked list would hold
2->1->4->3->3.

Time Complexity O(n)
Space Complexity O(1)

*/

/* CPP */

#include <iostream>
#include <string>
using namespace std;

/* Definition for singly-linked list */
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:
    ListNode* ReversePairRecursive(ListNode* head)
    {
    	ListNode* temp;

    	if (head == NULL || head->next == NULL)
    	{
    		return head;
    	}
    	else
    	{
    		temp = head->next;
    		head->next = ReversePairRecursive(temp->next);
    		temp->next = head;
    		return temp;
    	}

    }

    ListNode* ReversePairIterative(ListNode* head)
    {
    	ListNode* current, temp, temp2;

    	ListNode* newHead = head->next;
    	ListNode* current = head;

    	while (current != NULL && current->next != NULL)
    	{
    		temp = current->next;
    		temp2 = temp->next;
    		temp->next = current;
    		current->next = temp2;

    		if (current != NULL)
    		{
    			current = current->next;
    		}
    	}


    	return newHead;
    }

};

int main()
{
    
}
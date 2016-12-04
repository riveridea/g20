/*
234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

Or CC150 2.7.txt

# Implement a function to check if a linked list is a palindrome.

1. Reverse the list and compare
2. push the first half in the stack then compare,
3. recursive approach.

e.g. 0->1->2->1->0
*/

/* CPP */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* Definition for singly-linked list */
struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:

    // revesing the whole list and then compare the two
    // lists one node by one node.
    bool isPalindrome1(ListNode* head)
    {

    }

    // by leveraging the std stack class
    bool isPalindrome2(ListNode* head)
    {
    	ListNode* fast = head;
    	ListNode* slow = head;

    	stack<int> stackOfNode;

    	while (fast != NULL && fast->next != NULL)
    	{
    		stackOfNode.push(fast->val);
    		slow = slow.next;
    		fast = fast.next.next;
    	}

    	// has odd number of elements, so skip the middle element
    	if (fast != NULL)
    	{
    		slow = slow->next;
    	}

    	while (slow != null) 
    	{
    		int top = stack.pop();

    		if (top != slow->val)
    		{
    			return fasle;
    		}

    		slow = slow->next;
    	}

    	return true;
    }

    bool IsPalindrome3(ListNode* head)
    {
        int length = 0;

        while (head!=NULL)
        {
            length += 1;
            head = head->next;
        }

        return IsPalindromehelper(ListNode* head, length);

    }

    bool IsPalindromehelper(ListNode* head, int length);
    {
        // base case 1
        if (head == NULL || length == 0)
        {
            return true;
        }
        // base case 2
        else if (length == 1)
        {
            return (head->next, true)
        }
        // base case 3
        else (length == 2)
        {
            return  (head->next->next, head.data == head->next.data)
        }

        // smaller problem
        result = isPalindromehelper(head->next, length - 2);

        if (result)
        {

        }
        else
        {
            res.result = head->data == res.node->data;
            res.node = res.node->next;
            return res;
        }
    }

};

int main()
{
	
}

// end of file
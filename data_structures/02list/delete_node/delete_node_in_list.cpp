/*
2.3.txt

Write a function to delete a node (except the tail) in the middle
 of a ingly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given 
the third node with value 3, the linked list should become 
1 -> 2 -> 4 after calling your function.

note: this problem cannot be solved if the node to be deleted 
is the last node in the linked list.
*/

/* CPP */

#include <iostream>
#include <string>

using namespace std;

/* Definition for singly-linked list. */

struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
       if (node == NULL || node->next == NULL)
       {
           return;
       }
       
       ListNode* nextNode = node->next;
       node->val = nextNode->val;
       node->next = nextNode->next;
       return;
    }
};

int main()
{
	// leetcode result : passed
}

// end of file
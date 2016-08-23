/*
Write a program to find the node at which the intersection of two 
singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

	// Method 1:  
	/*
    get the lengths of two lists seperatedly. on the longer list
    forward (length1 - length2), then two pointer forward at the
    the same pace, if meet, then we get intersection pointer.
	*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    }

    // Method 2: smart
    /*

    */

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        
    }
};
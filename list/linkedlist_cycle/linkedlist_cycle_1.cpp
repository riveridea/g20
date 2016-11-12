/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


/*
Similar Question: Problem -6
-- it depends where we start to check the list, a node from
the beginning or inside the cycle.

Can we use hashing technique for solving this problem? Yes

Can we use sorting technique? No
-- it works only if we can find the length of the list.
but if the list is having loop then we may end up in infinte
loop. Due to this reason the algorithm fails.

Can we solve the problem in O(n)? Yes.

*/


/* CPP */

#include <cstddef>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	// Memeory less Approach, namely Floyd cycle finding algorithm.
    bool hasCycle(ListNode *head){
    	ListNode *slow = head;
    	ListNode *fast = head;

    	while (fast != NULL && fast->next != NULL) {
    		slow = slow->next;
    		fast = fast->next->next;

    		if (fast == slow) {
    			return true;
    		}
    	}

    	return false;
    }

    // or

        bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL) {
            slow = slow->next;
            
            if (fast->next == NULL) {
                return false;
            }
                
            fast = fast->next->next;

            if (fast == slow) {
                return true;
            }
        }
        
        return false;
    }
};
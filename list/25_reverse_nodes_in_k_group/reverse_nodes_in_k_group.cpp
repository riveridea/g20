/*
Given a linked list, reverse the nodes of a linked list k at a time 
and return its modified list. If the number of nodes is not a multiple 
of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

/* C++ */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;

        int i = 0;
        while (head) {
            i++;
            if (i % k == 0) {
                pre = reverse(pre, head->next);                
                head = pre->next;
            } else {
                head = head->next;   
            }
        }

        return dummy.next;
    }

    ListNode *reverse(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;

            cur = last->next;
        }
        return last;
    }
};
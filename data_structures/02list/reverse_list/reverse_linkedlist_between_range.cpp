/*
Leetcode:
https://leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in-place 
and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

//http://bangbingsyb.blogspot.com/2014/11/leetcode-reverse-linked-list-ii.html
//http://www.jiuzhang.com/solutions/reverse-linked-list-ii/
//https://gist.github.com/superlayone/9916030#file-reverselistbetweenmandn-md
//http://yucoding.blogspot.com/2013/04/leetcode-question-85-reverse-linked.html

/**
 * Definition for singly-linked list.
 */ 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

	// tricky solution by switch the values of the related nodes only
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p=head;
        int i=1;
        while (p!=NULL){
            if (i>(m+int((n-m)/2))) {return head;}
            if (i<m) {i++;p=p->next;}
            else{
                ListNode* q = p;
                for (int j=0;j<(n-m-(i-m)*2);j++){
                    q=q->next;
                }
                int tmp = p->val;
                p->val = q->val;
                q->val=tmp;
                i++;
                p=p->next;
            }
        }
        return head;  
    }

    // actually reverse the nodes
  
        ListNode* reverseBetween(ListNode* head, int m, int n) {
        // simple cases
        if (m < 1 || m >= n || head == NULL) {
            return head;
        }  
        
        // create a dummy head, in case the first
        // node need to be switched
        ListNode* dummy = new ListNode(0);
        // redirect the head to the dummy node
        dummy->next = head;
        head = dummy;
        
        // move head to the (m-1) the node
        for (int i = 0; i < m-1; i++) {
            
            // in case, the list is not long enough
            if (head == NULL) {
                return NULL;
            }
            
            head = head->next;
        }
        
        ListNode* mNode = head->next;
        ListNode* cur = head->next->next;
        
        for (int i = 0; i < n-m; i++) {
            ListNode* tmp = cur->next;
            cur->next = mNode;
            mNode = cur;
            cur = tmp;
        }
        
        head->next->next = cur;
        head->next = mNode;// now mNode is nNode
        head = dummy->next;
        
        delete dummy; // need to destroy after new() is called
        return head;
    }
};
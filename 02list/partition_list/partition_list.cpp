/*
Partition List:
https://leetcode.com/problems/partition-list/

Given a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each
of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

CC150 2.4
*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {

/*
由于不要求sort，只要求partition。可以建立一个新的list l2。遍历原list l1的每个节点p。
p->val < x，保留。p->val >= x，从l1中移出并插入l2。由于要删除节点需要使用被删节点的
前节点。所以实际写的时候考察的是p->next->val和x的比较。

总结： 
这类头节点经常要插入、删除的题目，第一反应就是试试使用dummy头节点来简化代码。

*/
public:
    // main method
    ListNode *partition(ListNode *head, int x) {
        // basic case 1
        if (head == NULL) {
            return NULL;
        }

        // basic case 2
        if (head->next == NULL) {
            return head;
        }

        ListNode *h1 = new ListNode(0);
        ListNode *h2 = new ListNode(0);
        ListNode *t2 = h2;
        h1->next = head;
        head = h1;
        
        while(head->next) {
            if(head->next->val<x)   // skip node
                head = head->next;
            else {  // remove node from h1 and insert to the tail of h2
                t2->next = head->next;
                head->next = head->next->next;
                t2 = t2->next;
                t2->next = NULL;
            }
        }
        
        // bind two lists together
        head->next = h2->next;
        head = h1->next;
        delete h1;
        delete h2;
        return head;
    }
};


////////

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p= new ListNode(0);
        p->next = head;
        head = p; // used to save the result head.
        ListNode *last=head; // used to get the last node
         
        if (head==NULL){return NULL;}
        if (head->next==NULL){return head->next;}
         
        int n=0; //length of the list
        while (last->next!=NULL){ last=last->next; n++; } //get the length and last node
         
        while (n>0){  // in case  of non-stop loop, count n.
            if (p->next->val < x){  // val<x keep the node
                p=p->next;
                n--;
            }else{                  // val>=x move to last
                last->next = new ListNode(p->next->val);    // add node to the last
                last = last->next;
                p->next = p->next->next;                    //delete current node
                n--;
            }
        }
        return head->next;  //the 1st node is elmininated 
    }
};

class Solution {
public:

    // Leetcode result: passed, but not fast enough!
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* beforeStart = NULL;
        ListNode* beforeEnd = NULL;
        ListNode* afterStart = NULL;
        ListNode* afterEnd = NULL;
        
        ListNode* node = head;
        
        while (node != NULL)
        {
            ListNode* tmp = node->next;
            node->next = NULL;
            
            if (node->val < x)
            {
                if (beforeStart == NULL)
                {
                    beforeStart = node;
                    beforeEnd = beforeStart;
                }
                else
                {
                    beforeEnd->next = node;
                    beforeEnd = node;
                }
            }
            else
            {
                if (afterStart == NULL)
                {
                    afterStart = node;
                    afterEnd = afterStart;
                }
                else
                {
                    afterEnd->next = node;
                    afterEnd = node;
                }
            }
            
            node = tmp;
        }
        
        if (beforeStart == NULL)
        {
            return afterStart;
        }
        
        beforeEnd->next = afterStart;
        return beforeStart;
    }
};

// end of file
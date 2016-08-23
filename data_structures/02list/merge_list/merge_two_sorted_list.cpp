/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes 
of the first two lists.

合并两个非降序链表的并集。
1->2->3 和 2->3->5 为
1->2->3->5. 只能输出结果，
不能修改两个链表的数据

Time Complexity O(m+n)
*/



/* CPP */

#include <iostream>
#include <string>
using namespace std;


// Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    ListNode* mergeTwoLists(ListNode  *l1, listNode *l2) {
       if (l1 == NULL) {
            return l2;
        }

        if (l2 == NULL) {
            return l1;
        }

        ListNode *mergedListHead = NULL;

        if (l1->val < l2->val) {
            mergedListHead = l1;
            mergedListHead->next = mergeTwoLists(l1->next, l2);
        } else if (l1->val >= l2->val) {
            mergedListHead = l2;
            mergedListHead->next = mergeTwoLists(l1, l2->next);
        }

        return mergedListHead;        
    }
};
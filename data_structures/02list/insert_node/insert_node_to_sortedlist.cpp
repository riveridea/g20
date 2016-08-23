/*
Problem 15:
Insert a node in a sorted linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* InsertNode2SortedList(ListNode *head, int x) {

    	ListNode* current = head;
    	ListNode* tmp = NULL;

    	if (head == NULL) {
    		return NULL;
    	}

    	// traverse the list, find the first node bigger than x
    	while (current != NULL && current->val < x) {
    		temp = current; // keep the previous node info
    		current = current->next;
    	}

    	// insert the new node before the big node
    	ListNode* newnode = ListNode(x);
    	newnode->next = current;
    	temp->next = newnode;

    	return head;
    }
};
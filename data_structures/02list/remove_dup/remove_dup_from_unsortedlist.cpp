/*
2.1.txt
Write code to remove duplicates from an unsorted linked list.
  
Follow Up
How would you solve this problem if a temporay buffer is not allowed.

Basic Idea:
  If we don't have a buffer, we can iterate with two pointers: current
  which iterates through the linked list, and runner which checks all
  subsequent nodes for duplicates.

e.g. 
  Given: 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21,
  Output: 12 -> 11 -> 21 -> 41 -> 43

*/ 


 /* CPP */
#include <cstddef>
#include <unordered_map>

/* Definition for singly-linked list. */

// leetcode result : passed
// with two pointers, runs in O(1) space, O(n^2) time
// without buffer

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

    	if (NULL == head) {
    	    return NULL;
    	}

    	ListNode* previous = head;
    	ListNode* current = previous->next;

    	while (NULL != current) {
    	    ListNode* runner = head;

    	    while (runner != current) {
    	        if (runner->val == current->val) {
    	            ListNode* tmp = current->next;
    	            previous->next = tmp;
    	            current = tmp;
    	            break;
    	        }

    	        runner = runner->next;
            
            }
    	     
    	    if (runner == current) {  	    
    	        previous = current;
    	        current = current->next;
    	    }
    	}

    	return head;        
    }

    // used buffers
    // looks like passed in leetcode
    ListNode *deleteDuplicates(ListNode *head) {
        unordered_map<int, bool> hashtable;

        ListNode *previous = NULL;
        ListNode *node = head;

        while (node != NULL) {
            if (hashtable.find(node->val) != hashtable.end()) {
                previous->next = node->next;
            } else {
                hashtable.insert(make_pair(node->val, true));
                previous = node;
            }

            node = node->next;
        }

        return head;
    }
};
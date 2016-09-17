/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


/* CPP */

/* Definition for singly-linked list with a random pointer. */
#include <cstddef>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode* CopyRandomList(RandomListNode *head) {

    	if (head == NULL) {
    		return NULL;
    	}

    	// 1. clone all nodes

    	RandomListNode *onProcess = head;
    	RandomListNode *tmp = NULL;

    	while (onProcess != NULL) {
    		tmp = onProcess->next;
    		RandomListNode *node = new RandomListNode(onProcess->label);
    		node->next = tmp;
    		onProcess->next = node;
    		onProcess = tmp;
    	}

    	// 2. reset onProcess to head, and duplicate sibling info

    	while (onProcess != NULL) {
    		if (onProcess->random != NULL) {
    			onProcess->next->random = onProcess->random->next;
    			onProcess = onProcess->next->next;
    		}
    	}

    	// 3. reset onProcess to head and divide the list to two lists

        RandomListNode *retHead = NULL;  
        RandomListNode *tRet = NULL;  
          
        tHead = head;  
        RandomListNode *next2 = NULL;  
        while(tHead)  
        {  
            if(retHead == NULL)  
            {    
                next2 = tHead->next->next;  
                retHead = tHead->next;  
                tRet = retHead;  
                tHead->next = next2;  
                tHead = next2;  
            }  
            else  
            {  
                next2 = tHead->next->next;  
                tRet->next = tHead->next;  
                tHead->next = next2;  
                tHead = next2;  
                tRet = tRet->next;  
            }  
  
        }  
        return retHead;  

    }
};
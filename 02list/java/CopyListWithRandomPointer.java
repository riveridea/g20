/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


/* 
CPP Solution
tested by leetcode
*/

/* Definition for singly-linked list with a random pointer. */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:  
    RandomListNode *copyRandomList(RandomListNode *head) {  
        RandomListNode *tHead = head;  
        RandomListNode *next = NULL;  
        while(tHead)  
        {  
            next = tHead->next;  
            RandomListNode *node = new RandomListNode(tHead->label);  
            node->next = tHead->next;  
            //node->random = tHead->random;  
            tHead->next = node;  
            tHead= next;  
        }  
        tHead = head;  
        while(tHead)  
        {  
            if(tHead->random) tHead->next->random = tHead->random->next;  
            tHead = tHead->next->next;  
        }  


        
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



right answer

/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return null;
        }

        RandomListNode node = head;
        RandomListNode temp = null;

        //insert new node
        while (node != null) {
            temp = node.next;

            RandomListNode newNode = new RandomListNode(node.label);
            node.next = newNode;
            newNode.next = temp;

            node = temp;
        }

        //update new node's random
        node = head;
        while (node != null) {
            if (node.random != null) {
                node.next.random = node.random.next;
            }

            node = node.next.next;
        }

        // seperate two linked lists
        RandomListNode newHead = head.next;

        node = head;
        RandomListNode newNode = node.next;
        while (node != null) {
            node.next = newNode.next;
            if (newNode.next != null) {
                newNode.next = newNode.next.next; // node.next.next
            }

            node = node.next;
            if (node != null) {
                newNode = node.next;
            }
        }

        return newHead;
    }
}



/* C*/

/*

copy a complex linked list

*/

struct ComplexNode {
	int value;
	ComplexNode *next;
	ComplexNode *sibling;
};

//clone all nodes
void cloneNodes(ComplexNode *pHead)
{
	complexNode *pNode = pHead;

	while(pNode != NULL) {
		ComplexNode *pCloned = malloc();
		pCloned->value = pNode->value;
		pCloned->next = pNode->next;
		pCloned->sibling = NULL;
		pNode->next = pCloned;
		pNode = pCloned->next;
	}
}

//replicate sibling info

void connectSiblings(complexNode *pHead)
{
	ComplexNode *pNode = pHead;

	while (pNode != NULL) {
		complexNode *pCloned = pNode->next;

		if (pNode->sibling != NULL) {
			pCloned->sibling = pNode->sibling->next;
		}

		pNode = pCloned->next;
	}
}

// divide this linked list

ComplexNode *disconnectNodes(ComplexNode *pHead)
{
	ComplexNode *pNode = pHead;
	ComplexNode *pClonedHead = NULL;
	ComplexNode *pCloned = NULL;

	if (pNode != NULL) {
		pClonedHead = pCloned =pNode->next;
		pNode->next = pCloned->next;
		pNode = pNode->next;
	}

	while (pNode != NULL) {
		pCloned->next = pNode->next;
		pCloned = pCloned->next;
		pNode->next = pCloned->next;
		pNode = pNode->next;
	}

	return pClonedHead;
}
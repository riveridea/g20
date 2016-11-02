/*
A linked list is given such that each node 
contains an additional random pointer which could 
point to any node in the list or null.

Return a deep copy of the list.
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
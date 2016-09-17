/*
2.5 You have two numbers represented by a linked list,
where each node contains a single digit. The digits
are stored in reverse order, such that the 1's digit is
at the head of the list. Write a function that adds the 
two numbers and returns the sum as a linked list.

E.g. inpu : (3->1->5) + (5->9->2)
output: (8->0->8)

513 + 295 = 808
*/

// wrong answer?

struct ListNode {
	int val;
	ListNode *next;
	ListNode (int x): val(x), next(NULL) {}
};

class Solution {
public:

	// iteratively, passed by leetcode
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* res = new ListNode(0);
		ListNode* head = res;

		while (l1 && l2) {
			res->next = new ListNode((l1->val + l2->val + carry)%10);
			carry = (l1->val + l2->val + carry)/10;
			l1 = l1->next;
			l2 = l2->next;

			res = res->next;
		}

		while (l1) {
			res->next = new ListNode((l1->val + carry) % 10);
			carry = (l1->val + carry) / 10;
			l1 = l1->next;
			res = res->next;
		}

		while (l2) {
			res->next = new ListNode((l2->val + carry) % 10);
			carry = (l2->val + carry) / 10;
			l2 = l2->next;
			res = res->next;
		}

		if (carry > 0) {
			res->next = new ListNode(carry);
		}

		return head->next;
	}


	// recursively method, passed by leetcode
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       return addTwoNumbersHelper(l1, l2, 0);
	}
	
	ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carry) {
	    // termination condition
	    if (l1 == NULL && l2 == NULL && carry == 0) {
	        return NULL;
	    }
	    
	    ListNode* result = new ListNode(0);
	    
	    if (l1 != NULL) {
	        carry += l1->val;
	    }
	    
	    if (l2 != NULL) {
	        carry += l2->val;
	    }
	    
	    result->val = carry % 10;
	    
	    if (l1 != NULL || l2 != NULL) {
	        ListNode* restListHeader = addTwoNumbersHelper(l1 == NULL ? NULL : l1->next,
	                                                  l2 == NULL ? NULL : l2->next,
	                                                  carry >= 10 ? 1 : 0);
	        result->next = restListHeader;
	    }
	    
	    return result;
	}
};

/*
2.5 You have two numbers represented by a linked list,
where each node contains a single digit. The digits
are stored in "forword" order, such that the 1's digit is
at the head of the list. Write a function that adds the 
two numbers and returns the sum as a linked list.

E.g. inpu : (5->1->3) + (2->9->5)
output: (8->0->8)

513 + 295 = 808

CC150 2.5 question 2. 
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode (int x): val(x), next(NULL) {}
};

class Solution {
public:

	// iteratively, passed by leetcode
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	}


	// recursively method, passed by leetcode
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 
	}
	
};

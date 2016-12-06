/* CPP */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* Definition for singly-linked list */
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void printListFromEnd(ListNode* head)
    {
    	if (head == NULL)
    	{
    		return;
    	}

    	printListFromEnd(head->next);

    	printf("%d", head->val);
    }

    // using stack
    void PrintListFromEnd(ListNode* head) {
        stack<int> stack;

        ListNode* current = head;
        
        while (current != NULL) {
            stack.push(current->val);
            current = current->next;
        }

        while (stack.empty() != NULL) {
            cout << stack.pop() << endl;
        }

        return;
    }
};
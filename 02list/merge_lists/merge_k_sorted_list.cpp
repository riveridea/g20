/*
23. Merge k Sorted Lists
https://leetcode.com/problems/Merge-k-Sorted-Lists/

Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }
};


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
          // Start typing your Java solution below
         // DO NOT write main() function
         ListNode head = null;
         int len = lists.size();
         if(len == 0)
             return null;
         else if(len == 1){
             return lists.get(0);
         }
         head = merge2List(lists.get(0), lists.get(1));
         for(int i = 2; i < len; i++){
             head = merge2List(lists.get(i), head);
         }
         return head;
         
     }
     
     public ListNode merge2List(ListNode node1, ListNode node2){
         ListNode head = new ListNode(Integer.MIN_VALUE);
         ListNode tmp = head;
         while(node1 != null && node2 != null){
             if(node1.val <= node2.val){
                 ListNode node = new ListNode(node1.val);
                 tmp.next = node;
                 tmp = tmp.next;
                 node1 = node1.next;
             } else {
                 ListNode node = new ListNode(node2.val);
                 tmp.next = node;
                 tmp = tmp.next;
                 node2 = node2.next;
             }
         }
         
         if(node1 != null){
             tmp.next = node1;
         }
         
         if(node2 != null){
             tmp.next = node2;
         }
         head = head.next;
         return head;
         
     }
}
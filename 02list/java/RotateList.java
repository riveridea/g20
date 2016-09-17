/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/


//It's somehow like finding the Nth to last Node. Once you find it, change some pointers and Bim Bam Boom: list ends up rotated. I'd say it's a linear time solution.


###
may be it is good to calculate the length of the list first.


/* Java */
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
    public ListNode rotateRight(ListNode head, int n) {
       if(head==null) 
            return null;
            
       ListNode n1 = head,n2=head;
       int length = 0;
       
       while (n1 != null) {
           length++;
           n1 = n1.next;
       }
       
        n1 = head;
        n = n%length;
        
        while(n>0){
            n2=n2.next;
            n--;
        }
        
        if (n1 == n2) {
            return n1;
        }
        
        while(n2.next!=null){
            n1=n1.next;
            n2=n2.next;
        }
        
        ListNode temp = n1.next;
        n2.next=head;
        n1.next=null;
        return temp;        
    }
}


####

public ListNode rotateRight(ListNode head, int n) {

        if(head==null) 
            return null;

        ListNode n1 = head,n2=head;

        while(n>0){
            n2=n2.next;
            n--;
            
            if(n2==null){
                n2=head;
            }
        }
        
        if(n1==n2) 
            return n1;
        
        while(n2.next!=null){
            n1=n1.next;
            n2=n2.next;
        }
        
        ListNode temp = n1.next;
        n2.next=head;
        n1.next=null;
        return temp;
    }
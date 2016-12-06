"""
206. Reverse a singly linked list.
https://leetcode.com/problems/reverse-linked-list/

A linked list can be reversed either iteratively or recursively. 
Could you implement both?

https://leetcode.com/problems/reverse-linked-list/
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        current = None

        while head != None:
        	temp = head.next
        	head.next = current
        	current = head
        	head = temp

        return current

if __init__ == '__main__'
    reverseList()
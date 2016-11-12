# https://leetcode.com/problems/reorder-list/
# Given a singly linked list L: L0→L1→…→Ln-1→Ln,
# reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

# You must do this in-place without altering the 
# nodes' values.

# For example,
# Given {1,2,3,4}, reorder it to {1,4,2,3}.

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def test():
    	mylist = ['a', 'b', 'c', 'd', 'e']
    	myorder=[3, 2, 0, 1, 4]
    	mylist = [mylist[i] for i in myorder]
    	print mylist

    def test1():
    	listinput = ['a', 'b', 'c', 'd' ,'e']
    	listoutput = ['d', 'c', 'a', 'b', 'e']

    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """

        if not head:
        	return

        # split the list with fast and slow pointers
        fast = head
        slow = head

        while fast and fast.next:
        	slow = slow.next
        	fast = fast.next.next

        head1 = head
        head2 = slow.next
        slow.next = None

        # reverse the second-half list
        cur = head2
        pre = None

        while cur:
        	nex = cur.next
        	cur.next = pre
        	pre = cur
        	cur = next

        # merge the two lists node by node
        cur1 = head1
        cur2 = pre

        while cur2:
        	next1 = cur1.next
        	next2 = cur2.next

        	cur1.next = cur2
        	cur2.next = next1

        	cur1 = next1
        	cur2 = next2

    def reorderList2(self, head):
    	        # write your code here
        if None == head or None == head.next:
            return head

        pfast = head
        pslow = head
        
        while pfast.next and pfast.next.next:
            pfast = pfast.next.next
            pslow = pslow.next
        pfast = pslow.next
        pslow.next = None
        
        pnext = pfast.next
        pfast.next = None
        while pnext:
            q = pnext.next
            pnext.next = pfast
            pfast = pnext
            pnext = q

        tail = head
        while pfast:
            pnext = pfast.next
            pfast.next = tail.next
            tail.next = pfast
            tail = tail.next.next
            pfast = pnext
        return head


     def reorderList3(self, head):
     	        if head==None or head.next==None or head.next.next==None: return head
        
        # break linked list into two equal length
        slow = fast = head                              #快慢指针技巧
        while fast and fast.next:                       #需要熟练掌握
            slow = slow.next                            #链表操作中常用
            fast = fast.next.next
        head1 = head
        head2 = slow.next
        slow.next = None

        # reverse linked list head2
        dummy=ListNode(0); dummy.next=head2             #翻转前加一个头结点
        p=head2.next; head2.next=None                   #将p指向的节点一个一个插入到dummy后面
        while p:                                        #就完成了链表的翻转
            tmp=p; p=p.next                             #运行时注意去掉中文注释
            tmp.next=dummy.next
            dummy.next=tmp
        head2=dummy.next

        # merge two linked list head1 and head2
        p1 = head1; p2 = head2
        while p2:
            tmp1 = p1.next; tmp2 = p2.next
            p1.next = p2; p2.next = tmp1
            p1 = tmp1; p2 = tmp2

if __name__ == "__main__":
	None
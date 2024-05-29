/*给你两个单链表的头节点 headA 和 headB ，
请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 //龟兔赛跑的思想
 struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
     struct ListNode* p = headA;
     struct ListNode* q = headB;
     while (p != q) {
         p = p != NULL ? p->next : headB;
         q = q != NULL ? q->next : headA;
     }
     return p;
 }
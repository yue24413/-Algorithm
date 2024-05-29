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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        int numA=0,numB=0,num=0;
        struct ListNode *cur1=headA,*cur2=headB;
        while(cur1||cur2)
        {
            if(cur1)
            {
            numA++;
            cur1=cur1->next;
            }
           else
           {
            numB++;
            cur2=cur2->next;
           }
        }
        num=abs(numA-numB);
        cur1=numA>numB?headA:headB;
        cur2=numA>numB?headB:headA;
        while(num--)
        cur1=cur1->next;
         while((cur1!=cur2)&&(cur1!=NULL)&&(cur2!=NULL))
         {
            cur1=cur1->next;
            cur2=cur2->next;
         }
        return cur1==cur2?cur1:0;
}
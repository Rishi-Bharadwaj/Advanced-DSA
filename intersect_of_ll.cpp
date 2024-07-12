//Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;ListNode*temp2=headB;
        int sizea=0,sizeb=0;
        while(temp1!=nullptr)
        {
            sizea++;
            temp1=temp1->next;
        }
        while(temp2!=nullptr)
        {
            sizeb++;
            temp2=temp2->next;
        }
        
        vector<ListNode*> a (sizea,nullptr);
        vector<ListNode*> b(sizeb,nullptr);
        temp1=headA;
        temp2=headB;
        int i,j=0;
        while(temp1!=nullptr)
        {
            a[i++]=temp1;
            temp1=temp1->next;
        }
        while(temp2!=nullptr)
        {
            b[j++]=temp2;
            temp2=temp2->next;
        }
        i=sizea-1,j=sizeb-1;
        temp1=nullptr;

        while(i>=0 && j>=0 && a[i]==b[j])
        {
            temp1=a[i];
            i--;j--;
        }
        return temp1;
    }
};
//Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

//The first node is considered odd, and the second node is even, and so on.

//Note that the relative order inside both the even and odd groups should remain as it was in the input.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode * temp=head;
        if(head==nullptr)
        return head;
        if(temp->next==nullptr)
        return head;
        
        ListNode* even=temp->next;
        ListNode* temp2=temp->next;
        int count=0;
        while(temp2!=nullptr)
        {
            count++;
            ListNode* fut=temp2->next;

            if(fut==nullptr)
            {
                if(count%2==0)
                {
                    temp->next=fut;
                    temp=temp2;
                    temp2=fut;
                    temp->next=even;
                }
                else 
                {
                    temp->next=even;
                    break;
                }
            }
            else
            {
                    temp->next=fut;
                    temp=temp2;
                    temp2=fut;
            }
        }
        return head;
    }
};
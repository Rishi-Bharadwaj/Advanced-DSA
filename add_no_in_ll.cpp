// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


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

    int get_len(ListNode* head)
        {
            ListNode* temp=head;
            int count=0;
            while(temp!=nullptr)
            {
                count++;
                temp=temp->next;
            }
            return count;
        }

    int add(ListNode* node1, ListNode* node2)
    {
        int c=0,sum=0;
        if(node1==nullptr || node2==nullptr)
        {
           return 0;
        }
        else
        {
            int sum=node1->val+node2->val +add(node1->next,node2->next);
            c=sum/10;
            node1->val=sum%10;
            cout<<"val: "<<node1->val;
        }
        return c;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=get_len(l1);
        int len2=get_len(l2);
        if(len2>len1)
        {
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }
        int dif=len1>len2?len1-len2:len2-len1;

        for(int i=0;i<dif;i++)
        {
           ListNode* nnode=new ListNode(0,l2);
           cout<<"l2"<<l2->val;
           l2=nnode;
        }
        cout<<"len1: "<<get_len(l1);
        cout<<"len2: "<<get_len(l2);
        int fin_carry=add(l1,l2);
        if(fin_carry==0)
        {
            return l1;
        }
        else
        {
            ListNode* newnode= new ListNode(1,l1);
            return newnode;
        }
    }
};
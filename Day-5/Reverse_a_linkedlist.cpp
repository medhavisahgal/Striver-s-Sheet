#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *temp=head;
        ListNode *prev=NULL;
        ListNode *temp2=NULL;
        while(temp!=NULL)
        {
            temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        head=prev;
        return head;
    }
};

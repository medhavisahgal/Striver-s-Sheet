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
    ListNode* middleNode(ListNode* head)
    {
        ListNode *temp=head;
        int num=0;
        while(temp!=NULL)
        {
            num++;
            temp=temp->next;
        }
        int mid=ceil(num/2);
        temp=head;
        while(mid--)
        {
            temp=temp->next;
        }
        return temp;
    }
};

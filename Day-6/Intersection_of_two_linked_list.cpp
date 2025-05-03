#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len1 = 0, len2 = 0;
        ListNode *temp = headA;
        ListNode *temp1 = headB;
        while (temp || temp1)
        {
            if (temp)
            {
                len1++;
                temp = temp->next;
            }
            if (temp1)
            {
                len2++;
                temp1 = temp1->next;
            }
        }
        int dif = abs(len1 - len2);
        ListNode *temp2 = headA;
        ListNode *temp3 = headB;
        if (len1 > len2)
        {
            for (int i = 0; i < dif; i++)
            {
                temp2 = temp2->next;
            }
        }
        else if (len2 > len1)
        {
            for (int i = 0; i < dif; i++)
            {
                temp3 = temp3->next;
            }
        }
        while (temp2 && temp3)
        {
            if (temp2 == temp3)
            {
                return temp2;
            }
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
        return NULL;
    }
};
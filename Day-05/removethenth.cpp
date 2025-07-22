#include <iostream>
using namespace std;
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // ListNode *temp = head;
        // int len = 0;
        // while (temp)
        // {
        //     len++;
        //     temp = temp->next;
        // }
        // if (len == 1)
        // {
        //     delete head;
        //     head = nullptr;
        //     return head;
        // }
        // if (len == n)
        // {
        //     ListNode *del2 = head;
        //     head = head->next;
        //     delete del2;
        //     return head;
        // }
        // int del = len - n;
        // int cnt = 0;
        // ListNode *temp2 = head;
        // while (cnt < del - 1)
        // {
        //     temp2 = temp2->next;
        //     cnt++;
        // }
        // ListNode *del1 = temp2->next;
        // temp2->next = temp2->next->next;
        // delete del1;
        // return head;
        // Time complexity: O(n)
        // Space complexity: O(1)
        // Better approach is to use 2 pointers
        // 1st pointer will point to the head and 2nd pointer will point to the head + n
        // then we will move both the pointers until the 2nd pointer reaches the end of the list
        // then we will delete the node which is pointed by the 1st pointer
        ListNode *temp = head;
        ListNode *temp2 = head;
        for (int i = 0; i < n; i++)
        {
            temp2 = temp2->next;
        }
        if (temp2 == nullptr)
        {
            return head->next;
        }
        while (temp2->next)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        ListNode *del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
        // Time complexity: O(n)
        // Space complexity: O(1)
    }
};
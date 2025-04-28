#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
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
    ListNode *middleNode(ListNode *head)
    {
        // ListNode *temp=head;
        // int num=0;
        // while(temp!=NULL)
        // {
        //     num++;
        //     temp=temp->next;
        // }
        // int mid=ceil(num/2);
        // temp=head;
        // while(mid--)
        // {
        //     temp=temp->next;
        // }
        // return temp;
        // The above code is a brute force approach to find the middle node of a linked list.
        // It first counts the number of nodes in the linked list, then calculates the middle index, and finally traverses the linked list again to reach the middle node.
        // This approach has a time complexity of O(n) and a space complexity of O(1).
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        // The slow pointer will be at the middle of the linked list when the fast pointer reaches the end.
        // If the linked list has an even number of nodes, the slow pointer will be at the second middle node.
        // If the linked list has an odd number of nodes, the slow pointer will be at the middle node.
        // This is because the fast pointer moves twice as fast as the slow pointer.
        // time complexity is O(n) and space complexity is O(1).
    }
};

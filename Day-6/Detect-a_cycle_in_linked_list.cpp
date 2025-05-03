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
    bool hasCycle(ListNode *head)
    {
        // unordered_set<ListNode *> s;
        // ListNode *temp = head;
        // while (temp)
        // {
        //     if (s.find(temp) != s.end())
        //     {
        //         return true;
        //     }
        //     s.insert(temp);
        //     temp = temp->next;
        // }
        // return false;
        //* Using Floyd's Cycle Detection Algorithm (Tortoise and Hare) */also known as the fast and slow pointer approach.
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
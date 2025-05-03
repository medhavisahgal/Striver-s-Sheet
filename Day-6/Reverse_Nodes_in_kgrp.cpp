#include <bits/stdc++.h>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // ListNode *temp = head;
        // int len = 0;
        // while (temp)
        // {
        //     len++;
        //     temp = temp->next;
        // }
        // int n = len / k;
        // ListNode *temp2 = head;
        // ListNode *head2 = nullptr;
        // ListNode *tail = nullptr;
        // int cnt = 0;
        // while (temp2 && cnt < n)
        // {
        //     vector<int> v;
        //     for (int i = 0; i < k; i++)
        //     {
        //         v.push_back(temp2->val);
        //         temp2 = temp2->next;
        //     }
        //     reverse(v.begin(), v.end());
        //     for (int i = 0; i < k; i++)
        //     {
        //         ListNode *newnode = new ListNode(v[i]);
        //         if (head2 == nullptr)
        //         {
        //             head2 = newnode;
        //             tail = newnode;
        //         }
        //         else
        //         {
        //             tail->next = newnode;
        //             tail = newnode;
        //         }
        //     }
        //     cnt++;
        // }
        // while (temp2)
        // {
        //     ListNode *newnode = new ListNode(temp2->val);
        //     tail->next = newnode;
        //     tail = newnode;
        //     temp2 = temp2->next;
        // }
        // return head2;
        // Time complexity: O(n), where n is the number of nodes in the linked list.
        // The space complexity is O(n) because we are using a vector to store the values of the nodes in each k-group before reversing them.
        // But the space complexity can be reduced to O(1) by reversing the nodes in place without using a vector.
        // This can be done by using a stack or by reversing the nodes in place using pointers.
        // The time complexity will still be O(n) in that case, but the space complexity will be O(1).
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy;
        ListNode *after = head;
        ListNode *curr = nullptr;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (true)
        {
            ListNode *groupStart = after;
            for (int i = 0; i < k; i++)
            {
                if (groupStart == nullptr)
                    return dummy->next;
                groupStart = groupStart->next;
            }
            curr = after;
            prev = prevGroupEnd;
            for (int i = 0; i < k; i++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            after->next = curr;
            prevGroupEnd->next = prev;
            prevGroupEnd = after;
            after = curr;
        }
        return dummy->next;
    }
};
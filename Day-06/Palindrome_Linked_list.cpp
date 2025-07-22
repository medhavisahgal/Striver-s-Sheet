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
    ListNode *left;

public:
    bool isPalindrome(ListNode *head)
    {
        // vector<int> v;
        // ListNode *temp = head;
        // while (temp)
        // {
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int start = 0;
        // int end = v.size() - 1;
        // while (start <= end)
        // {
        //     if (v[start] != v[end])
        //     {
        //         return false;
        //     }
        //     start++;
        //     end--;
        // }
        // return true;
        // Time complexity: O(n)
        // Space complexity: O(n)
        // Not a good approach but works fine.
        // We can do it in O(1) space complexity by using two pointers and reversing the second half of the linked list.
        // We can also use a stack to store the first half of the linked list and then compare it with the second half.
        // This will also take O(n) time and O(n) space.
        // stack<int> s;
        // ListNode *temp = head;
        // while(temp){
        //     s.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp){
        //     if(s.top()!=temp->val){
        //         return false;
        //     }
        //     s.pop();
        //     temp=temp->next;
        // }
        // return true;
        // Time complexity: O(n)
        // Space complexity: O(n)
        // it has recursive approach also but it is not good for large linked lists as it will take O(n) space for recursion stack.
        // Recursion will take O(n) space and O(n) time.
        //     left = head;
        //     return check(head);
        // }
        // bool check(ListNode *right)
        // {
        //     if (right == nullptr)
        //     {
        //         return true;
        //     }
        //     bool res = check(right->next);
        //     if (!res || right->val != left->val)
        //     {
        //         return false;
        //     }
        //     left = left->next;
        //     return true;

        // Better approach is to use two pointers and reverse the second half of the linked list.
        // This will take O(n) time and O(1) space.
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        ListNode *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *temp = head;
        ListNode *temp2 = prev;
        while (temp)
        {
            if (temp->val != temp2->val)
            {
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
        // Time complexity: O(n)
        // Space complexity: O(1)
    }
};
#include <iostream>
#include <vector>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // vector<int> v;
        // v.push_back(0);
        // ListNode *temp1 = l1;
        // ListNode *temp2 = l2;
        // while (temp1 && temp2)
        // {
        //     int sum = temp1->val + temp2->val + v.back();
        //     if (sum >= 10)
        //     {
        //         v.push_back(1);
        //     }
        //     else
        //     {
        //         v.push_back(0);
        //     }
        //     temp1 = temp1->next;
        //     temp2 = temp2->next;
        // }
        // while (temp1)
        // {
        //     int sum = temp1->val + v.back();
        //     if (sum >= 10)
        //     {
        //         v.push_back(1);
        //     }
        //     else
        //     {
        //         v.push_back(0);
        //     }
        //     temp1 = temp1->next;
        // }
        // while (temp2)
        // {
        //     int sum = temp2->val + v.back();
        //     if (sum >= 10)
        //     {
        //         v.push_back(1);
        //     }
        //     else
        //     {
        //         v.push_back(0);
        //     }
        //     temp2 = temp2->next;
        // }
        // int i = 0;
        // temp1 = l1;
        // temp2 = l2;
        // ListNode *prev = nullptr;
        // while (temp1 && temp2)
        // {
        //     int sum = temp1->val + temp2->val + v[i];
        //     temp2->val = sum % 10;
        //     prev = temp2;
        //     temp1 = temp1->next;
        //     temp2 = temp2->next;
        //     i++;
        // }

        // while (temp1)
        // {
        //     int sum = temp1->val + v[i];
        //     ListNode *newnode = new ListNode(sum % 10);
        //     prev->next = newnode;
        //     prev = newnode;
        //     temp1 = temp1->next;
        //     i++;
        // }

        // while (temp2)
        // {
        //     int sum = temp2->val + v[i];
        //     temp2->val = sum % 10;
        //     prev = temp2;
        //     temp2 = temp2->next;
        //     i++;
        // }
        // if (v[i] == 1)
        // {
        //     ListNode *newnode = new ListNode(1);
        //     prev->next = newnode;
        // }
        // return l2;
        // Time Complexity: O(max(m,n)) where m and n are the lengths of the two linked lists.
        // Space Complexity: O(max(m,n)) for the result linked list.
        ListNode *dummy = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *curr = dummy;
        int carry = 0;
        while (p1 || p2 || carry)
        {
            int sum = carry;
            if (p1)
            {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2)
            {
                sum += p2->val;
                p2 = p2->next;
            }
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
        }
        ListNode *result = dummy->next;
        delete dummy; // delete the dummy node to avoid memory leak
        return result;
        // there is memeory leak in the above code as we are not deleting the dummy node
        // we can use smart pointers to avoid memory leak or we can use a stack to store the nodes and delete them after we are done with the linked list.
    }
};
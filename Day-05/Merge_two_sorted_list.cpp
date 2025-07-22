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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *dummy = new ListNode();
        ListNode *newnode = dummy;
        while (head1 != nullptr || head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                newnode->next = head1;
                head1 = head1->next;
            }
            else
            {
                newnode->next = head2;
                head2 = head2->next;
            }
            newnode = newnode->next;
        }
        if (head1 != nullptr)
        {
            newnode->next = head1;
        }
        else
        {
            newnode->next = head2;
        }
        return dummy->next;
    }
};

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
        ListNode *temp = head;
        int len = 0;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        if (len == 1)
        {
            delete head;
            head = nullptr;
            return head;
        }
        if (len == n)
        {
            ListNode *del2 = head;
            head = head->next;
            delete del2;
            return head;
        }
        int del = len - n;
        int cnt = 0;
        ListNode *temp2 = head;
        while (cnt < del - 1)
        {
            temp2 = temp2->next;
            cnt++;
        }
        ListNode *del1 = temp2->next;
        temp2->next = temp2->next->next;
        delete del1;
        return head;
    }
};
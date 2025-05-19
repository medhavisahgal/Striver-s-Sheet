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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // int len =0;
        // ListNode* temp2=head;
        // while(temp2){
        //     len++;
        //     temp2=temp2->next;
        // }
        // if(!head||!(head->next)){
        //     return head;
        // }
        // for(int i=0;i<k%len;i++){
        //     ListNode* temp=head;
        //     while(temp->next->next){
        //         temp=temp->next;
        //     }
        //     ListNode* newst=temp->next;
        //     newst->next=head;
        //     head=newst;
        //     temp->next=nullptr;
        // }
        // return head;
        // Time complexity is O(n*k) and space complexity is O(1)
        // Optimized approach
        if (!head || !head->next || k == 0)
            return head;
        int len = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        k %= len;
        if (k == 0)
            return head;

        tail->next = head;
        int stepsToNewTail = len - k;
        ListNode *newTail = tail;
        while (stepsToNewTail--)
        {
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
        // Time complexity is O(n) and space complexity is O(1)
        // where n is the number of nodes in the linked list.
    }
};
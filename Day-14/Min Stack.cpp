#include <algorithm>
using namespace std;
class MinStack
{
private:
    struct Node
    {
        int val;
        int minv;
        Node *next;
        Node(int val1, int minv1, Node *next1)
        {
            this->val = val1;
            this->minv = minv1;
            this->next = next1;
        }
    };
    Node *head;

public:
    MinStack()
    {
        head = nullptr;
    }
    void push(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val, val, nullptr);
        }
        else
        {
            head = new Node(val, min(val, head->minv), head);
        }
    }
    void pop()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    int top()
    {
        if (head != nullptr)
        {
            return head->val;
        }
        return -1;
    }
    int getMin()
    {
        if (head != nullptr)
        {
            return head->minv;
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
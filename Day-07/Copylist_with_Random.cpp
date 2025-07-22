#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *newHead = nullptr;
        Node *newtail = nullptr;
        Node *temp = head;
        map<Node *, Node *> nodeMap;
        while (temp)
        {
            Node *newnode = new Node(temp->val);
            nodeMap[temp] = newnode;
            if (newHead == nullptr)
            {
                newHead = newnode;
                newtail = newnode;
            }
            else
            {
                newtail->next = newnode;
                newtail = newtail->next;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            Node *copiedNode = nodeMap[temp];
            copiedNode->random = nodeMap[temp->random];
            temp = temp->next;
        }
        return newHead;
    }
};
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
};
struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    // Node *merge(Node *head1, Node *head2)
    // {
    //     Node *dummy = new Node(0);
    //     Node *tail = dummy;
    //     while (head1 && head2)
    //     {
    //         if (head1->data < head2->data)
    //         {
    //             tail->bottom = head1;
    //             head1 = head1->bottom;
    //         }
    //         else
    //         {
    //             tail->bottom = head2;
    //             head2 = head2->bottom;
    //         }
    //         tail = tail->bottom;
    //     }
    //     if (head1)
    //     {
    //         tail->bottom = head1;
    //     }
    //     else
    //     {
    //         tail->bottom = head2;
    //     }
    //     return dummy->bottom;
    // }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root)
    {
        // if (!root || !root->next)
        //     return root;
        // vector<int> v;
        // Node *temp = root;
        // while (temp)
        // {
        //     Node *temp1 = temp;
        //     while (temp1)
        //     {
        //         v.push_back(temp1->data);
        //         temp1 = temp1->bottom;
        //     }
        //     temp = temp->next;
        // }
        // sort(v.begin(), v.end());
        // Node *head2 = nullptr;
        // Node *tail = nullptr;
        // for (int i = 0; i < v.size(); i++)
        // {
        //     Node *newnode = new Node(v[i]);
        //     if (head2 == nullptr)
        //     {
        //         head2 = newnode;
        //         tail = newnode;
        //     }
        //     else
        //     {
        //         tail->bottom = newnode;
        //         tail = newnode;
        //     }
        // }
        // return head2;
        // Time Complexity:O(n*mlog(n*m))
        // Space Complexity:O(n*m)
        // Recursive approach
        // root->next = flatten(root->next);
        // root = merge(root, root->next);
        // return root;
        // Time Complexity:O(n*m)
        // Space Complexity:O(n)
        // Please note that the above code is not optimal and can be improved.
        // The optimal solution is to use a priority queue or a min heap to merge the linked lists.
        // This will reduce the time complexity to O(nlogk) where k is the number of linked lists.
        // The space complexity will remain O(n) as we need to store the merged linked list.
        // priority_queue<type, container, comparator> name;
        priority_queue<Node *, vector<Node *>, compare> pq;
        // Min-Heap
        Node *head = nullptr;
        Node *tail = nullptr;
        while (root)
        {
            pq.push(root);
            root = root->next;
        }
        while (!pq.empty())
        {
            auto minNode = pq.top();
            pq.pop();
            if (!head)
            {
                head = minNode;
                tail = minNode;
            }
            else
            {
                tail->bottom = minNode;
                tail = tail->bottom;
            }
            if (minNode->bottom)
            {
                pq.push(minNode->bottom);
                minNode->bottom = nullptr;
            }
        }
        return head;
    }
};
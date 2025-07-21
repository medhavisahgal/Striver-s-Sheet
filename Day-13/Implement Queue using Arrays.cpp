#include <iostream>
using namespace std;
class queue
{
private:
    int front, rear, size;
    int *arr;

public:
    // Constructor to initialize the queue with a given size
    queue(int s)
    {
        size = s;
        front = 0;
        rear = -1;
        arr = new int[size];
    }
    // destructor to free allocated memory
    ~queue()
    {
        delete[] arr;
    }
    // Enqueue operation
    void enqueue(int x)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }
    // Dequeue operation
    int dequeue()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int dequeued = arr[front];
        front++;
        return dequeued;
    }
    // Peek operation
    int peek()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    // Check if queue is empty
    bool isEmpty()
    {
        return front > rear;
    }
    // Check if queue is full
    bool isFull()
    {
        return rear == size - 1;
    }
};
int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element is: " << q.peek() << endl;
    cout << "Dequeued element is: " << q.dequeue() << endl;
    cout << "Front element after dequeue is: " << q.peek() << endl;
    return 0;
}
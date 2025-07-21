#include <iostream>
using namespace std;
class stack
{
private:
    int top;
    int *arr;
    int capacity;

public:
    stack(int size)
    {
        top = -1;
        capacity = size;
        arr = new int[capacity];
    }
    // Destructor to free memory
    ~stack()
    {
        delete[] arr;
    }
    // Push operation
    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    // Pop operation
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int popped = arr[top];
        top--;
        return popped;
    }
    // Peek operation
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }
    // Check if stack is full
    bool isFull()
    {
        return top == capacity - 1;
    }
    // Display stack elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element is: " << s.peek() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    s.display();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;
    s.push(40);
    s.push(50);
    s.push(60);
    s.display();
    return 0;
}
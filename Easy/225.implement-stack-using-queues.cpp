/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack
{
public:
    int *arr;
    int size;
    int front;

    MyStack()
    {
        size = 10001;
        arr = new int[size];
        front = -1;
    }

    void push(int x)
    {
        if (front == size)
        {
            cout << "Stack is full";
        }
        else
        {
            front++;
            arr[front] = x;
        }
    }

    int pop()
    {
        if (front == -1)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front--;
            return ans;
        }
    }

    int top()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

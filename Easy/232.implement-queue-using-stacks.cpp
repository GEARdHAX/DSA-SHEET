/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;
    MyQueue()
    {
        size = 10001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int x)
    {
        if (rear == size)
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            arr[rear] = x;
            rear++;
        }
    }

    int pop()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int peek()
    {
        if (front == rear)
        {
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == rear)
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
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

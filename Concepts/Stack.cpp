#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
    Stack(int s)
    {
        this->size = s;
        arr = new int(s);
        top = -1;
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
            cout << arr[top] << endl;
        }
        else
        {
            cout << "Can't push" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Empty Stack" << endl;
        }
    }
    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        if (top >= 0 && top < size)
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(50);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.print();
}
#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
public:
    int arr[100]; // size as per constraints
    int top1 = -1;
    int top2 = 100;

    void push1(int x)
    {
        if (top2 - top1 > 1)
        {
            arr[++top1] = x;
        }
    }

    void push2(int x)
    {
        if (top2 - top1 > 1)
        {
            arr[--top2] = x;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
            return arr[top1--];
        return -1;
    }

    int pop2()
    {
        if (top2 < 100)
            return arr[top2++];
        return -1;
    }
};

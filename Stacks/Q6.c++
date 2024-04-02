// small element of stack using List stack
#include <iostream>
#include <stack>
using namespace std;
class MinStack
{
    stack<long int> st;
    long int min;

public:
    MinStack()
    {
        min = INT16_MAX;
    }
    void push(int val)
    {
        if (st.empty())
        {
            this->min = val;
            st.push(val);
        }
        else
        {
            st.push(val - this->min);
            if (this->min > val)
            {
                this->min = val;
            }
        }
    }
    void pop()
    {
        if (!st.empty())
        {
            if (this->st.top() > 0)
            {
                this->st.pop();
            }
            else
            {
                this->min = this->min - this->st.top();
                this->st.pop();
            }
        }
    }
    int top()
    {
        if (this->st.top() < 0)
        {
            return this->min;
        }
        else if(this->st.size() == 1)
        return st.top();
        else
        {
            return this->min + this->st.top();
        }
    }
    int getmin()
    {
        return this->min;
    }
};
int main()
{
    MinStack M1;
    M1.push(10);
    M1.push(5);
    M1.push(0);
    M1.push(7);
    M1.push(-1);
    M1.push(2);
    cout << M1.getmin() << endl;
    M1.pop();
    M1.pop();
    M1.pop();
    cout << M1.getmin() << endl;
    cout<<M1.top();
}
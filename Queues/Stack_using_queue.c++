#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> qu;

public:
    // push representating
    void push(int x)
    {
        this->qu.push(x);
    }
    void pop()
    {
        queue<int> temp;
        while (qu.size() > 1)
        {
            temp.push(this->qu.front());
            qu.pop();
        }
        this->qu.pop();
        while (not temp.empty())
        {
            this->qu.push(temp.front());
            temp.pop();
        }
    }
    bool empty()
    {
        return qu.empty();
    }
    int front()
    {
        queue<int> temp;
        while (qu.size() > 1)
        {
            temp.push(qu.front());
            qu.pop();
        }
        int f = this->qu.front();
       temp.push(qu.front());
       qu.pop();
        while (not temp.empty())
        {
            this->qu.push(temp.front());
            temp.pop();
        }
        return f;
    }
};
int main()
{

    Stack st = Stack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    st.pop();
    st.push(70);
    while (not st.empty())
    {
        cout << st.front() << "   ";
        st.pop();
    }
    return 0;
}
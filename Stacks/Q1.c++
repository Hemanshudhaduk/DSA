#include <iostream>
#include <stack>
#include<vector>
using namespace std;
bool CheackBrackets(string s, int size1)
{
    stack<int> st;
    // int n = s.size();
    // int n = s.length;
    for (int i = 0; i < size1; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') //()()(())
        {
            st.push(ch);
        }
        else
        {
            if (ch == ']' && st.top() == '[' && !st.empty())
            {
                st.pop();

            }
           else if (ch == '}' && st.top() == '{' && !st.empty())
            {
                st.pop();
            }
            else if (ch == ')' && st.top() == '(' && !st.empty())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
    cout<<"\t ID : 22DCE022"<<endl;
    string str="{{()}}";
    cout<<str<<":    ";
    if(CheackBrackets(str, 6)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
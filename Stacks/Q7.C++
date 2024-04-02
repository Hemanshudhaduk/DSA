// balance brakets in take a user input string.
#include <iostream>
#include <stack>
#include<vector>
using namespace std;
vector<int> CheackBrackets(string s, int size1)
{
    stack<int> st;
    vector<int>v;
    for (int i = 0; i < size1; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') //()()(())
        {
            st.push(ch);
            v.push_back(i);
        }
        else
        {
            if (ch == ']' && st.top() == '[' && !st.empty())
            {
                st.pop();
                v.push_back(i);
            }
           else if (ch == '}' && st.top() == '{' && !st.empty())
            {
                st.pop();
                v.push_back(i);
            }
            else if (ch == ')' && st.top() == '(' && !st.empty())
            {
                st.pop();
                v.push_back(i);
            }
            else
            {
                
               // return false;
            }
        }
    }
    return v;
}
int main()
{
    cout<<"\t ID : 22DCE022"<<endl;
    string str="{{()}}[)";
    cout<<str<<":    ";
    vector<int> res = CheackBrackets(str,6);
    for(int i=0;i<6;i++){
        cout<<str[res[i]];
    }
}
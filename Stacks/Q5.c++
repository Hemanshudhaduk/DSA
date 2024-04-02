// histograms
#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int Histogram(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    int ans = INT_MIN;
    st.push(0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and arr[i] < arr[st.top()])  //find the next smallest element 
        {
            int el = arr[st.top()];
            st.pop();
            int nsi = i;
            int psi = (st.empty() )? -1 : st.top(); // find the previous smallest element
            ans = max(ans, el * (nsi - psi - 1)); //maximum answer
        }
        st.push(i);
    }
    while (!st.empty()) // here store element in stack if it is not a get answer so use this. 
    {
        int el = arr[st.top()];
        st.pop();
        int nsi = n;
        int psi = (st.empty()) ? -1 : st.top();
        ans = max(ans, el * (nsi - psi - 1));
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter a Array size : ";
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int res = Histogram(v);
    cout << res << " ";
    return 0;
}
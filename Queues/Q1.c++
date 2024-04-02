// reverse queue..
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
    queue<int> qu;
    stack<int> st;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.pop();
    qu.push(40);

    while (not qu.empty())
    {
        st.push(qu.front());
        qu.pop();
    }
    // Reverse Queue...
    while(not st.empty()){
        cout<<st.top()<<"  ";
        st.pop();
    }
    
}
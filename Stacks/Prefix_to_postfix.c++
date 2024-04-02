#include<iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;
string evaluate(string &str){
    stack<string>st;
    reverse(str.begin(),str.end());
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
            st.push(to_string(str[i] -'0'));
        }
        else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            // string newex = str[i] + v1 + v2;
            string newex = v1 + v2 + str[i];
            st.push(newex);
        }
    }
    return st.top();
}
int main(){
    string str = "*+31-15"; //  13+15-*
    // string str1 = "31+15-*"; 
    cout<<evaluate(str)<<"  ";
}
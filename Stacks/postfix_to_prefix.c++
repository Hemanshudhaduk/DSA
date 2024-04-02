#include<iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;
string evaluate(string &str){
    stack<string>st;
    // reverse(str.begin(),str.end());
    int count=0;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
            st.push(to_string(str[i] -'0'));
            count++;
        }
        else{
            // if(st.empty()) st.push(to_string(str[i]));
            // else if(count==0)  st.push(to_string(str[i]));
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string newex = str[i]+ v2 + v1 ;
            st.push(newex);
        }
    }
    return st.top();
}
int main(){
    string str = "31+15-*"; //   *+31-15 // *-51+31
    cout<<evaluate(str)<<"  ";
}
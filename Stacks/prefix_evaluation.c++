// prefix expression evaluation like -9+*132
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int cal(int v1,int v2,char op){
    if(op == '+'){
        return v1+v2;
    }
    else if(op == '^'){
        return pow(v1,v2);
    }
    else if(op == '*'){
        return v1*v2;
    }
    else if(op == '/'){
        return v1/v2;
    }
    return v1-v2;
}
int evaulate(string s){
    stack<int>st;
    for(int i=s.size()-1;i>=0;i--){
        char ch=s[i];
        if(isdigit(ch)){
            st.push(ch -'0');
        }
        else{
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(cal(v1,v2,ch));
        }
    }
    return st.top();
}
int main(){
    string str ="-9+*132"; // -9+*132
    cout<<evaulate(str)<<"  ";
}

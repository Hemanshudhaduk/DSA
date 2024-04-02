#include<iostream>
#include<stack>
using namespace std;
stack<int>DeciHexa(int n){
    stack<int>st;
    int div =0;
    while(n>0){ 
        div =  n%8;
        st.push(div);
        n/=8;
    }
    return st;
}
int main(){
    cout<<"Enter a Decimal Number : ";
    int n;
    cin>>n;
    stack<int>res;
    res = DeciHexa(n);
    while(not res.empty()){
        cout<<res.top();
        res.pop();
    }
}
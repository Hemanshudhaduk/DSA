#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int HexaDeci(int &n){
    stack<int>st;
    int i=0,div;
    while (n>0)
    {
        div = n%10;
        st.push(div*pow(8,i));
        n/=10;
        i++;
    }
    int res=0;
    while(not st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    cout<<"Enter a Number : ";
    int n;
    cin>>n;
    int res = HexaDeci(n);
    cout<<res;
}
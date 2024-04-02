#include<iostream>
#include<math.h>
#include<stack>
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

int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' or ch == '/') return 2;
    else if(ch == '+' or ch == '-') return 1;
    return -1;
}
int evaluation(string str){
    stack<int>nums;
    stack<char>oprand;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
            nums.push(str[i] - '0');
        }
        else if(str[i] == '('){
            oprand.push('(');
        }
        else if(str[i] ==')'){
            while(not oprand.empty() and oprand.top() != '('){
            char op=oprand.top();
            oprand.pop();
            int v2 = nums.top();
            nums.pop();
            int v1 = nums.top();
            nums.pop();
            nums.push(cal(v1,v2,op));
            }
            if(not oprand.empty()) oprand.pop();
        }
        else{
            while(not oprand.empty() and precedence(oprand.top())>=str[i]){
            char op=oprand.top();
            oprand.pop();            
            int v2 = nums.top();
            nums.pop();
            int v1 = nums.top();
            nums.pop();
            nums.push(cal(v1,v2,op));
            }
            oprand.push(str[i]);
        }
    }
    while(not oprand.empty()){
            char op=oprand.top();
            oprand.pop();            
            int v2 = nums.top();
            nums.pop();
            int v1 = nums.top();
            nums.pop();
            nums.push(cal(v1,v2,op));        
    }
    return nums.top();
}
int main(){
    string str ="2+(3*(3-2))+2";
    cout<<evaluation(str)<<"  ";
    return 0;
}
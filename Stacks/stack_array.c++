#include <iostream>
using namespace std;
class Stack
{
    int top;
    int *arr;
    int Capacity;

public:
    Stack(int c)
    {
        this->Capacity = c;
        arr = new int[c];
        top = -1;
    }
    int Push(int data)
    {
        if ((this->Capacity - 1) == top)
        {
            cout << "Overflow" << endl;
            return INT8_MAX;
        }
        this->top++;
        arr[this->top] = data;
    }
    void pop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return ;
        }
        this->top--;
    }
    int  size()
    {
        return (this->Capacity);
    }
    bool Isempty()
    {
        return this->top == -1;
    }
    int getTop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return INT16_MIN;
        }
        return this->arr[this->top];
    }
    int change(int data,int position){
        if(top-position+1<=0){
            cout<<"Overflow"<<endl;
        }
        arr[this->top-position+1] = data;
    }
    void Display(){
        if(this->top<0){
            cout<<"Underflow"<<endl;
            return ;
        }
        for(int i=0;i<=top;i++){
            cout<<this->arr[i]<<"  ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack st(5);
    cout<<"\t ID : 22DCE022 "<<endl;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Display();
    st.pop();
    st.pop();
    cout<<"After POP opretion : "<<endl;
    st.Display();
}
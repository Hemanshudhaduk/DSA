#include<iostream>
using namespace std;

class Queues{
    int front;
    int Rear;
    int *que;
    int s;
    public:
    Queues(int size1){
        s=size1;
        this->front=-1;
        front++;
        this->Rear=-1;
        que = new int[size1];
    }
    int Enqueue(int data){
        if((Rear+1)==s){
            cout<<"Overflow Queues.."<<endl;
            return INT8_MIN;
        }
        Rear++;
        this->que[Rear]=data;
    }
    void Dqueue(){
        if(this->front == this->Rear){
            front=-1;
            Rear=-1;
            cout<<"Underflow..."<<endl;
        }
        else
        this->front++;
    }
    int front1(){
        return que[front];
    }
    void Display(){
        for(int i=front;i<=Rear;i++){
            cout<<this->que[i]<<"  ";
        }
        cout<<endl;
    }
};
int main(){
    Queues q1 =Queues(5);
    cout<<"\t ID : 22DCE022"<<endl;
    q1.Enqueue(12);
    q1.Enqueue(16);
    q1.Display();
    cout<<"Front elemenet : "<<endl;
    cout<<q1.front1()<<endl;
    q1.Dqueue();
    cout<<"After Dequeue operation.."<<endl;
    q1.Display();
}
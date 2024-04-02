#include <iostream>
using namespace std;
class Queue
{
    int front, rear;
    int *que;
    int size1;
    public:
    Queue(int s){
        size1=s;
        front=-1;
        rear=-1;
        que = new int[size1];
    }
    int Enqueue(int data){
        if((front==0 && rear==size1-1) || ((rear+1)%size1==front)){
            cout<<"Queues is full...."<<endl;
            return INT16_MIN;
        }
        else if(front==-1){
            rear=0;
            front=0;
            que[front]=data;
        }
        else if(front!=0 && rear==size1-1){
            rear=0;
            que[rear]=data;
        }
        else{
            rear++;
            que[rear]=data;
        }
    }
    int Dequeue(){
        if(front==-1){
            cout<<"Queue is Empty.."<<endl;
           return INT16_MIN;
        }
        else if(front==size1-1){
            front=0;
        }
        else
        front++;

        return que[front-1];
    }
    void Display(){
        if(front==-1){
            cout<<"Your Queue is Empty.."<<endl;
        }
        cout<<"\t------ Print Queue ------"<<endl;
        if(rear>=front){
            for(int i=front;i<=rear;i++){
                cout<<que[i]<<"    ";
            }
            cout<<endl;
        }
        else{
            for(int i=front;i<size1;i++){
                cout<<que[i]<<"  ";
            }
            for(int i=rear;i<front;i++){
                cout<<que[i]<<"  ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Queue q1 = Queue(5);
    cout<<"\t ID : 22DCE022 "<<endl;
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(20);
    q1.Display();
    cout<<"After Dequeue operation "<<endl;
    q1.Dequeue();
    q1.Dequeue();
    q1.Display();
}
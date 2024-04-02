#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *NextNode;
} *start = nullptr;
struct node *Createnode()
{
    struct node *newnode = new struct node;
    cout << "Enter a data in node : ";
    cin >> newnode->data;
    newnode->NextNode = nullptr;
    return newnode;
}
struct node *Enqueue(struct node *head)
{
    struct node *previousNode = head;
    while (true)
    {
        struct node *CurrentNode = Createnode();
        if (previousNode == nullptr)
        {
            head = CurrentNode;
            previousNode = CurrentNode;
        }
        else
        {
            previousNode->NextNode = CurrentNode;
            previousNode = CurrentNode;
        }
        char loopend;
        cout << "Do you want to continue?(Y/N) : ";
        cin >> loopend;
        if (loopend == 'N' || loopend == 'n')
        {
            break;
        }
    }
    return head;
}
struct node *Dequeue(struct node *head)
{
    struct node *temp;
    temp = head;
    head = temp->NextNode;
    temp->NextNode = nullptr;
    //Enque temp;
    return head;
}
void DisplayLinkList(struct node *head)
{
    cout << endl;
    struct node *Node = head;
    while (Node != nullptr)
    {
        cout << "Your Data value is : " << Node->data << endl;
        Node = Node->NextNode;
    }
}
int main(){
    cout<<"\t ID : 22DCE022 "<<endl;
    cout<<"Enqueue Operation.."<<endl;
    start=Enqueue(start);
    DisplayLinkList(start);
    cout<<endl<<"Deques Opration..";
    start=Dequeue(start);
    DisplayLinkList(start);
}
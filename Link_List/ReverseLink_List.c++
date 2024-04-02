#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *NextNode;
}*start = nullptr;
struct node *Createnode(){
    struct node *NewNode = new struct node;
    cout<<"Enter a Data : ";
    cin>>NewNode->data;
    NewNode->NextNode=nullptr;
    return NewNode;
}
struct node *CreateLinklist(struct node *head)
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
struct node *Link_List_Reverse(struct node *head){
    struct node *previosnode=nullptr;
    struct node *currentnode = head;
    struct node *nextnode;
    while(currentnode != nullptr){
        nextnode=currentnode->NextNode;
        currentnode->NextNode=previosnode;
        previosnode=currentnode;
        currentnode=nextnode;
    }
    head=previosnode;
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
    start = CreateLinklist(start);
    DisplayLinkList(start);
    cout<<endl<<"Reverse Link List :";
    start=Link_List_Reverse(start);
    DisplayLinkList(start);

}
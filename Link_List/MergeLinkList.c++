#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *NextNode;
}*start = nullptr,*nest=nullptr;
struct node *Createnode()
{
    struct node *newnode = new struct node;
    cout << "Enter a data in node : ";
    cin >> newnode->data;
    newnode->NextNode = nullptr;
    return newnode;
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
void *Merge_node(struct node *head , struct node *head1){
    struct node *ptr1 = head;
    struct node *ptr2 = head1;
    // struct node *dummNode =new struct node;
    // struct node *ptr3=dummNode;
    while(ptr1 !=nullptr && ptr2 !=nullptr){
        if(ptr1->data < ptr2->data){
            ptr1=ptr1->NextNode;
        }
        else if(ptr1->data > ptr2->data){
            ptr1->NextNode = ptr2;
            ptr2=ptr2->NextNode;
        }
        ptr1=ptr1->NextNode;
    }
    while(ptr2!=nullptr){
        ptr1->NextNode=ptr2;
        ptr2=ptr2->NextNode;
        ptr1=ptr1->NextNode;
    }
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
    cout<<"First Link List : "<<endl;
    start=CreateLinklist(start);
    cout<<"Second Link List : "<<endl;
    nest=CreateLinklist(nest);
    DisplayLinkList(start);
    DisplayLinkList(nest);
    Merge_node(start,nest);
    DisplayLinkList(start); 
}
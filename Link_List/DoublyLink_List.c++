#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *PreNode;
    struct node *NextNode;
} *start = nullptr;
struct node *Createnode(){
    struct node *newnode = new struct node;
    cout << "Enter a data in node : ";
    cin >> newnode->data;
    newnode->NextNode = nullptr;
    newnode->PreNode = nullptr;
    return newnode;
}
struct node *CreateLinkList(struct node *head){
    struct node *previousNode = head;
    while (true){
        struct node *CurrentNode = Createnode();
        if (previousNode == nullptr) {
            head = CurrentNode;
            previousNode = CurrentNode;
        }
        else  {
            previousNode->NextNode = CurrentNode;
            CurrentNode->PreNode = previousNode;
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
struct node *InsertFront(struct node *head)
{
    struct node *temp = head;
    struct node *newnode = Createnode();
    while (temp->PreNode == nullptr)
    {
        newnode->NextNode = temp;
        temp->PreNode = newnode;
        head = newnode;
    }
    return head;
}
struct node *InserEnd(struct node *head)
{
    struct node *temp = head;
    struct node *NewNode = Createnode();
    while (temp->NextNode != nullptr)
    {
        temp = temp->NextNode;
    }
    temp->NextNode = NewNode;
    NewNode->PreNode = temp;
    return head;
}
struct node *InsertNodeBetween(struct node *head)
{
    struct node *temp = head;
    int n;
    cout << "Entre after given node information : " << endl;
    cin >> n;
    struct node *NewNode = Createnode();
    while (temp->data != n)
    {
        temp = temp->NextNode;
    }
    NewNode->NextNode = temp->NextNode;
    temp->NextNode = NewNode;
    NewNode->PreNode = temp;
    return head;
}
struct node *DeleteFront(struct node *head)
{
    struct node *temp = head;
    while (temp->PreNode == nullptr)
    {
        temp = temp->NextNode;
    }
    temp->PreNode = nullptr;
    head = temp;
    return head;
}

void DisplayLinkList(struct node *head)
{
    cout << endl;
    struct node *temp = head;
    while (temp != nullptr)
    {
        cout << "Your Data is " << temp->data << endl;
        temp = temp->NextNode;
    }
}
int main()
{
    cout<<"\t ID : 22DCEO22"<<endl;
    start = CreateLinkList(start);
    cout << "Insert a node at front" << endl;
    start = InsertFront(start);
    DisplayLinkList(start);
    cout << "Insert a node at End" << endl;
    start = InserEnd(start);
    DisplayLinkList(start);
    cout << "Insert a node after given node information : " << endl;
    start = InsertNodeBetween(start);
    DisplayLinkList(start);
    cout << "Delete a node at front : " << endl;
    start = DeleteFront(start);
    DisplayLinkList(start);
}

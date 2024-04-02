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
struct node *CreateCircularLinklist(struct node *head)
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
            previousNode->NextNode = head;
            break;
        }
    }
    return head;
}
struct node *InsetNodeFront(struct node *head)
{
    struct node *temp = head;
    struct node *NewNode = Createnode();
    NewNode->NextNode = temp;
    while (temp->NextNode != head)
    {
        temp = temp->NextNode;
    }
    temp->NextNode = NewNode;
    head = NewNode;
    return head;
}
struct node *DeleteNodeAtEnd(struct node *head)
{
    struct node *temp = head;
    struct node *pretemp = head;
    while (temp->NextNode != head)
    {
        pretemp = temp;
        temp = temp->NextNode;
    }
    pretemp->NextNode = head;
    return head;
}
void CirculerLinkListDisplay(struct node *head)
{
    cout << endl;
    struct node *temp = head;
    do
    {
        cout << "Your Data is : " << temp->data << endl;
        temp = temp->NextNode;
    } while (temp != head);
}
int main()
{
    cout << "\t ID : 22DCE022 " << endl;
    start = CreateCircularLinklist(start);
    CirculerLinkListDisplay(start);
    cout << "\tInserting Front End  " << endl;
    start = InsetNodeFront(start);
    CirculerLinkListDisplay(start);
    cout << "\tDelete a node at end" << endl;
    start = DeleteNodeAtEnd(start);
    CirculerLinkListDisplay(start);
}

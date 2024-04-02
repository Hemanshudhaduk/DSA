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
struct node *BeginLink_List(struct node *head)
{
    struct node *New_node = Createnode();
    cout << "--------- For Begin Input -------" << endl;
    New_node->NextNode = head;
}
struct node *Last_ADDElement(struct node *head)
{
    struct node *temp = Createnode();
    struct node *current = head;
    while (current->NextNode != nullptr)
    {
        current = current->NextNode;
    }
    current->NextNode = temp;
    return head;
}
struct node *Current_Link(struct node *head)
{
    int n;
    cout << "Enter element Where You have to assign new element : ";
    cin >> n;
    struct node *temp = head;
    while (temp->data != n)
    {
        temp = temp->NextNode;
    }
    struct node *NEW_NODE = Createnode();
    NEW_NODE->NextNode = temp->NextNode;
    temp->NextNode = NEW_NODE;
    return head;
}
struct node *Delete_Frist_node(struct node *head)
{
    struct node *temp;
    temp = head;
    head = temp->NextNode;
    temp->NextNode = nullptr;
    delete temp;
    return head;
}
struct node *Delete_Last_node(struct node *head)
{
    struct node *temp = head;
    struct node *pretemp;
    while (temp->NextNode != nullptr)
    {
        pretemp = temp;
        temp = temp->NextNode;
    }
    pretemp->NextNode = nullptr;
    delete temp;
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
int main()
{
    start = CreateLinklist(start);
    cout << "\t ID : 22DCE022 " << endl;
    DisplayLinkList(start);
    cout << "Insert Node at Starting Node : " << endl;
    start = BeginLink_List(start);
    DisplayLinkList(start);
    start = Current_Link(start);
    cout << "Enter Node vale  After a Given Node Value " << endl;
    DisplayLinkList(start);
    start = Delete_Frist_node(start);
    cout << "Delete a node at First " << endl;
    DisplayLinkList(start);
    start = Delete_Last_node(start);
    cout << "\t Delete a node at Last " << endl;
    DisplayLinkList(start);
    cout << "Insert Node at Ending Node : " << endl;
    start = Last_ADDElement(start);
    cout << "\t Insert Node at end " << endl;
    DisplayLinkList(start);
}

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
struct node *push(struct node *Top)
{
    struct node *previousNode = Top;
    while (true)
    {
        struct node *Beginnode = Createnode();
        if (previousNode == nullptr)
        {
            Top = previousNode;
            previousNode = Beginnode;
        }
        else
        {
            Beginnode->NextNode = previousNode;
            previousNode = Beginnode;
            Top = previousNode;
        }
        char loopend;
        cout << "Do you want to continue?(Y/N) : ";
        cin >> loopend;
        if (loopend == 'N' || loopend == 'n')
        {
            break;
        }
    }
    return Top;
}
struct node *pop(struct node *Top)
{
    while (true)
    {
        char loopend;
        cout << "Do You Want to next Pop operation : ";
        cin >> loopend;
        if (loopend == 'y' || loopend == 'Y')
        {
            struct node *temp;
            struct node *over;
            temp = Top;
            over = Top;
            if (temp == nullptr)
            {
                cout << "underflow" << endl;
                break;
            }
            over = temp->NextNode;
            temp->NextNode = nullptr;
            cout << "Your POP operation is Sucessfull!!!" << endl;
            Top = over;
        }
        else
        {
            break;
        }
    }
    return Top;
}
int Peep(struct node *Top, int position)
{
    int count = 0;
    struct node *temp = Top;
    while (position != count)
    {
        count++;
        temp = temp->NextNode;
    }
    return temp->data;
}
void DisplayStack(struct node *Top)
{
    cout << endl;
    struct node *Node = Top;
    while (Node != nullptr)
    {
        cout << "Your Data value is : " << Node->data << endl;
        Node = Node->NextNode;
    }
}
int main()
{
    cout<<"\t ID : 22DCE022"<<endl;
    start = push(start);
    DisplayStack(start);
    start = pop(start);
    DisplayStack(start);
}
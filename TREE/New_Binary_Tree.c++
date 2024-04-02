#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *BuildTree(node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter a data inserting in Left of  " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter a data inserting in Righr of  " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}
void LevelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
// void ReverseOrderTraversal(node* root){
//     if(root == NULL)
//         return ;
//     ReverseOrderTraversal(root->left);
//     ReverseOrderTraversal(root->right);
//     cout<<root->data<<"  ";
// }

void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << "  ";
    Inorder(root->right);
}
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    Inorder(root->left);
    Inorder(root->right);
}
void Postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    Inorder(root->right);
    cout << root->data << "  ";
}

void BuildTreeFromLevelorder(node* &root)
{
    queue<node *> q;
    cout << "Enter a data : ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter a left node for : " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter a Right node for : " << temp->data << endl;
        int Rightdata;
        cin >> Rightdata;
        if (Rightdata != -1)
        {
            temp->right = new node(Rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;
    // Create a Tree
    //     root = BuildTree(root);

    //     // Print Levelordertravrsle
    //     cout<<"Level Order Traversal"<<endl;
    //     LevelOrderTraversal(root);

    //     // print Reverseordertraversal
    //    // ReverseOrderTraversal(root);

    //    //print Inorder
    //    cout<<endl<<"Inorder Traversal "<<endl;
    //    Inorder(root);

    //    // print Preoredr
    //    cout<<endl<<"Preorder Traversal"<<endl;
    //    Preorder(root);

    //    //print Postorder
    //    cout<<endl<<"Postorder Traversal "<<endl;
    //    Postorder(root);

    BuildTreeFromLevelorder(root);
    LevelOrderTraversal(root);
}
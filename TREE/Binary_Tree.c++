#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

Node *search(Node *root, int data)
{
    if (root == nullptr || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = nullptr;
    cout << "ID : 22DCE022" << endl;
    while (true)
    {
        char loopend;
        int data;
        cout << "Enter a tree data : ";
        cin >> data;
        root = insert(root, data);
        cout << "Do you want to continue?(Y/N) : ";
        cin >> loopend;
        if (loopend == 'N' || loopend == 'n')
            break;
    }
    int searchValue;
    cout << "Enter a Searchvalue in a tree : ";
    cin >> searchValue;
    Node *result = search(root, searchValue);
    if (result != nullptr)
    {
        cout << searchValue << " found in the tree." << endl;
    }
    else
    {
        cout << searchValue << " not found in the tree." << endl;
    }

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

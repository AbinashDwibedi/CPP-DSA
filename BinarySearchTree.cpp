#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
bool search(Node *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == value)
    {
        return true;
    }
    if (root->data > value)
    {
        search(root->left, value);
    }
    return search(root->right, value);
}
int findMin(Node *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}
int findMax(Node *root)
{
    while (root->right != nullptr)
        root = root->right;
    return root->data;
}
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    std::cout << "value of is: " << root->data << std::endl;
    inorder(root->right);
}

int main()
{
    Node* root = nullptr;
    int arr[] = {2,345,543,64,123,3,65};
    for(auto value: arr){
        root = insert(root,value);
    }
    inorder(root);
    return 0;
}
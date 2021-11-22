#include <bits\stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void preorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
void postorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}
void inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preoder traversal of binary tree is:: ";
    preorder(root);
    cout<<endl;
    cout << "Postorder traversal of binary tree is:: ";
    postorder(root);
     cout<<endl;
    cout << "Inorder traversal of binary tree is:: ";
    inorder(root);
    cout<<endl;

}
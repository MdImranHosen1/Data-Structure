#include<bits\stdc++.h>
using namespace std;
struct Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};
Node* insertBST(Node* root,int value)
{
    if(root==NULL){
        return new Node(value);
    }
    if(value<root->data){
        root->left=insertBST(root->left,value);
    }
    else {
        root->right=insertBST(root->right,value);
    }
    return root;
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
    Node *root=NULL;
    root=
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    
    cout << "Inorder traversal of binary tree is:: ";
    inorder(root);
    cout<<endl;

    return 0;


}

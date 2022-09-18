// Problem Link - https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

//Function to find the lowest common ancestor in a BST. 

Node* DFS(Node* root, ll n1, ll n2)
{
    if(root==nullptr)
        return nullptr;
    if(n1<root->data and n2<root->data)
        return DFS(root->left,n1,n2);
    if(n1>root->data and n2>root->data)
        return DFS(root->right,n1,n2);
    return root;
}

Node* LCA(Node *root, int n1, int n2)
{
    return DFS(root,n1,n2);
}


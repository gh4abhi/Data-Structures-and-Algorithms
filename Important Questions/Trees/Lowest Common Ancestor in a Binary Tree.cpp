// Problem Link - https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    ll ans = -1;
    
    Node* DFS(Node* root, ll n1, ll n2)
    {
        if(root==nullptr)
            return nullptr;
        Node* lef = DFS(root->left,n1,n2);
        Node* rig = DFS(root->right,n1,n2);
        if(lef and rig)
            return root;
        if(root->data==n1)
            return root;
        if(root->data==n2)
            return root;
        if(lef)
            return lef;
        if(rig)
            return rig;
        return nullptr;
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        return DFS(root,n1,n2);
    }
};

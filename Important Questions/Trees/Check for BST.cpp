// Problem Link - https://practice.geeksforgeeks.org/problems/check-for-bst/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll long long

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool DFS(Node* root, ll maxi, ll mini)
    {
        if(root==nullptr)
            return 1;
        if(root->data>=maxi or root->data<=mini)
            return false;
        return DFS(root->left,root->data, mini) and DFS(root->right, maxi, root->data);
    }
    
    bool isBST(Node* root) 
    {
        return DFS(root,LONG_MAX,LONG_MIN);
    }
};

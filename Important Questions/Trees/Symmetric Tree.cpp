// Problem Link - https://practice.geeksforgeeks.org/problems/symmetric-tree/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    
    bool DFS(struct Node* root1, struct Node* root2)
    {
        if(!root1 and root2)
            return false;
        if(root1 and !root2)
            return false;
        if(!root1 and !root2)
            return true;
        if(root1->data != root2->data)
            return false;
        return DFS(root1->left,root2->right) and DFS(root1->right,root2->left);
    }
    
    bool isSymmetric(struct Node* root)
    {
        if(root==nullptr)
            return true;
        return DFS(root->left,root->right);
    }
};

// Problem Link - https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int
// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    void DFS(Node* root, vector<ll>& ans, ll level)
    {
        if(root==nullptr)
            return;
        if(level==ans.size())
            ans.push_back(root->data);
        DFS(root->right,ans,level+1);
        DFS(root->left,ans,level+1);
    }
    
    vector<int> rightView(Node *root)
    {
        vector<ll> ans;
       DFS(root,ans,0);
       return ans;
    }
};

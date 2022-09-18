// Problem Link - https://practice.geeksforgeeks.org/problems/inorder-traversal/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    
    void DFS(Node* root, vector<ll> &ans)
    {
        if(root==nullptr)
            return;
        DFS(root->left,ans);
        ans.push_back(root->data);
        DFS(root->right,ans);
    }
    
    vector<int> inOrder(Node* root) {
        vector<ll> ans;
        DFS(root,ans);
        return ans;
    }
};
// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution{
  public:
    /*You are required to complete this method*/
    
    ll ans = 1e9;
    
    void DFS(Node* root, ll count)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr and root->right==nullptr)
        {
            ans = min(ans,count);
            return;
        }
        DFS(root->left,count+1);
        DFS(root->right,count+1);
    }
    
    int minDepth(Node *root) {
        DFS(root,1);
        return ans;
    }
};

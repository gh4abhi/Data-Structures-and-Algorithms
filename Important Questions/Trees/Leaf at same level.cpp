// Problem Link - https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int
class Solution{
  public:
    /*You are required to complete this method*/
    
    ll ans = -1;
    
    bool DFS(Node* root, ll level)
    {
        if(root==nullptr)
            return 1;
        if(root->left==nullptr and root->right==nullptr)
        {
            if(ans==-1)
                ans = level;
            else
                return ans==level;
        }
        return DFS(root->left,level+1) and DFS(root->right,level+1);
    }
    
    bool check(Node *root)
    {
        return DFS(root,0);
    }
};
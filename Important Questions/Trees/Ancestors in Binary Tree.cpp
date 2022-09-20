// Problem Link - https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int
class Solution{
  public:
    // Function should return all the ancestor of the target node
    
    ll DFS(struct Node* root, ll x, vector<ll> &ans)
    {
        if(root==nullptr)
            return -1;
        if(root->data==x)
            return x;
        if(DFS(root->left,x,ans)!=-1)
        {
            ans.push_back(root->data);
            return x;
        }
        if(DFS(root->right,x,ans)!=-1)
        {
            ans.push_back(root->data);
            return x;
        }
        return -1;
    }
    
    vector<int> Ancestors(struct Node *root, int target)
    {
         vector<ll> ans;
         DFS(root,target,ans);
         return ans;
    }
};
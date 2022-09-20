// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    map<pair<Node*,ll>,ll> dp;
    ll DFS(Node* root, ll op)
    {
        if(root==nullptr)
            return 0;
        if(dp.count({root,op}))
            return dp[{root,op}];
        if(op)
            return dp[{root,op}] = max(root->data + DFS(root->left,0) + DFS(root->right,0), DFS(root,0));
        if(!op)
            return dp[{root,op}] = DFS(root->left,1) + DFS(root->right,1);
    }
    
    int getMaxSum(Node *root) 
    {
        return DFS(root,1);
    }
};

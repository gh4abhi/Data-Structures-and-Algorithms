// Problem Link - https://practice.geeksforgeeks.org/problems/max-level-sum-in-binary-tree/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution{
  public:
    /*You are required to complete below method */
    
    void DFS(Node* root, ll level, unordered_map<ll,ll> &m)
    {
        if(root==nullptr)
            return;
        m[level]+=root->data;
        DFS(root->left,level+1,m);
        DFS(root->right,level+1,m);
    }
    
    int maxLevelSum(Node* root) {
        unordered_map<ll,ll> m;
        DFS(root,0,m);
        ll maxi = INT_MIN;
        for(auto i:m)
            maxi = max(maxi,i.second);
        return maxi;
    }
};
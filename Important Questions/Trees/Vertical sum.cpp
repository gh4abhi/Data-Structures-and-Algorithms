// Problem Link - https://practice.geeksforgeeks.org/problems/vertical-sum/1?page=4&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution{
  public:
    
    void DFS(Node* root, map<ll,ll> &m, ll c)
    {
        if(root==nullptr)
            return;
        m[c] += root->data;
        DFS(root->left,m,c-1);
        DFS(root->right,m,c+1);
    }
    
    vector <int> verticalSum(Node *root) {
        map<ll,ll> m;
        DFS(root,m,0);
        vector<ll> ans;
        for(auto i:m)
            ans.push_back(i.second);
        return ans;
    }
};

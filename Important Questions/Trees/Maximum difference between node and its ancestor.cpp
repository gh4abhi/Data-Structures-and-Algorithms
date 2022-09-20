// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

//Function to return the maximum difference between any node and its ancestor.


void DFS(Node* root, ll par, ll &ans)
{
    if(root==nullptr)
        return;
    ll op = par;
    if(par!=INT_MIN)
        ans = max(ans,par-root->data);
    op = max(op,root->data);
    DFS(root->left,op,ans);
    DFS(root->right,op,ans);
}

int maxDiff(Node* root)
{
    ll ans = INT_MIN;
    DFS(root,INT_MIN,ans);
    return ans;
}

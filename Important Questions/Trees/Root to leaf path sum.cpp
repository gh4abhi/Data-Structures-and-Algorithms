// Problem Link - https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int
/*you are required to
complete this function */
class Solution
{
    public:
    
    ll ans = 0;
    
    void DFS(Node* root, ll sum, ll S)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr and root->right==nullptr)
        {
            if(sum+root->data==S)
                ans = 1;
            return;
        }
        DFS(root->left,sum+root->data,S);
        DFS(root->right,sum+root->data,S);
    }
    
    bool hasPathSum(Node *root, int S) {
    DFS(root,0,S);
    return ans;
}
};
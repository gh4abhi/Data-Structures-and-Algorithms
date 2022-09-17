// Problem Link - https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    ll ans = 0;
    
    ll DFS(Node* root)
    {
        if(root==nullptr)
            return 0;
        ll lef = DFS(root->left);
        ll rig = DFS(root->right);
        ans = max(ans,1 + lef+rig);
        return 1 + max(lef,rig);
    }
    
    int diameter(Node* root) {
        DFS(root);
        return ans;
    }
};
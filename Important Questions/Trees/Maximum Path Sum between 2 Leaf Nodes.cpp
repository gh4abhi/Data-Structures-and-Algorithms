// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

#define ll int

class Solution {
public:
    
    ll ans = INT_MIN;
    
    ll DFS(Node* root, ll level)
    {
        if(root==nullptr)
            return INT_MIN;
            
        if(root->left==nullptr and root->right==nullptr)
            return root->data;
        
        ll lef = DFS(root->left,level+1);
        ll rig = DFS(root->right,level+1);
        
        if(root->left and root->right)
            ans = max(ans,root->data + lef + rig);
        
        if(level==0 and root->left and !root->right)
            ans = max(ans,root->data + lef);
        
        if(level==0 and !root->left and root->right)
            ans = max(ans,root->data + rig);
        
        return root->data + max(lef,rig);
    }
    
    int maxPathSum(Node* root)
    {
        DFS(root,0);
        return ans;
    }
};
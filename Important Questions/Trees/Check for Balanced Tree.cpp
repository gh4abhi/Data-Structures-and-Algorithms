// Problem Link - https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

/* A binary tree node structure

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
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    ll ans = 1;
    
    ll DFS(Node* root)
    {
        if(root==nullptr)
            return 0;
        ll lef = DFS(root->left);
        ll rig = DFS(root->right);
        if(abs(lef-rig)>1)
            ans = 0;
        return 1 + max(lef,rig);
    }
    
    bool isBalanced(Node *root)
    {
        DFS(root);
        return ans;
    }
};
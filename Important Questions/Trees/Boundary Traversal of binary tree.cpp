// Problem Link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution {
public:

    void addLeft(Node* root, vector<ll> &ans)
    {
        if(root==nullptr)
            return;
        Node* cur = root;
        while(cur)
        {
            if(cur->left or cur->right)
                ans.push_back(cur->data);
            if(cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    
    void addLeaves(Node* root, vector<ll>& ans)
    {
        if(!root)
            return;
        addLeaves(root->left,ans);
        if(!root->left and !root->right)
            ans.push_back(root->data);
        addLeaves(root->right,ans);
    }
    
    void addRight(Node* root, vector<ll>& ans)
    {
        if(root==nullptr)
            return;
        vector<ll> temp;
        Node* cur = root;
        while(cur)
        {
            if(cur->left or cur->right)
                temp.push_back(cur->data);
            if(cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        for(ll i=temp.size()-1;i>=0;i--)
            ans.push_back(temp[i]);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<ll> ans;
        if(root==nullptr)
            return ans;
        ans.push_back(root->data);
        if(!root->left and !root->right)
            return ans;
        addLeft(root->left,ans);
        addLeaves(root,ans);
        addRight(root->right,ans);
        return ans;
    }
};
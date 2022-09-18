// Problem Link - https://practice.geeksforgeeks.org/problems/preorder-traversal/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int
//Function to return a list containing the preorder traversal of the tree.
    void DFS(Node* root, vector<ll> &ans)
    {
        if(root==nullptr)
            return;
        ans.push_back(root->data);            
        DFS(root->left,ans);
        DFS(root->right,ans);
    }
vector <int> preorder(Node* root)
{
        vector<ll> ans;
        DFS(root,ans);
        return ans;
}
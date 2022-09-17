// Problem Link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

void DFS(Node* root, ll level, vector<ll> &ans)
{
    if(root==nullptr)
        return;
    if(ans.size()==level)
        ans.push_back(root->data);
    DFS(root->left,level+1,ans);
    DFS(root->right,level+1,ans);
}

vector<int> leftView(Node *root)
{
    vector<ll> vect;
    DFS(root,0,vect);
    return vect;
}

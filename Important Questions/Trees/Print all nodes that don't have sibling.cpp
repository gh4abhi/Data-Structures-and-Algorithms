// Problem Link - https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

ll DFS(Node* root, vector<ll> &ans)
{
    if(root==nullptr)
        return 0;
    ll lef = DFS(root->left,ans);
    ll rig = DFS(root->right,ans);
    if(!lef and rig)
        ans.push_back(rig);
    if(lef and !rig)
        ans.push_back(lef);
    return root->data;
}

vector<int> noSibling(Node* root)
{
    vector<ll> ans;
    DFS(root,ans);
    if(ans.size()==0)
        return {-1};
    sort(ans.begin(),ans.end());
    return ans;
}
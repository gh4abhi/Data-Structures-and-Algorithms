// Problem Link - https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

ll op = -1;
ll ok = 1;

void DFS(Node* root, ll level, ll &a, ll &b)
{
    if(root==nullptr)
        return;
    if(root->left and root->right)
    {
        if(root->left->data==a and root->right->data==b)
            ok = 0;
        if(root->left->data==b and root->right->data==a)
            ok = 0;
    }
    if(root->data==a or root->data==b)
    {
        if(root->data==a)
            a = -1;
        if(root->data==b)
            b = -1;
        if(op!=-1 and op!=level)
            ok = 0;
        else
            op = level;
    }
    DFS(root->left,level+1,a,b);
    DFS(root->right,level+1,a,b);
}

bool isCousins(Node *root, int a, int b)
{
    op = -1;
    ok = 1;
    DFS(root,0,a,b);
    return ok and a==-1 and b==-1;
}
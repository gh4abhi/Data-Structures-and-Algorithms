// Problem Link - https://practice.geeksforgeeks.org/problems/sum-of-left-leaf-nodes/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// left leaf nodes

ll ans = 0;

void DFS(Node* root, ll flag)
{
    if(root==nullptr)
        return;
    if(!root->left and !root->right and flag)
        ans += root->data;
    DFS(root->left,1);
    DFS(root->right,0);
}

int leftLeavesSum(Node *root)
{
    ans = 0;
    DFS(root,0);
    return ans;
}
// Problem Link - https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

#define ll int

/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    vector<ll> ans;
    if(root==nullptr)
        return ans;
    while(pendingNodes.size())
    {
        Node* cur = pendingNodes.front();
        pendingNodes.pop();
        ans.push_back(cur->data);
        if(cur->right)
            pendingNodes.push(cur->right);
        if(cur->left)
            pendingNodes.push(cur->left);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
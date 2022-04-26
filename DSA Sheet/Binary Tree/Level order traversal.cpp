// Problem Link - https://practice.geeksforgeeks.org/problems/level-order-traversal/1

#define ll int

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
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      vector<ll> ans;
      if(root==nullptr)
      return ans;
      queue<Node*> pendingNodes;
      pendingNodes.push(root);
      while(pendingNodes.size())
      {
         Node* cur = pendingNodes.front();
         pendingNodes.pop();
         ans.push_back(cur->data);
         if(cur->left)
            pendingNodes.push(cur->left);
        if(cur->right)
            pendingNodes.push(cur->right);
      }
      return ans;
    }
};
// Problem Link - https://practice.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

/* A binary tree Node

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
//Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node* node)
{
  vector<vector<ll>> ans;
  if(node==nullptr)
    return ans;
  queue<Node*> q;
  q.push(node);
  q.push(nullptr);
  vector<ll> temp;
  while(q.size())
  {
      auto cur = q.front();
      q.pop();
      if(cur==nullptr)
      {
          ans.push_back(temp);  
          if(q.size()==0)
            break;
          temp.clear();
          q.push(nullptr);
          continue;
      }
      temp.push_back(cur->data);
      if(cur->left)
        q.push(cur->left);
     if(cur->right)
        q.push(cur->right);
  }
  return ans;
}

// Problem Link - https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

vector<int> diagonal(Node *root)
{
   vector<ll> ans;
   if(root==nullptr)
    return ans;
   queue<Node*> q;
   q.push(root);
   while(q.size())
   {
        auto cur = q.front();
        q.pop();
        while(cur)
        {
            ans.push_back(cur->data);
            if(cur->left)
                q.push(cur->left);
            cur = cur->right;
        }
   }
   return ans;
}
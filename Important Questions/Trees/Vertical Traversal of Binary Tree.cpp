// Problem Link - https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int
class Solution{
    public:
    vector<int> verticalOrder(Node *root)
    {
       map<ll,map<ll,vector<ll>>> m;
       queue<pair<Node*,pair<ll,ll>>> q;
       q.push({root,{0,0}});
       while(q.size())
       {
           auto cur = q.front();
           q.pop();
           Node* op = cur.first;
           ll r = cur.second.second;
           ll c = cur.second.first;
           m[c][r].push_back(op->data);
           if(op->left)
            q.push({op->left,{c-1,r+1}});
           if(op->right)
            q.push({op->right,{c+1,r+1}});
       }
       vector<ll> ans;
       for(auto i:m)
           for(auto j:i.second)
                for(auto k:j.second)
                    ans.push_back(k);
        return ans;
    }
};

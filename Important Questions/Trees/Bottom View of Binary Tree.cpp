// Problem Link - https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<ll> ans;
        if(root==nullptr)
            return ans;
        map<ll,ll> m;
        queue<pair<Node*, ll>> q;
        q.push({root,0});
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            m[cur.second] = cur.first->data;
            if(cur.first->left)
                q.push({cur.first->left,cur.second-1});
            if(cur.first->right)
                q.push({cur.first->right,cur.second+1});
        }
        for(auto i:m)
            ans.push_back(i.second);
        return ans;
    }
};
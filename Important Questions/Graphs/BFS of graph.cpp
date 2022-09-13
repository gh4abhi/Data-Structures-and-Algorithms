// Problem Link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<ll> ans;
        queue<ll> q;
        vector<ll> vis(V,0);
        q.push(0);
        vis[0] = 1;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto i: adj[cur])
                if(vis[i]==0)
                    vis[i] = 1, q.push(i);
        }
        return ans;
    }
};
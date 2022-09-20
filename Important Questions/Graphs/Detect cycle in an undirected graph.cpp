// Problem Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool DFS(ll source, ll pre, vector<ll> adj[], vector<ll> &vis)
    {
        vis[source] = 1;
        for(auto i:adj[source])
        {
            if(vis[i]==0)
            {
                if(DFS(i,source,adj,vis))
                    return 1;
            }
            else
            {
                if(i!=pre)
                    return 1;
            }
        }
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<ll> vis(V,0);
        for(ll i=0;i<V;i++)
            if(vis[i]==0)
                if(DFS(i,-1,adj,vis))
                    return 1;
        return 0;
    }
};

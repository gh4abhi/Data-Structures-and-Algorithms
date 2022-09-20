// Problem Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution {
  public:
    
    bool DFS(ll source, vector<ll> adj[], vector<ll> &vis, vector<ll> &dfsVis)
    {
        vis[source] = 1;
        dfsVis[source] = 1;
        for(auto i:adj[source])
        {
            if(vis[i]==0)
             {   if(DFS(i,adj,vis,dfsVis))
                    return 1;}
            else if(dfsVis[i])
                {
                    return 1;
                }
        }
        dfsVis[source] = 0;
        return 0;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<ll> vis(V,0);
        vector<ll> dfsVis(V,0);
        for(ll i=0;i<V;i++)
        {
            if(vis[i]==0)
                if(DFS(i,adj,vis,dfsVis))
                    return 1;
        }
        return 0;
    }
};
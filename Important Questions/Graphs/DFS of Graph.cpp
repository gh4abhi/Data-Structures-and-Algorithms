// Problem Link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<ll> ans;
    
    void DFS(ll source, vector<int> adj[], vector<ll>& vis)
    {
        vis[source] = 1;
        ans.push_back(source);
        for(auto i:adj[source])
            if(vis[i]==0)
                DFS(i,adj,vis);
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<ll> vis(V,0);
        DFS(0,adj,vis);
        return ans;
    }
};
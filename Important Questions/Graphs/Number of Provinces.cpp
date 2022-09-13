// Problem Link - https://practice.geeksforgeeks.org/problems/number-of-provinces/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution {
  public:
    
    void DFS(vector<vector<int>> adj, int n, ll source, vector<ll> &vis)
    {
        vis[source] = 1;
        for(ll i=0;i<n;i++)
            if(adj[source][i]==1 and vis[i]==0)
                DFS(adj,n,i,vis);
    }
    
    int numProvinces(vector<vector<int>> adj, int n) {
        vector<ll> vis(n,0);
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                DFS(adj,n,i,vis);
            }
        }
        return ans;
    }
};
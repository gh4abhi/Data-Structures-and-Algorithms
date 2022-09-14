// Problem Link - https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1?page=2&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution
{
    public:
    
    bool ans = 0;
    
    bool DFS(ll n, ll m, vector<vector<ll>> &adj, vector<ll> &vis, ll source, ll count)
    {
        vis[source] = 1;
        if(count==n)
            return 1;
        for(auto i:adj[source])
            if(vis[i]==0)
                if(DFS(n,m,adj,vis,i,count+1))
                    return 1;
        vis[source] = 0;
        return 0;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<vector<ll>> adj(N);
        vector<ll> vis(N,0);
        for(auto i:Edges)
        {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        for(ll i=0;i<N;i++)
            if(DFS(N,M,adj,vis,i,1))
                return 1;
        return 0;
    }
};
 
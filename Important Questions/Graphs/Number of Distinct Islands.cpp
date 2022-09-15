// Problem Link - https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

#define ll int

class Solution {
  public:
    void DFS(vector<vector<ll>> &vect, ll m, ll n, ll i, ll j, vector<vector<ll>> &vis, vector<pair<ll,ll>> &ans, ll x, ll y)
    {
        vis[i][j] = 1;
        ans.push_back({i-x,j-y});
        for(auto k:{-1,1})
        {
            if(i+k>=0 and i+k<m and vect[i+k][j]==1 and vis[i+k][j]==0)
                DFS(vect,m,n,i+k,j,vis,ans,x,y);
            if(j+k>=0 and j+k<n and vect[i][j+k]==1 and vis[i][j+k]==0)
                DFS(vect,m,n,i,j+k,vis,ans,x,y);
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<ll,ll>>> s;
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> vis(m,vector<ll>(m,0));
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    vector<pair<ll,ll>> vect;
                    DFS(grid,m,n,i,j,vis,vect,i,j);
                    s.insert(vect);
                }
            }
        }
        return s.size();
    }
};

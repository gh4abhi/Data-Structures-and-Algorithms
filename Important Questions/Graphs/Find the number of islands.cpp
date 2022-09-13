// Problem Link - https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution {
  public:
    // Function to find the number of islands.
    
    void DFS(vector<vector<char>>& grid, vector<vector<ll>> &vis, ll i, ll j, ll m, ll n)
    {
        vis[i][j] = 1;
        for(ll r =-1;r<=1;r++)
            for(ll c = -1;c<=1;c++)
                if(i+r>=0 and i+r<m and j+c>=0 and j+c<n and vis[i+r][j+c]==0 and grid[i+r][j+c]=='1')
                    DFS(grid,vis,i+r,j+c,m,n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        ll ans = 0;
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                    ans++, DFS(grid,vis,i,j,m,n);
            }
        }
        return ans;
    }
};
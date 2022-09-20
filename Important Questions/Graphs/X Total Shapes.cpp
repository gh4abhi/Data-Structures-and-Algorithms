// Problem Link - https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution
{
    public:
    void DFS(vector<vector<char>>& grid, vector<vector<int>>& vis, ll i, ll j)
    {
        ll m = grid.size();
        ll n = grid[0].size();
        vis[i][j] = 1;
        for(auto r:{1,-1})
        {
            if(i+r>=0 and i+r<m and vis[i+r][j]==0 and grid[i+r][j]=='X')
                DFS(grid,vis,i+r,j);
            if(j+r>=0 and j+r<n and vis[i][j+r]==0 and grid[i][j+r]=='X')
                DFS(grid,vis,i,j+r);
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        ll ans = 0;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(grid[i][j]=='X' and vis[i][j]==0)
                    ans++, DFS(grid,vis,i,j);
        return ans;
    }
};
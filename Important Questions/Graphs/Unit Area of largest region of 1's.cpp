// Problem Link - https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution
{
    public:
    
    ll DFS(vector<vector<int>>& grid, vector<vector<int>>& vis, ll i, ll j)
    {
        ll m = grid.size();
        ll n = grid[0].size();
        vis[i][j] = 1;
        ll ans = 1;
        for(auto r:{1,-1})
        {
            for(auto c:{0,1,-1})
            {
                if(i+r>=0 and i+r<m and j+c>=0 and j+c<n and vis[i+r][j+c]==0 and grid[i+r][j+c]==1)
                    ans += DFS(grid,vis,i+r,j+c);
                if(i+c>=0 and i+c<m and j+r>=0 and j+r<n and vis[i+c][j+r]==0 and grid[i+c][j+r]==1)
                    ans += DFS(grid,vis,i+c,j+r);
            }
        }
        return ans;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        ll ans = 0;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(grid[i][j]==1 and vis[i][j]==0)
                    ans = max(ans,DFS(grid,vis,i,j));
        return ans;
                
    }
};
// Problem Link - https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    void DFS(vector<vector<int>>& grid, vector<vector<int>>& vis, ll i, ll j)
    {
        ll m = grid.size();
        ll n = grid[0].size();
        vis[i][j] = 1;
        for(auto r:{1,-1})
        {
            if(i+r>=0 and i+r<m and vis[i+r][j]==0)
                DFS(grid,vis,i+r,j);
            if(j+r>=0 and j+r<n and vis[i][j+r]==0)
                DFS(grid,vis,i,j+r);
        }
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        ll r1, c1;
        ll r2, c2;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                {
                    if(grid[i][j]==0)
                        vis[i][j] = 1;
                    else if(grid[i][j]==1)
                        r1 = i, c1 = j;
                    else if(grid[i][j]==2)
                        r2 = i, c2 = j;
                }
         DFS(grid,vis,r1,c1);
         return vis[r2][c2]==1;
                    
    }
};
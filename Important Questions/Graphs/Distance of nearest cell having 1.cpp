// Problem Link - https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

#define ll int

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>>nearest(vector<vector<int>>grid)
    {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<ll> x = {1,-1};
        vector<vector<ll>> ans(m,vector<ll>(n,0));
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        queue<pair<pair<ll,ll>,ll>> q;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(grid[i][j]==1)
                    q.push({{i,j},0}), vis[i][j] = 1;
        
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            ans[cur.first.first][cur.first.second] = cur.second;
            for(auto i:x)
            {
                if(i+cur.first.first>=0 and i+cur.first.first<m and vis[i+cur.first.first][cur.first.second]==0)
                    q.push({{i+cur.first.first,cur.first.second},cur.second+1}), vis[i+cur.first.first][cur.first.second] = 1;
                if(i+cur.first.second>=0 and i+cur.first.second<n and vis[cur.first.first][i+cur.first.second]==0)
                    q.push({{cur.first.first,i+cur.first.second},cur.second+1}), vis[cur.first.first][i+cur.first.second] = 1;;
            }
        }
        return ans;
    }
};

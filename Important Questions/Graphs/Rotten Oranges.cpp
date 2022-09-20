// Problem Link - https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        queue<pair<ll,ll>> q;
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(grid[i][j]==2)
                    q.push({i,j}),vis[i][j] = 1;
        q.push({-1,-1});
        ll ans = -1;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur.first==-1)
            {
                ans++;
                if(q.size()==0)
                    break;
                q.push({-1,-1});
                // cout<<ans<<endl;
                continue;
            }
            // vis[cur.first][cur.second] = 1;
            ll r = cur.first;
            ll c = cur.second;
            // cout<<r<<" "<<c<<endl;
            for(auto i:{-1,1})
            {
                if(i+r>=0 and i+r<m and vis[i+r][c]==0 and grid[i+r][c]==1)
                    q.push({i+r,c}),vis[i+r][c] = 1;
                if(i+c>=0 and i+c<n and vis[r][i+c]==0 and grid[r][i+c]==1)
                    q.push({r,i+c}),vis[r][i+c] = 1;
            }
        }
        // cout<<ans<<endl;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(grid[i][j]==1 and vis[i][j]==0)
                    return -1;
        return ans;
    }
};

// 10 9
// 2 1 1 1 2 1 2 0 2
// 1 2 1 1 2 1 1 2 2
// 2 2 1 2 2 1 1 2 1
// 1 0 2 0 1 2 2 1 0
// 2 0 0 2 2 2 2 0 2
// 2 1 1 1 2 0 2 1 2
// 2 2 1 1 0 0 1 2 2
// 0 2 0 2 2 2 2 2 1
// 2 0 2 0 1 2 2 2 2
// 1 1 1 2 0 1 2 2 2
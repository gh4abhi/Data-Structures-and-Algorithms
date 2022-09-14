// Problem Link - https://practice.geeksforgeeks.org/problems/knight-walk4521/1?page=2&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution 
{
    public:

    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
    {
        vector<vector<ll>> vect = {{-2,2},{-1,1}};
        queue<vector<ll>> q;
        q.push(KnightPos);
        ll ans = 0;
        q.push({-1});
        vector<vector<ll>> vis(n,vector<ll>(n,0));
        vis[KnightPos[0]-1][KnightPos[1]-1] = 1;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur==TargetPos)
                return ans;
            if(cur[0]==-1)
            {
                ans++;
                if(q.size()==0)
                    return -1;
                q.push({-1});
                continue;
            }
            for(auto i:vect[0])
            {
                for(auto j:vect[1])
                {
                    if(cur[0]+i>=1 and cur[0]+i<=n and cur[1] + j>=1 and cur[1]+j<=n and vis[cur[0]+i-1][cur[1]+j-1]==0)
                        q.push({cur[0]+i,cur[1]+j}), vis[cur[0]+i-1][cur[1]+j-1] = 1;
                    if(cur[0]+j>=1 and cur[0]+j<=n and cur[1] + i>=1 and cur[1]+i<=n and vis[cur[0]+j-1][cur[1]+i-1]==0)
                        q.push({cur[0]+j,cur[1]+i}), vis[cur[0]+j-1][cur[1]+i-1] = 1;
                }
            }
        }
        return -1;
    }
};
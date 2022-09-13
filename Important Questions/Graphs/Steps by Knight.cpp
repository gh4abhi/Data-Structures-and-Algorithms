// Problem Link - https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1?page=1&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution 
{
    public:

    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
    {
        queue<vector<ll>> q;
        q.push(KnightPos);
        ll ans = 0;
        q.push({-1});
        vector<vector<ll>> vis(n+1,vector<ll>(n+1,0));
        vis[KnightPos[0]][KnightPos[1]] = 1;
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
                    return ans;
                q.push({-1});
                continue;
            }
            vector<vector<ll>> vect = {{-2,2},{-1,1}};
            for(auto i:vect[0])
            {
                for(auto j:vect[1])
                {
                    if(cur[0]+i>=1 and cur[0]+i<=n and cur[1] + j>=0 and cur[1]+j<=n and vis[cur[0]+i][cur[1]+j]==0)
                        q.push({cur[0]+i,cur[1]+j}), vis[cur[0]+i][cur[1]+j] = 1;
                    if(cur[0]+j>=1 and cur[0]+j<=n and cur[1] + i>=0 and cur[1]+i<=n and vis[cur[0]+j][cur[1]+i]==0)
                        q.push({cur[0]+j,cur[1]+i}), vis[cur[0]+j][cur[1]+i] = 1;
                }
            }
        }
        return ans;
    }
};
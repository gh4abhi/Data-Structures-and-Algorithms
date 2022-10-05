// Problem Link - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
        for(ll i=0;i<n+1;i++)
            dp[i][0] = 0;
        for(ll i=0;i<m+1;i++)
            dp[0][i] = 0;
        ll ans = 0;
        for(ll i=1;i<n+1;i++)
            for(ll j=1;j<m+1;j++)
                if(S1[i-1]==S2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1], ans = max(ans,dp[i][j]);
        return ans;
    }
};

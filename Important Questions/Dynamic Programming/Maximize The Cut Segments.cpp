// Problem Link - https://practice.geeksforgeeks.org/problems/cutted-segments1642/1?page=1&company[]=Amazon&category[]=Dynamic%20Programming&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<ll> dp(n+1,0);
        dp[0] = 0;
        for(ll i=1;i<=n;i++)
        {
            ll a = INT_MIN;
            ll b = INT_MIN;
            ll c = INT_MIN;
            if(i>=x)
                a = 1 + dp[i-x];
            if(i>=y)
                b = 1 + dp[i-y];
            if(i>=z)
                c = 1 + dp[i-z];
            dp[i] = max({a,b,c});
        }
        return max(0,dp[n]);
        
    }
};
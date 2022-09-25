// Problem Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?page=1&company[]=Amazon&category[]=Dynamic%20Programming&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int w[], int val[], int n) 
    { 
        vector<vector<ll>> dp(n+1,vector<ll>(W+1));
        for(ll i=0;i<W+1;i++)
            dp[n][i] = 0;
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=W;j>=0;j--)
            {
                dp[i][j] = dp[i+1][j];
                if(j>=w[i])
                    dp[i][j] = max(val[i] + dp[i+1][j-w[i]],dp[i][j]);
            }
        }
        return dp[0][W];
    }
};
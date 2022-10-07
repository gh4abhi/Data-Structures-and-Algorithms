// Problem Link - https://practice.geeksforgeeks.org/problems/coin-change2448/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll long long

class Solution {
  public:
    ll dp[1000][1000];
    ll find(int coins[], ll n, ll sum, ll ind)
    {
        if(sum==0)
            return 1;
        if(ind==n)
            return 0;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        ll ans = 0;
        if(sum>=coins[ind])
            ans += find(coins,n,sum-coins[ind],ind);
        ans += find(coins,n,sum,ind+1);
        return dp[ind][sum] = ans;
    }
  
    long long int count(int coins[], int N, int sum) {
        memset(dp,-1,sizeof(dp));
        return find(coins,N,sum,0);
    }
}; 
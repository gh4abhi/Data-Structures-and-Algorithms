// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/coin-change-permutations-official/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

int main()
{
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    ll target;
    cin>>target;
    
    vector<ll> dp(target+1,0);
    
    for(ll i=0;i<target+1;i++)
    {
        if(i==0)
        {
            dp[i] = 1;
            continue;
        }
        
        for(ll j=0;j<n;j++)
        {
            if(arr[j]<=i)
            {
            dp[i] += dp[i-arr[j]];
            }
        }
    }
    cout<<dp[target];
}


// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/coin-change-combination-official/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

int main()
{
    ll n;
    cin>>n;
    vector<ll> vect(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    
    ll amt;
    
    cin>>amt;
    
    ll dp[amt+1];
    for(ll i=0;i<amt+1;i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=vect[i];j<amt+1;j++)
        {
            if(dp[j-vect[i]]>0)
            {
                dp[j]+=dp[j-vect[i]]; 
            }
        }
    }
    cout<<dp[amt];
}




// Problem Link - https://nados.io/question/paint-house-many-colors

#include <iostream>
#include <bits/stdc++.h>
#define ll int
using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    int k ;
    cin>>k ;
    vector<vector<ll>> vect(n,vector<ll>(k,0));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<k;j++)
        {
            cin>>vect[i][j];
        }
    }
    if(k==1)
    {
     ll sum = 0;
     for(ll i=0;i<n;i++)
        sum+=vect[i][0];
     cout<<sum;
    }
    else
    {
    vector<ll> dp(k,0);

    ll mini = INT_MAX;
    ll sMini = INT_MAX;
    ll color = -1;

    for(ll j = 0; j<k;j++)
    {
        dp[j] = vect[0][j];
        if(dp[j]<mini)
        {
            color = j;
            sMini = mini;
            mini = dp[j];
        }
        else if(dp[j]<sMini)
        sMini = dp[j];
    }

    for(ll i=1;i<n;i++)
    {
        ll newMini = INT_MAX;
        ll newSMini = INT_MAX;
        ll newColor = color;
        for(ll j=0;j<k;j++)
        {
            if(j==color)
            dp[j] = vect[i][j] + sMini;
            else
            dp[j] = vect[i][j] + mini;
            if(dp[j]<newMini)
            {
                newColor = j;
                newSMini = newMini;
                newMini = dp[j];
            }
            else if(dp[j]<newSMini)
                newSMini = dp[j];    
        }
        mini = newMini;
        sMini = newSMini;
        color = newColor;
    }
ll ans = INT_MAX;
for(ll i=0;i<k;i++)
{
    ans = min(dp[i],ans);
}
cout<<ans;
    }
    return 0;
}

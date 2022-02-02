// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/maximum-sum-non-adjacent-elements-official/ojquestion

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
    ll inc, exc;
    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
            inc = vect[0];
            exc = 0;
            continue;
        }
        ll ninc = vect[i] + exc;
        ll nexc = max(inc,exc);
        inc = ninc;
        exc = nexc;
    }
    cout<<max(inc,exc);
}

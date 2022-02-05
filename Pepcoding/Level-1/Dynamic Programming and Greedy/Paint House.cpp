// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-official/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

int main()
{
    ll n;
    cin>>n;
    vector<ll> r(n), b(n), g(n);
    for(ll i=0;i<n;i++)
    {
        cin>>r[i]>>b[i]>>g[i];
    }
    
    ll red, blue, green;
    
    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
            red = r[i];
            blue = b[i];
            green = g[i];
            continue;
        }
        
        ll nRed = (r[i] + min(blue, green));
        ll nBlue = (b[i]+min(red, green));
        ll nGreen = (g[i]+min(red, blue));
        red = nRed;
        blue = nBlue;
        green = nGreen;
    }
    cout<<min(red,min(blue,green));
}

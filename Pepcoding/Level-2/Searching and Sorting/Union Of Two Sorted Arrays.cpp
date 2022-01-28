// Problem Link - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/union_of_two_sorted_arrays/ojquestion

#include<bits/stdc++.h>
#define ll int
#define pb push_back 

using namespace std;

int main()
{
    ll n,m;
    cin>>n;
    vector<ll> a(n);
    
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    vector<ll> b(m);
    for(ll j=0;j<m;j++)
    {
        cin>>b[j];
    }
    
    vector<ll> ans;
    
    ll i=0,j=0;
    
    while(i<n or j<m)
    {
        if(i==n and j<m)
        {
            while(j<m)
            {
                if(ans.size()==0 or (ans[ans.size()-1]!=b[j]))
                {
                    ans.pb(b[j]);
                }
                j++;
            }
            break;
        }
        
        if(j==m and i<n)
        {
            while(i<n)
            {
                if(ans.size()==0 or (ans[ans.size()-1]!=a[i]))
                {
                    ans.pb(a[i]);
                }
                i++;
            }
            break;
        }
        
        if(a[i]==b[j])
        {
            if(ans.size()==0 or (ans[ans.size()-1]!=a[i]))
            {
                ans.pb(a[i]);
            }
            i++;
            j++;
        }
        else if(a[i]<b[j])
        {
            if(ans.size()==0 or (ans[ans.size()-1]!=a[i]))
            {
                ans.pb(a[i]);
            }
            i++;
        }
        else if(a[i]>b[j])
        {
            if(ans.size()==0 or (ans[ans.size()-1]!=b[j]))
            {
                ans.pb(b[j]);
            }
            j++;
        }
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    
    return 0;
}

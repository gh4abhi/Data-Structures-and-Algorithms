// Problem Link - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/search_a_2d_matrix_ii/ojquestion

#include<bits/stdc++.h>
#define ll int
#define pb push_back 

using namespace std;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> vect(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>vect[i][j];
        }
    }
    
    ll val;
    cin>>val;
    
    ll r = 0, c = m-1;
    
    ll flag = 1;
    
    while(r<n and c>=0)
    {
        if(vect[r][c]==val)
        {
            cout<<"true";
            flag = 0;
            break;
        }
        else if(vect[r][c]>val)
        {
            c--;
        }
        else if(vect[r][c]<val)
        {
            r++;
        }
    }
    
    if(flag)
    {
        cout<<"false";
    }
    return 0;
}

// Problem Link - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/search_a_2d_matrix/ojquestion

#include<bits/stdc++.h>
#define ll int
#define pb push_back 

using namespace std;

ll findRow(vector<vector<ll>> vect, ll n, ll m, ll val)
{
    ll low = 0;
    ll high = n-1;
    
    while(low<=high)
    {
        ll mid = (low + high)/2;
        if(val>=vect[mid][0] and val<=vect[mid][m-1])
        {
            return mid;
        }
        else if(vect[mid][0]>val)
        {
            high = mid-1;
        }
        else if(vect[mid][0]<val)
        {
            low = mid+1;
        }
    }
    return -1;
}


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
    
    ll row = findRow(vect, n, m, val);
    

    
    ll flag = 1;
    
    if(row==-1)
    {
     cout<<"false";
     flag = 0;
    }
    
    ll low = 0;
    ll high = m-1;
    if(flag)
    while(low<=high)
    {
        ll mid = (low+high)/2;
        
        if(vect[row][mid]==val)
        {
            cout<<"true";
            flag = 0;
            break;
            
        }
        else if(vect[row][mid]>val)
        {
            high = mid-1;
        }
        else if(vect[row][mid]<val)
        {
            low = mid +1;
        }
    }
    if(flag)
    {
        cout<<"false";
    }
    return 0;
}

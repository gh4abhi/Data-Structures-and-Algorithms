#include <bits/stdc++.h>
#define SPEED  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define forl(n) for(ll i=0;i<n;i++)
#define prtIn(vect,i) cout<<vect[i]
#define vecs(vect,n) vector<ll> vect(n)
#define rev(v) reverse(v.begin(), v.end());
#define issorted(v) is_sorted(v.begin(),v.end())
#define prt1(a) cout<<a<<" ";
#define prt2(a,b) cout<<a<<" "<<b<<" ";
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define ll long long
#define vec  vector<ll>
#define pb push_back
#define pa vector<pair<ll,ll>>
#define fi first
#define se second
#define sz size()
#define full(a) a.begin(),a.end()
#define max_val INT_MIN
#define min_val INT_MAX;
#define MOD 1000000007
 
using namespace std;
 
void inOt()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}
 
bool isPwerOf2(ll x)
{
    return x && (!(x&(x-1)));
}
 
 
bool cmp(pair<char,ll> a, pair<char,ll> b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    return a.first>b.first;    
}
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll> vect(n);
    for(ll i=0;i<n;i++)
    vect[i] = i+1;
    
    vector<ll> temp = vect;
    temp[0] = 3;
    temp[1] = 1;
    temp[2] = 2;
    for(auto i:temp)
    cout<<i<<" ";
    cout<<endl;
    temp[0] = 3;
    temp[1] = 2;
    temp[2] = 1;
    for(auto i:temp)
    cout<<i<<" ";
    cout<<endl;
    ll k = n-2;
    ll i=0,j=n-1;
    while(k--)
    {
        if(i>=j)
        {
            i = 0;
            j = n-1;
        }
        swap(vect[i], vect[j]);
        i++;
        j--;
        for(auto r:temp)
            cout<<r<<" ";
            cout<<endl;
    }
}
 
int main()
{
    SPEED;
    #ifndef ONLINE_JUDGE
    inOt(); 
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
}
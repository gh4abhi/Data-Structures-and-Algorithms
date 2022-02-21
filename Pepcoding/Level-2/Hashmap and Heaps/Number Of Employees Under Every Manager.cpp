// Problem Link - https://nados.io/question/number-of-employees-under-every-manager?zen=true

#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
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

 
int main()
{
   ll n;
 cin>>n;
 map<char,ll> m;
 vector<pair<char,char>> vect;
 for(ll i=0;i<n;i++)
 {
   char a,b;
   cin>>a>>b;
   vect.push_back(make_pair(a,b));
   if(a!=b)
   m[b] += 1;
  } 
  char ceo;
  for(auto i:vect)
  {
    if(i.first!=i.second)
    m[i.second] += m[i.first];
    else
    ceo = i.second;
  }
  m[ceo] = n-1;
for(auto i:m)
{
  cout<<i.first<<" "<<i.second;
  cout<<endl;
}

  //Write your code here
  
return 0;
    
}
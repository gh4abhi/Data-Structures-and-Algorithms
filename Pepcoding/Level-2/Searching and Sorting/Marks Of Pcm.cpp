// Problem Link - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/marks_of_pcm/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

class toGetThree
{
  public:
  ll a;
  ll b;
  ll c;
  
  toGetThree()
  {
      this->a = 0;
      this->b = 0;
      this->c = 0;
  }
  
  toGetThree(ll a, ll b, ll c)
  {
      this->a = a;
      this->b = b;
      this->c = c;
  }
  
};

bool cmp(toGetThree one, toGetThree two)
{
    if(one.a != two.a)
    {
        return one.a<two.a;
    }
    
    if(one.b != two.b)
    {
        return one.b>two.b;
    }
    
    return one.c<two.c;
}

int main()
{
    ll n;
    cin>>n;
    vector<toGetThree> vect;
    
    vector<ll> a(n),b(n),c(n);
    
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>c[i];
    }
    
    for(ll i=0;i<n;i++)
    {
        vect.push_back(toGetThree(a[i],b[i],c[i]));
    }
        sort(vect.begin(), vect.end(), cmp);
        for(auto i:vect)
        {
            cout<<i.a<<" "<<i.b<<" "<<i.c<<endl;
        }
        
}

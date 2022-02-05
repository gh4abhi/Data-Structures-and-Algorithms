// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/fractional-knapsack-official/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

class contents
{
    public:
    
    ll val;
    ll we;
    double ratio;
    
    contents()
    {
        this->val = 0;
        this->we = 0;
        this->ratio = 0.0;
    }
    
    contents(ll val, ll we, double ratio)
    {
        this->val = val;
        this->we = we;
        this->ratio = ratio;
    }
};

bool cmp(contents a, contents b)
{
    return a.ratio > b.ratio; 
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> values(n);
    vector<ll> weights(n);
    
    for(ll i=0;i<n;i++)
    {
        cin>>values[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    
    ll cap;
    cin>>cap;
    
    vector<contents> fracKnap(n);
    
    for(ll i=0;i<n;i++)
    {
        double ratio = ((values[i])*1.0)/weights[i];
        fracKnap[i] = contents(values[i], weights[i],ratio);
    }
    
    sort(fracKnap.begin(),fracKnap.end(), cmp);
    
    double maxVal = 0.0;
    ll remCap = cap;
    
    for(ll i=0;i<n;i++)
    {
        if(remCap==0)
            break;
        if(remCap>=fracKnap[i].we)
        {
            remCap-=fracKnap[i].we;
            maxVal += fracKnap[i].val;
        }
        else
        {
            double currentVal = (1.0*(fracKnap[i].val*remCap))/fracKnap[i].we;
            maxVal+=currentVal;
            break;
        }
    }
    
    cout<<maxVal;
}

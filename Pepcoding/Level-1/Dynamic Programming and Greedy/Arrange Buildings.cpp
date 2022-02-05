// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/arrange-buildings-official/ojquestion

#include<bits/stdc++.h>
#define ll long long

using namespace std;

void its_Function(ll n)
{
    if(n==0)
    {
        cout<<0;
        return;
    }
    
    ll endS = 1;
    ll endB = 1;
    for(ll i=2;i<=n;i++)
    {
        ll temp = endS;
        endS += endB;
        endB = temp;
    }
    
    cout<<(endS+endB)*(endS+endB);
}

int main()
{
    ll n;
    cin>>n;
    its_Function(n);
}

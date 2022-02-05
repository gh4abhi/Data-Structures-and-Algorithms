// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

int main()
{
    ll n;
    cin>>n;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    ll endZero = 1;
    ll endOne = 1;
    for(ll i=2;i<=n;i++)
    {
        ll temp = endOne;
        endOne = endOne + endZero;
        endZero = temp;
    }
    cout<<(endZero+endOne);
}

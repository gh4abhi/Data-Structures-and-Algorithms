// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-a+b+c+subsequences-official/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

int main()
{
    string str;
    cin>>str;
    ll a = 0, ab = 0, abc = 0;
    for(ll i=0;i<str.length();i++)
    {
        if(str[i]=='a')
            a = 2*a + 1;
        else if(str[i]=='b')
            ab = 2*ab + a;
        else
            abc = 2*abc + ab;
    }
    cout<<abc;
}


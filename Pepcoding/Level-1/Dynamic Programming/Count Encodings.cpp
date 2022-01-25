// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-encodings-official/ojquestion

#include<bits/stdc++.h>
#define ll int

using namespace std;

void its_Function(string str)
{
    vector<ll> dp(str.length(),0);
    dp[0] = 1;
    for(ll i=1;i<str.length();i++)
    {
        if(str[i-1]=='0' and str[i]=='0')
        {
            dp[i] = 0;
        }
        else if(str[i-1]!='0' and str[i]=='0')
        {
            if(str[i-1]=='1' or str[i-1]=='2')
                dp[i] += i-2>=0?dp[i-2]:1;
        }
        else if(str[i-1]=='0' and str[i]!=0)
        {
            dp[i] = dp[i-1];
        }
        else
        {
            dp[i] = dp[i-1];
            ll num = stoi(str.substr(i-1,2));
            if(num<=26)
            {
                if(i-2>=0)
                dp[i]+=dp[i-2];
                else
                dp[i]+=1;
            }
            
        }
    }
    cout<<dp[str.length()-1];
}

int main()
{
    string str;
    cin>>str;
    its_Function(str);
}

// Problem Link - https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
  public:       
    int lps(string s) {
        ll n = s.length();
        vector<ll> prefix(n,0);
        ll ans = 0;
        for(ll i=1;i<n;i++)
        {
            ll j = prefix[i-1];
            while(j>0 and s[i]!=s[j])
                j = prefix[j-1];
            if(s[i]==s[j])
                j+=1;
            prefix[i] = j;
        }
        return prefix[n-1];
    }
};
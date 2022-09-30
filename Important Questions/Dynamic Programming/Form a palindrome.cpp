// Problem Link - https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Strings&sortBy=submissions

#define ll int

class Solution{   
public:
    ll dp[1000][1000];
    ll lcs(string &s1, string &s2, ll i, ll j)
    {
        if(i==s1.length() or j==s2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = 1 + lcs(s1,s2,i+1,j+1);
        return dp[i][j] = max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    }
    
    int findMinInsertions(string s){
        memset(dp,-1,sizeof(dp));
        ll n = s.length();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return n-lcs(s,s2,0,0);
    }
};
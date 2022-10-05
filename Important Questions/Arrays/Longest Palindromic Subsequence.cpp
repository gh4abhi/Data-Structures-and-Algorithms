// Problem Link - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?page=4&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
  public:
    ll dp[1000][1000];
    ll lcs(string str1, string str2, ll i, ll j)
    {
        if(i==str1.length() or j==str2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str1[i]==str2[j])
            return dp[i][j] = 1 + lcs(str1,str2,i+1,j+1);
        return dp[i][j] = max(lcs(str1,str2,i+1,j), lcs(str1,str2,i,j+1));
    }
    
    int longestPalinSubseq(string A) {
        memset(dp,-1,sizeof(dp));
        string temp = A;
        reverse(temp.begin(),temp.end());
        return lcs(A,temp,0,0);
    }
};

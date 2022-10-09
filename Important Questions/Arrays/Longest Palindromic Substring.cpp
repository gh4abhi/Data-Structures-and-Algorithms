// Problem Link - https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1?page=4&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{   
public:
    
    ll expand(string &S, ll start, ll end)
    {
        while(start>=0 and end<S.length())
        {
            if(S[start]!=S[end])
                break;
            start--;
            end++;
        }
        return end-start-1;
    }
    
    string longestPalindrome(string S){
        ll start=0,end=0;
        ll ans = 0;
        for(ll i=0;i<S.length()-1;i++)
        {
            ll len = max(expand(S,i,i),expand(S,i,i+1));
            if(len>ans)
            {
                ans = len;
                start = i - (len-1)/2;
                end = i+ (len)/2;
            }
        }
        return S.substr(start,end-start+1);
    }
};
// Problem Link - https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
    public:
    int longestUniqueSubsttr(string s){
        ll n = s.length();
        vector<ll> m(26,-1);
        ll ans = 0;
        ll start = 0;
        for(ll i=0;i<n;i++)
        {
            if(m[s[i]-'a']==-1 or m[s[i]-'a']<start)
                ans = max(ans,i-start+1);
            else
                start = m[s[i]-'a']+1;
             m[s[i]-'a'] = i;
        }
        return ans;
    }
};

// Problem Link - https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Strings&sortBy=submissions

#define ll int

class Solution
{
    public:
        
        void permutation(string &str, ll ind, string &s, ll n, map<string,ll> &m)
        {
            if(ind==n)
            {
                m[str]++;
                return;
            }
            for(ll i=0;i<n;i++)
            {
                if(str[i]=='$')
                {
                    str[i] = s[ind];
                    permutation(str,ind+1,s,n,m);
                    str[i] = '$';
                }
            }
        }
        
        vector<string>find_permutation(string s)
        {
            map<string,ll> m;
            ll n = s.length();
            string str = string(n,'$');
            permutation(str,0,s,n,m);
            vector<string> ans;
            for(auto i:m)
                ans.push_back(i.first);
            return ans;
        }
};
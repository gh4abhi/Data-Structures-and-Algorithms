// Problem Link - https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1?page=1&category[]=Strings&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       vector<ll> vis(26,0);
       for(auto i:S)
       {
           if(vis[i-'a']==1)
                vis[i-'a'] = 2;
            else if(vis[i-'a']==0)
                vis[i-'a'] = 1;
       }
       for(auto i:S)
        if(vis[i-'a']==1)
            return i;
       return '$';
    }
};
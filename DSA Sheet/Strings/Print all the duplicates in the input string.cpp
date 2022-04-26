#define ll int
class Solution{
public: 
    
    
    vector<char> printDuplicate(string S)
    {
       unordered_map<char,ll> m;
       for(auto i:S)
        m[i]++;
       vector<char> ans;
       for(auto i:m)
        if(i.second>1)
            ans.push_back(i.first);
       return ans; 
    }

};
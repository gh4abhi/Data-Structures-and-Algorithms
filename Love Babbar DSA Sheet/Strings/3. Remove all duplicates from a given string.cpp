// Problem Link - https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

#define ll int
class Solution{
public:
	string removeDuplicates(string str) {
	    map<char,ll> m;
	    string ans = "";
	    for(auto i:str)
	    {
	        if(m.count(i)==0)
	        {
	            ans+=i;
	            m[i]++;
	        }
	    }
	    return ans;
	}
};
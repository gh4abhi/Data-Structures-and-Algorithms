// Problem Link - https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

class Solution {
public:
    bool checkZeroOnes(string s) {
        long long c0=0,c1=0,cf1=INT_MIN,cf0=INT_MIN;
        for(auto i: s)
        {
            if(i=='1')
            {
                c0=0;
                c1++;
            }
            else
            {
                c1=0;
                c0++;
            }
            cf1 = max(cf1,c1);
            cf0 = max(cf0,c0);
        }
        
        return cf1>cf0;
    }
};

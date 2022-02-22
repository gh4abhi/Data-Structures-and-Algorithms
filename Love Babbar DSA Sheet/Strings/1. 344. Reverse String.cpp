// Problem Link - https://leetcode.com/problems/reverse-string/

#define ll int
class Solution {
public:
    void reverseString(vector<char>& s) {
        ll i=0, j = s.size()-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
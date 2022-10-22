// Problem Link - https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution {
  public:
    string findSum(string X, string Y) {
        string ans = "";
        ll i = X.length()-1;
        ll j = Y.length()-1;
        ll carry = 0;
        while(i>=0 or j>=0)
        {
            ll op = 0;
            if(i>=0)
                op += (X[i]-'0');
            if(j>=0)
                op += (Y[j]-'0');
            op += carry;
            carry = op/10;
            ll num = op%10;
            ans = to_string(num) + ans;
            i--;
            j--;
        }
        if(carry)
            ans = to_string(carry) + ans;
        ll k =0;
        while(k<ans.length() and ans[k]=='0')
            k++;
        if(k==ans.length())
            k--;
        return ans.substr(k,ans.length());
    }
};
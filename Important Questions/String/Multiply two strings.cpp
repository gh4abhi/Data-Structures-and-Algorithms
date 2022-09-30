// Problem Link - https://practice.geeksforgeeks.org/problems/multiply-two-strings/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       if(s1=="0" or s2=="0" or s1.length()==0 or s2.length()==0)
            return "0";
        if(s1=="1")
            return s2;
        if(s2=="1")
            return s1;
        ll e1 = 0, e2 = 0;
        if(s1[0]=='-')
            e1++;
        if(s2[0]=='-')
            e2++;
        ll m = s1.length();
        ll n = s2.length();
        string ans = string(n+m,'0');
        for(ll i=m-1;i>=e1;i--)
        {
            for(ll j=n-1;j>=e2;j--)
            {
                ll op = (s1[i]-'0')*(s2[j]-'0');
                op += (ans[i+j+1]-'0');
                ans[i+j+1] = ('0' + (op%10));
                ll ok = (ans[i+j]-'0');
                ok += op/10;
                ans[i+j] = ('0'+ok);
            }
        }
        ll i=0;
        while(ans[i]=='0')
            i++;
        string res = ans.substr(i,ans.length());
        if(e1 and e2)
            return res;
        if(e1 or e2)
            res = "-" + res;
        return res;
    }

};
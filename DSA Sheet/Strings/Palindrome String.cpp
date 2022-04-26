// Problem Link - https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

#define ll int
class Solution{
public: 
    
    
    int isPalindrome(string S)
    {
       ll i=0, j = S.length()-1;
       while(i<j)
       {
           if(S[i]!=S[j])
            return 0;
            i++;
            j--;
       }
       return 1;
    }

};
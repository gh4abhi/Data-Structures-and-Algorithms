// Problem Link - https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

#define ll int
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	   ll l = 0, r = S.length()-1;
	   while(l<r)
	   {
	       if(S[l]!=S[r])
	       return 0;
	       l++;
	       r--;
	   }
	   return 1;
	}

};
// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/target-sum-subsets-dp-official/ojquestion 

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define ll int
using namespace std;

void targetSumSubset(int n, vector<int> arr, int tar) {

ll dp[n+1][tar+1];
for(ll i=0;i<n+1;i++)
{
    for(ll j=0;j<tar+1;j++)
    {
        if(i==0 and j==0)
        {
            dp[i][j] = 1;
        }
        else if(i==0)
        {
            dp[i][j] = 0;
        }
        else if(j==0)
        {
            dp[i][j] = 1;
        }
        else 
        {
            if(dp[i-1][j]==1)
            {
                dp[i][j] = 1;
            }
            else
            {
                ll val = arr[i-1];
                if(j>=val)
                {
                    if(dp[i-1][j-val]==1)
                    {
                        dp[i][j] =1;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
}
if(dp[n][tar])
{
    cout<<"true";
    return;
}
cout<<"false";
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int tar;
  cin >> tar;
  targetSumSubset(n, arr, tar);

}

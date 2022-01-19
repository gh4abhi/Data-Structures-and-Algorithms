// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/zero-one-knapsack-official/ojquestion

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define ll int
using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

ll dp[n+1][cap+1];
for(ll i=0;i<n+1;i++)
{
    for(ll j=0;j<cap+1;j++)
    {
        if(i==0 or j==0)
        {
            dp[i][j] = 0;
            continue;
        }
        dp[i][j] = dp[i-1][j];
        if(j>=weight[i-1])
        {
           
                dp[i][j] = max(dp[i-1][j-weight[i-1]] + val[i-1],dp[i][j]);
            
        }
    }
}
cout<<dp[n][cap];
}

int main() {

  int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int cap;
  cin >> cap;

  zeroOneKnapsack(n, val, weight, cap);


}

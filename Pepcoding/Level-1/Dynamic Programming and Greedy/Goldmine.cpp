// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/goldmine-official/ojquestion

#include <bits/stdc++.h>
#define ll int

using namespace std;


int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    ll maxi = 0;
  for(ll j=m-1;j>=0;j--)
  {
      for(ll i=n-1;i>=0;i--)
      {
          if(j==m-1)
          {
              dp[i][j] = arr[i][j];
          }
          else if(i==0)
          {
              dp[i][j] = arr[i][j] + max(dp[i+1][j+1],dp[i][j+1]);
          }
          else if(i==n-1)
          {
              dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i-1][j+1]);
          }
          else
          {
              dp[i][j] = arr[i][j] + max(dp[i+1][j+1],max(dp[i-1][j+1],dp[i][j+1]));
          }
         if(j==0)
      {
       maxi = max(maxi,dp[i][j]);   
      }    
      }
     
  }
  return maxi;
}



int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, 0));

  cout << collectGold(n, m, arr, dp);

}

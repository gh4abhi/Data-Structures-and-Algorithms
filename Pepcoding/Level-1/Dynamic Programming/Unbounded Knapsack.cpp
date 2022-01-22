// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/unbounded-knapsack-official/ojquestion

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define ll int

using namespace std;

void unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

ll dp[cap+1];

dp[0] = 0;
for(ll i=1;i<cap+1;i++)
{
    dp[i] = 0;
    for(ll j=0;j<n;j++)
    {
        if(weight[j]<=i)
        {
            dp[i] = max(dp[i], dp[i-weight[j]] + val[j]);
        }
    }
}

cout<<dp[cap];

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

  unboundedKnapsack(n, val, weight, cap);


}

// Problem Link - https://nados.io/question/friends-pairing

// Backtracking Solution 
// In this all possible pairs are also diplayed.
/*#include<bits/stdc++.h>
#define ll int

using namespace std ;

    ll ans = 0;

    void friendsPairing(vector<bool>& visited, ll n, ll i, string way)
    {
      if(i>n)
      {
        cout<<way.substr(0,way.length()-1)<<endl;
        ans++;
        return;
      }
      if(visited[i]==true)
      {
        friendsPairing(visited,n,i+1,way);
      }
      else
      {
        visited[i] = true;
        string temp = "" + way + to_string(i)+"-";
        friendsPairing(visited,n,i+1,temp);
        for(ll j=i+1;j<=n;j++)
        {
          if(visited[j]==false)
          {
            visited[j] = true;
            string temp = "" + way + to_string(i) + to_string(j) + "-";
            friendsPairing(visited,n,i+1,temp);
            visited[j] = false;    
          }
        }
        visited[i] = false;
      }
    }

    int main() {
       int n ;
       cin>>n ;
      vector<bool> visited(n+1,false);
      friendsPairing(visited,n,1,"");
      cout<<ans;
   }*/
   
// DP Approach

#include<bits/stdc++.h>
#define ll int

using namespace std ;

    int main() {
       int n ;
       cin>>n ;
      ll dp[n+1];
      dp[1] = 1;
      dp[2] = 2;
      for(ll i=3;i<n+1;i++)
      {
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
      }
      cout<<dp[n];
   }

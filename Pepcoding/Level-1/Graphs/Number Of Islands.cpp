// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/graphs/count-islands-official/ojquestion

#include <bits/stdc++.h>
#define ll int

using namespace std;
void numIslandsHelper(vector<vector<bool>> &visited, ll i, ll j, ll n, ll m, vector<vector<int>>& grid)
    {
        visited[i][j] = true;
        if(i<n-1)
        {
            if(visited[i+1][j]==false and grid[i+1][j]==0)
                numIslandsHelper(visited, i+1, j, n , m, grid);
        }
        if(i>0)
        {
                if(visited[i-1][j]==false and grid[i-1][j]==0)
                numIslandsHelper(visited, i-1, j, n, m, grid);
        }   
        if(j<m-1)
        {
                if(visited[i][j+1]==false and grid[i][j+1]==0)
                numIslandsHelper(visited, i, j+1, n, m, grid);
        }
        
        if(j>0)
        {
                if(visited[i][j-1]==false and grid[i][j-1]==0)
                numIslandsHelper(visited, i, j-1, n, m, grid);    
        }
        }
        
    int numIslands(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        ll count = 0;
        
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    if(visited[i][j])
                        continue;
                    count++;
                    numIslandsHelper(visited, i, j, n, m , grid);
                }
            }
        }
        return count;
    }
    
int main()
{
  int n, m;
  cin >> n;
  cin >> m;

  vector<vector<int>> arr;

  for (int i = 0; i < n; i++)
  {
    vector<int> ans;
    for (int j = 0; j < m; j++)
    {
      int res;
      cin >> res;
      ans.push_back(res);
    }
    arr.push_back(ans);
  }
    
    cout<<numIslands(arr);
}

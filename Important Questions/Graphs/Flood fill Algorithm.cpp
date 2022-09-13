// Problem Link - https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

#define ll int

class Solution {
public:
    
    void DFS(vector<vector<int>> &image, ll i, ll j, ll newColor, ll color, ll m, ll n)
    {
        image[i][j] = newColor;
        vector<ll> vect = {1,-1};
        for(auto k:vect)
        {
            if(i+k>=0 and i+k<m and image[i+k][j]==color)
                DFS(image,i+k,j,newColor, color, m, n);
            if(j+k>=0 and j+k<n and image[i][j+k]==color)
                DFS(image,i,j+k,newColor, color, m, n);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      ll m = image.size();
      ll n = image[0].size();
      if(newColor==image[sr][sc])
        return image;
      DFS(image,sr,sc,newColor,image[sr][sc],m,n);
      return image;
    }
};
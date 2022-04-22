// Problem Link - https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#define ll int

void reverseArray(vector<int> &arr , int m)
{
    ll i = m+1, j = arr.size()-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

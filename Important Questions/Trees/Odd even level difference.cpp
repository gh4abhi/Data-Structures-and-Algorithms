// Problem Link - https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution{
  public:
    /*You are required to complete this function*/
    
    void DFS(Node* root, ll flag, ll &ev, ll &od)
    {
        if(root==nullptr)
            return;
        if(flag)
            od += root->data;
        else
            ev += root->data;
        DFS(root->left,!flag,ev,od);
        DFS(root->right,!flag,ev,od);
    }
    
    int getLevelDiff(Node *root)
    {
       ll ev = 0, od = 0;
       DFS(root,1,ev,od);
       return od-ev;
    }
};

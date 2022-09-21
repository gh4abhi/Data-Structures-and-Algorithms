// Problem Link - https://practice.geeksforgeeks.org/problems/two-mirror-trees/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int   
   
class Solution
{
    public:
    ll check(Node* a, Node* b)
    {
        if(a==nullptr and b==nullptr)
            return 1;
        if(!a or !b)
            return 0;
        if(a->data!=b->data)
            return 0;
        return check(a->left,b->right) and check(a->right,b->left);
    }
    int areMirror(Node* a, Node* b) {
        return check(a,b);
    }

};
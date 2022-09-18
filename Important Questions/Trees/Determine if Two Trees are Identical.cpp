// Problem Link - https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(!r1 and r2)
            return 0;
        if(r1 and !r2)
            return 0;
        if(!r1 and !r2)
            return 1;
        if(r1->data != r2->data)
            return 0;
        return isIdentical(r1->left, r2->left) and isIdentical(r1->right, r2->right); 
    }
};
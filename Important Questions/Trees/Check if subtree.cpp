// Problem Link - https://practice.geeksforgeeks.org/problems/check-if-subtree/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    
    bool check(Node* T, Node* S)
    {
        if(!T and S)
            return 0;
        if(T and !S)
            return 0;
        if(!T and !S)
            return 1;
        if(T->data != S->data)
            return 0;
        return check(T->left,S->left) and check(T->right,S->right);
    }
    
    bool DFS(Node* T, Node* S)
    {
        if(!T)
            return 0;
        if(T->data==S->data)
            if(check(T,S))
                return 1;
        return DFS(T->left,S) or DFS(T->right,S);
    }
    
    bool isSubTree(Node* T, Node* S) 
    {
        return DFS(T,S);
    }
};
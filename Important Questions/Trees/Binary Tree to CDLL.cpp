// Problem Link - https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1?page=4&company[]=Amazon&category[]=Tree&sortBy=submissions

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    
    Node* prev = nullptr;
    Node* head = nullptr;
    void DFS(Node* root)
    {
        if(root==nullptr)
            return;
        DFS(root->left);
        if(prev)
        {
            prev->right = root;
            root->left = prev;
        }
        else 
            head = root;
        prev = root;
        DFS(root->right);
    }
    
    Node *bTreeToCList(Node *root)
    {
        DFS(root);
        prev->right = head;
        head->left = prev;
        return head;
    }
};
// Problem Link - https://practice.geeksforgeeks.org/problems/expression-tree/1?page=3&company[]=Amazon&category[]=Tree&sortBy=submissions

class Solution{
  public:
    /*You are required to complete below method */
    
    string DFS(node* root)
    {
        string op = root->data;
        if(op=="+")
            return root->data = to_string(stoi(DFS(root->left)) + stoi(DFS(root->right)));
        else if(op=="-")
            return root->data = to_string(stoi(DFS(root->left)) - stoi(DFS(root->right)));
        else if(op=="*")
            return root->data = to_string(stoi(DFS(root->left)) * stoi(DFS(root->right)));
        else if(op=="/")
            return root->data = to_string(stoi(DFS(root->left)) / stoi(DFS(root->right)));
        else
            return root->data;
    }
    
    int evalTree(node* root) {
        return stoi(DFS(root));
    }
};
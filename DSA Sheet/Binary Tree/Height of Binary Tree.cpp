// Problem Link - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node==nullptr)
            return 0;
        return 1 + max(height(node->right),height(node->left));
    }
};
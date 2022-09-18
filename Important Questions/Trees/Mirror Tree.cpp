// Problem Link - https://practice.geeksforgeeks.org/problems/mirror-tree/1

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        if(root==nullptr)
            return;
        mirror(root->left);
        mirror(root->right);
        Node* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }
};
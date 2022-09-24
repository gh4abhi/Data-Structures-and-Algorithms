// Problem Link - https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       Node* nex = del->next;
       swap(nex->data,del->data);
       del->next = nex->next;
    }

};
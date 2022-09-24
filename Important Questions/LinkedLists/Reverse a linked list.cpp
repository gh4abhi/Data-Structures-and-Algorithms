// Problem Link - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* prev = nullptr;
        Node* cur = head;
        while(cur)
        {
            Node* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    
};
// Problem Link - https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node* fast = head;
        Node* slow = head;
        while(fast and fast->next)
            fast = fast->next->next, slow = slow->next;
        return slow->data;
    }
};

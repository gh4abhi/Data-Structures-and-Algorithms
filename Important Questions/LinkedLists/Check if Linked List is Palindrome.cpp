// Problem Link - https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

#define ll int

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* fast = head;
        Node* slow = head;
        if(head==nullptr or head->next==nullptr)
            return 1;
        while(fast->next and fast->next->next)
            fast = fast->next->next, slow = slow->next;
        Node* prev = nullptr;
        Node* cur = slow->next;
        while(cur)
        {
            Node* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        slow = prev;
        fast = head;
        while(fast and slow)
        {
            if(fast->data != slow->data)
                return 0;
            slow = slow->next;
            fast = fast->next;
        }
        return 1;
    }
};

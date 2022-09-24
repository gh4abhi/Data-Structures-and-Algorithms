// Problem Link - https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* fast = head;
        Node* slow = head;
        while(fast and fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
                if(fast==slow)
                    break;
            }
        if(fast==nullptr or fast->next==nullptr)
            return;
        Node* temp = head;
        Node* op = fast;
        if(temp==fast)
            {
                while(fast->next!=temp)
                    fast = fast->next;
                fast->next = nullptr;
                return;
            }
        fast = fast->next;
        temp = temp->next;
        while(fast!=temp)
            fast = fast->next, temp = temp->next, op = op->next;
        op->next = nullptr;
    }
};
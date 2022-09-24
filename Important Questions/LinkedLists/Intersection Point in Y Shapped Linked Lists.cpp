// Problem Link - https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    if(!head1 or !head2)
        return -1;
    Node* l1 = head1, *l2 = head2;
    while(l1!=l2)
    {
        if(l1==nullptr)
            l1 = head2;
        else
            l1 = l1->next;
        if(l2==nullptr)
            l2 = head1;
        else
            l2 = l2->next;
    }
    if(!l2)
        return -1;
    return l2->data;
}
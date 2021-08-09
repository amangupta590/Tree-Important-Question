//Convert Sorted Doubly Linked List To Binary Search Tree

Node *midpoint(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast->right!=NULL and fast->right->right!=nullptr){
        slow=slow->right;
        fast=fast->right->right;
    }
    return slow;
}
Node *SortedDLLToBS(Node* head){
    if(head==NULL or head->right==NULL)
        return head;
    Node *mid=midpoint(head);
    Node *root=mid;
    Node *prev=root->left;
    Node *forw=root->right;
    root->right=NULL;
    if(prev)    prev->right=NULL;
    forw->left=NULL;
    root->left=NULL;
    Node* lefthead=(prev!=NULL)?head:nullptr;
    root->left=SortedDLLToBS(lefthead);
    root->right=SortedDLLToBS(forw);
    return root;
}

//
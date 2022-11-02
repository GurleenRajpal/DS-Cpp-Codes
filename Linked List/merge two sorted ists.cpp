Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node* newList = NULL;
    if(head1==NULL && head2!=NULL){
        return head2;
    }
    if(head1!=NULL && head2==NULL){
        return head1;
    }
    if(head1==NULL && head2==NULL){
        return NULL;
    }
    if(head1->data <= head2->data){
        newList = head1;
        head1 = head1->next;
    }
    else{
        newList = head2;
        head2 = head2->next;
    }
    Node* temp = newList;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            temp->next = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if(head1!=NULL){
        temp->next = head1;
    }
	if(head2!=NULL){
        temp->next = head2;
    }
    return newList;
}

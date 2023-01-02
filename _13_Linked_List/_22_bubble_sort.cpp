//  Bubble Sort (Iterative) LinkedList
// Send Feedback
// Given a singly linked list of integers, sort it using 'Bubble Sort.'
// Note :

// No need to print the list, it has already been taken care. Only return the new head to the list.

// Input format :

// The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

// Remember/Consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format :

// For each test case/query, print the elements of the sorted singly linked list.

// Output for every test case will be printed in a seperate line.

// Constraints :

// 0 <= M <= 10^3
// Where M is the size of the singly linked list.

// Time Limit: 1sec

// Sample Input 1 :

// 10 9 8 7 6 5 4 3 -1

// Sample Output 1 :

//  3 4 5 6 7 8 9 10 

//  Sample Input 2 :

// 10 -5 9 90 5 67 1 89 -1

// Sample Output 2 :

// -5 1 5 9 10 67 89 90 



void swapNodes(Node* a, Node* b, Node* c) {
   if (a != NULL)
       a->next = c;
   b->next = c->next;
   c->next = b;
}

Node *bubbleSort(Node *head)
{
	// Write your code here
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    if(head==NULL){
        return head;
    }
    Node* temp1 = head;
    Node* temp2 = head;
    Node* prev = NULL;
    for(int i=0;i<len-1;i++){
        prev = NULL;
        temp1 = head;
        temp2 = head->next;
        while(temp2){
            if((temp1->data)>(temp2->data)){
                swapNodes(prev, temp1, temp2);
                if(prev==NULL){
                    head = temp2;
                }
                prev = temp2;
                temp2 = temp1->next;
            }else{
                prev = temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            // cout<<temp1->data<<endl;
            // cout<<temp2->data<<endl;
        }
    }
    return head;
    
}

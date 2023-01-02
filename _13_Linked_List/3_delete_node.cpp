//  Delete node
// Send Feedback
// You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
// Note :

// Assume that the Indexing for the linked list always starts from 0.

// If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.

// The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the linked list separated by a single space. 

// The second line of each test case contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.

//  Remember/Consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format :

// For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

// Output for every test case will be printed in a separate line.

// Note:

// You are not required to print the output, it has already been taken care of. Just implement the function. 

// Constraints :

// 1 <= T <= 10^2
// 0 <= N <= 10^5
// POS >= 0

// Time Limit: 1sec

// Sample Input 1 :

// 1 
// 3 4 5 2 6 1 9 -1
// 3

// Sample Output 1 :

// 3 4 5 6 1 9
int length(Node* head){
    if(head==NULL){
        return 0;
    }
    return 1 + length(head->next);
}
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head==NULL){
        return head;
    }
    Node* temp = head;
    if(pos==0){
        head = head->next;
        delete temp;
        return head;
    }
    int i = 0;
    int len = length(head);
    if(pos>=len){
        return head;
    }
    Node* prev = NULL;
    while(i<pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    delete temp;
    return head;
    
}


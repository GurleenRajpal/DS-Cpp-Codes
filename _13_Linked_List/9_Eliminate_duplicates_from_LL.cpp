//  Eliminate duplicates from LL
// Send Feedback
// You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes 
// the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
//  Input format :

// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.

//  Remember/Consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

//  Output format :

// For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

// Output for every test case will be printed in a seperate line.

// Constraints :

// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Time Limit: 1sec

// Where 'M' is the size of the singly linked list.

// Sample Input 1 :

// 1
// 1 2 3 3 3 3 4 4 4 5 5 7 -1

// Sample Output 1 :

// 1 2 3 4 5 7 

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head==NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    Node* temp2;
    temp = temp->next;
    prev = head;
    if(temp==NULL){
        return head;
    }

    while(temp){
        if(temp->data==prev->data){
            temp2 = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete temp2;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}


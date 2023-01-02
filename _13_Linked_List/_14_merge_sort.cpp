//  Code: Merge Sort
// Send Feedback
//  Given a singly linked list of integers, sort it using 'Merge Sort.'
// Note :

// No need to print the list, it has already been taken care. Only return the new head to the list.

// Input format :

// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

// Remember/Consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format :

// For each test case/query, print the elements of the sorted singly linked list.

// Output for every test case will be printed in a seperate line.

// Constraints :

// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.

// Time Limit: 1sec

// Sample Input 1 :

// 1
// 10 9 8 7 6 5 4 3 -1

// Sample Output 1 :

//  3 4 5 6 7 8 9 10 

#include<iostream>
using namespace std;
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node* newList = NULL;
    if(head1 && !head2){
        return head1;
    }
    if(!head1 && head2){
        return head2;    
    }
    if(!head1 && !head2){
        return NULL;
    }
    Node* temp;
    while(head1 && head2){
        if(head1->data<=head2->data){
            //Node* newNode = new Node(head1->data);
            if(!newList){
                newList = head1;
                temp = head1;
            }
            else{
                temp->next = head1;
                temp = temp->next;
            }
            head1 = head1->next;
        }
        else{
            //Node* newNode = new Node(head2->data);
            if(!newList){
                newList = head2;
                temp = head2;
            }
            else{
                temp->next = head2;
                temp = temp->next;
            }
            head2 = head2->next;
        }
    }
    if(head1){
        temp->next = head1;
    }
    if(head2){
        temp->next = head2;
    }
    return newList;
}

Node *mergeSort(Node *head)
{
	//Write your code here
    if(head == NULL || head->next==NULL){
        return head;
    }
    
    Node* slow = head;
    Node* fast = head;
    Node* prev = head;
    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    //slow->next = NULL;
    prev->next = NULL;
    Node* temp1 = mergeSort(head);
    Node* temp2 = mergeSort(slow);
    // cout<<temp1->data<<endl;
    // cout<<temp2->data<<endl;
    // cout<<prev->data<<endl;
    // temp1 = mergeSort(temp1);
    // temp2 = mergeSort(temp2);
    
    Node* temp = mergeTwoSortedLinkedLists(temp1, temp2);
    
    return temp;
    
}

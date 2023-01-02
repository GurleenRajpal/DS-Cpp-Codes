//  Delete every N nodes
// Send Feedback
// You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
// To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
// Note :

// No need to print the list, it has already been taken care. Only return the new head to the list.

// Input format :

// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the singly linked list separated by a single space.

// The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.

//  Remember/Consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format :

// For each test case/query, print the elements of the updated singly linked list.

// Output for every test case will be printed in a seperate line.

// Constraints :

// 1 <= t <= 10^2
// 0 <= P <= 10^5
// Where P is the size of the singly linked list.
// 0 <= M <= 10^5
// 0 <= N <= 10^5 

// Time Limit: 1sec

// Sample Input 1 :

// 1
// 1 2 3 4 5 6 7 8 -1
// 2 2

// Sample Output 1 :

// 1 2 5 6

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head==NULL || M==0){
        return NULL;
    }
    if(N==0){
        return head;
    }
    Node* temp = head;
    while(temp!=NULL){
        //skip m nodes delete n nodes
        //10    22 10   26 11 7 8 1 23 5 1 -1
        //2     1  k3   k2 k1 k 
        //2 3
        int i = M;
        int j = N;
        Node* prev = NULL;
        while(i>0 && temp!=NULL){
            prev = temp;
            temp = temp->next;
            i--;
        }
        // cout<<prev->data<<endl;
        Node* k = temp;
        while(j>0 && k!=NULL){
            k = k->next;
            j--;
        }
        prev->next = k;
        temp = k;
    }
    return head;
}

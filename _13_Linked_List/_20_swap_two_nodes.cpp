//  Swap two Nodes of LL
// Send Feedback
// You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
// Note :

// Remember, the nodes themselves must be swapped and not the datas.

// No need to print the list, it has already been taken care. Only return the new head to the list.

// Input format :

// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the singly linked list separated by a single space.

// The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

//  Remember/consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format :

// For each test case/query, print the elements of the updated singly linked list.

// Output for every test case will be printed in a seperate line.

// Constraints :

// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.
// 0 <= i < M
// 0 <= j < M

// Time Limit: 1sec

// Sample Input 1 :

// 1
// 3 4 5 2 6 1 9 -1
// 3 4

// Sample Output 1 :

// 3 4 5 6 2 1 9 

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(head==NULL){
        return NULL;
    }
    
    if(i==j){
        return head;
    }
    
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    if(i>=len || j>=len){
        return head;
    }
    
    Node* temp1 = head;
    Node* temp2 = head;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    Node* temp3 = NULL;
    // 0 1 2 13 4 5
    int l1 = i;
    int l2 = j;
    
    while(l1>0){//2>0 1>0 
        prev1 = temp1;
        temp1 = temp1->next;
        l1--;
    }
    while(l2>0){
        prev2 = temp2;
        temp2 = temp2->next;
        l2--;
    }
    // cout<<temp1->data<<endl;
    // cout<<temp2->data<<endl;
    if(i==0){
        prev2->next = temp1;
        temp3 = temp2->next;
        temp2->next = temp1->next;
        temp1->next = temp3;
        head = temp2;
        return head;
    }
    else if(j==0){
        prev1->next = temp2;
        temp3 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp3;
        head = temp1;
        return head;
    }
    else{
        prev2->next = temp1;
        temp3 = temp2->next;
        temp2->next = temp1->next;
        prev1->next = temp2;
        temp1->next = temp3;
        return head;
    }
    
}

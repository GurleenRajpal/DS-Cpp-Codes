//  Palindrome LinkedList
// Send Feedback
// You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
//  Input format :

// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.

//  Remember/Consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

//  Output format :

// For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

//  Constraints :

// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Time Limit: 1sec

// Where 'M' is the size of the singly linked list.

// Sample Input 1 :

// 1
// 9 2 3 3 2 9 -1

// Sample Output 1 :

// true

bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL){
        return true;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //reverse from slow
    Node* temp = slow;
    Node* prev = NULL;
    Node* nextNode = temp;
    
    while(temp!=NULL){
    	nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    slow = prev;
    
    Node* temp2 = head;
    while(temp2!=NULL && slow!=NULL){
        if(temp2->data!=slow->data){
            return false;
        }
        temp2 = temp2->next;
        slow = slow->next;
    }
    
    return true;
    
}

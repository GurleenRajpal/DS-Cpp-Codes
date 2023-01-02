//  Even after Odd LinkedList
// Send Feedback
// For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
// Note :

// No need to print the list, it has already been taken care. Only return the new head to the list.

// Input format:

// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

//  Remember/Consider :

// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format:

// For each test case/query, print the elements of the updated singly linked list.

// Output for every test case will be printed in a seperate line.

// Constraints :

// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.

// Time Limit: 1sec

// Sample Input 1 :

// 1
// 1 4 5 2 -1

// Sample Output 1 :

// 1 5 4 2 

Node *evenAfterOdd(Node *head)
{
	//write your code here
    Node* temp = head;
    Node* odd = NULL;
    Node* even = NULL;
    Node* tempOdd = NULL;
    Node* tempEven = NULL;
    if(head==NULL || head->next==NULL){
        return head;
    }
    while(temp!=NULL){
        if((temp->data%2)==0){
            if(even==NULL){
                even = temp;
                tempEven = even;
            }
            else{
                tempEven->next = temp;
                tempEven = tempEven->next;
            }
            //tempEven->next = NULL;
            temp = temp->next;
        }
        else{
            if(odd==NULL){
                odd = temp;
                tempOdd = odd;
            }
            else{
                tempOdd->next = temp;
                tempOdd = tempOdd->next;
            }
            //tempOdd->next = NULL;
            temp = temp->next;
        }
    }
    if(tempOdd!=NULL){
    	tempOdd->next = NULL;
    }
    if(tempEven!=NULL){
    	tempEven->next = NULL;
    }
    if(even==NULL && odd==NULL){
        return NULL;
    }
    else if(even==NULL && odd!=NULL){
        tempOdd->next = NULL;
        return odd;
    }
    else if(odd==NULL && even!=NULL){
        tempEven->next = NULL;
        return even;
    }
    else{
    	tempOdd->next = even;   
        return odd;
    }
    //temp2->next = NULL;
//     if(odd==NULL){
        
//     }
//     else{
//    		tempEven->next = NULL;
//  		return odd;
//     }
    
}

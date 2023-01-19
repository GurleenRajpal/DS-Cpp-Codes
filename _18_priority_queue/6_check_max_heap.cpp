//  Check Max-Heap
// Send Feedback
// Given an array of integers, check whether it represents max-heap or not. 
// Return true if the given array represents max-heap, else return false.
// Input Format:

// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.

// Output Format :

// The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.

// Constraints:

// 1 <= N <= 10^5
// 1 <= Ai <= 10^5
// Time Limit: 1 sec

// Sample Input 1:

// 8
// 42 20 18 6 14 11 9 4

// Sample Output 1:

// true

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    int parentIndex = 0 ;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    int maxIndex = parentIndex;
    int i = 0;
    bool choice1=false, choice2=false;
    while(leftChildIndex<n){
        
        if(arr[parentIndex]>arr[leftChildIndex]){
            choice1 = true;
        }
        else{
            choice1 = false;
        }
        
        
        if(rightChildIndex>=n){
        	choice2 = true;    
        }
        else if(arr[rightChildIndex]<arr[parentIndex] && rightChildIndex<n){
            choice2 = true;
        }
        else{
            choice2 = false;
        }
        
        if(!choice1 || !choice2){
        	return false;    
        }
        
        parentIndex++;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
        
    }
    
    return true;
}

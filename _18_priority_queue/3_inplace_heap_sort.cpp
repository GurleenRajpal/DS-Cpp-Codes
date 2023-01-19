//  Code : In-place heap sort
// Send Feedback
// Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
// Note: Space complexity should be O(1).
// Input Format:

// The first line of input contains an integer, that denotes the value of the size of the array or N.
// The following line contains N space separated integers, that denote the value of the elements of the array.

// Output Format :

// The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.

// Constraints :

// 1 <= n <= 10^6
// Time Limit: 1 sec

// Sample Input 1:

// 6 
// 2 6 8 5 4 3

// Sample Output 1:

// 8 6 5 4 3 2


#include<vector>
void makeHeap(int arr[], int n){
    int childIndex = 1;
    int parentIndex;
    for(int i=1;i<n;i++){
        childIndex = i;
        while(childIndex>0){
            parentIndex = (childIndex-1)/2;
            if(arr[childIndex]<arr[parentIndex]){
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    return;
    
}
void remove(int arr[], int n){
    if(n==1){
        return;
    }
    int temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;
    
    // compare and swap till n-2
    
    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    int minIndex;
    
    while(leftChildIndex<n-1){
        minIndex = parentIndex;
        if(arr[leftChildIndex]<arr[minIndex]){
            minIndex = leftChildIndex;
        }
        if(arr[rightChildIndex]<arr[minIndex] &&  rightChildIndex<n-1){
            minIndex = rightChildIndex;
        }
        if(minIndex == parentIndex) break;
        
        int temp = arr[parentIndex];
        arr[parentIndex] = arr[minIndex];
        arr[minIndex] = temp;
        
        parentIndex = minIndex;
        
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
        
    }
    remove(arr, n-1);
    
}
void heapSort(int arr[], int n) {
    // Write your code
    if(n==0 || n==1){
        return;
    }
    makeHeap(arr, n);
    remove(arr, n);
}

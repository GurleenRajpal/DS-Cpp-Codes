// Rotate array
// Send Feedback
// You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
//  Note:
// Change in the input array/list itself. You don't need to return or print the elements.

void rotate(int *input, int d, int n)
{
    //Write your code here
    int arr[d];
    for(int i=0;i<d;i++){
        arr[i] = input[i];
    }
    for(int i=0; i<n; i++){
        input[i] = input[d+i];
    }
    for(int i=n-d, j=0;i<n, j<d;i++, j++){
        input[i] = arr[j];
    }
}

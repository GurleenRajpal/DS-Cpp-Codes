//  Duplicate in array
// Send Feedback
// You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
// Note :

// Duplicate number is always present in the given array/list.

// Input format :

// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Output Format :

// For each test case, print the duplicate element in the array/list.

// Output for every test case will be printed in a separate line.

// Constraints :

// 1 <= t <= 10^2
// 0 <= N <= 10^6

// Time Limit: 1 sec

// Sample Input 1:

// 1
// 9
// 0 7 2 5 4 7 1 3 6

// Sample Output 1:

// 7

void merge(int* arr, int si, int mid, int ei){
    int l1 = mid-si+1;
    int l2 = ei-mid;
    
    int* arr1 = new int[l1];
    int* arr2 = new int[l2];
    
    for(int i=0;i<l1;i++){
        arr1[i] = arr[si+i];
    }
    
    for(int j=0; j<l2; j++){
        arr2[j] = arr[mid+1+j];
    }
    
    int i = 0, j=0, k=si;
    
    while(i<l1 && j<l2){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    while(i<l1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<l2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
    delete[] arr1;
    delete[] arr2;
    
}

void mergeSort(int* arr, int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, mid, ei);
    
    
}

int findDuplicate(int *arr, int n)
{
    //Write your code here
    mergeSort(arr,0, n-1);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<n-1;i=i+1){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
}

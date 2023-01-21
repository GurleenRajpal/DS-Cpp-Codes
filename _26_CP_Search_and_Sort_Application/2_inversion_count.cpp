// Inversion Count
// Send Feedback
// For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]' 
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').
// Input format :
// The first line of input contains an integer 'N', denoting the size of the array.

// The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
// Output format :
// Print a single line containing a single integer that denotes the total count of inversions in the input array.
// Note:
// You are not required to print anything, it has been already taken care of. Just implement the given function.  
// Constraints :
// 1 <= N <= 10^5 
// 1 <= ARR[i] <= 10^9

// Where 'ARR[i]' denotes the array element at 'ith' index.

// Time Limit: 1 sec
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation of Sample Output 1:
// We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
// Sample Input 2 :
// 5
// 2 5 1 3 4
// Sample Output 2 :
// 4
// Explanation of Sample Output 1:
// We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).

#include <iostream>
using namespace std;
#include <bits/stdc++.h> 

long long merge(long long *arr, int si, int mid, int ei){
    long long i = si;
    long long j = mid+1;
    long long inversions = 0;
    long long *newArr = new long long[ei-si+1];
    long long k = 0;
    long long len = mid-si+1;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            newArr[k] = arr[i];
            i++;
            k++;
        }
        else{
            newArr[k] = arr[j];
            inversions+=mid+1-i;
            j++;
            k++;
        }
    }
    while(i<=mid){
        newArr[k] = arr[i];
        i++;
        k++;
    }
    while(j<=ei){
        newArr[k] = arr[j];
        j++;
        k++;
    }
    
    i = si;
    k = 0;
    
    while(i<=ei){
        arr[i] = newArr[k];
        i++;
        k++;
    }
    
    delete [] newArr;
    
    return inversions;
}


long long helper(long long *arr,int si,int ei){
    if(si>=ei){
        return 0;
    }
    int mid = si + (ei-si)/2;
    long long left  = helper(arr, si, mid);
    long long right = helper(arr, mid+1, ei);
    
    long long k = merge(arr, si, mid, ei);
    
    return left+right+k;
    
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans = 0;
    
    long long inversions = helper(arr, 0, n-1);
    
    return inversions;
    
}


int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}

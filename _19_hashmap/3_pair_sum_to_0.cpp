//  Code : Pair Sum to 0
// Send Feedback
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.
// Input format:

// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.

// Output format :

// The first and only line of output contains the count of pair of elements in the array which sum up to 0. 

// Constraints :

// 0 <= N <= 10^4
// Time Limit: 1 sec

// Sample Input 1:

// 5
// 2 1 -2 2 3

// Sample Output 1:

// 2

#include <iostream>
#include<unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    int count = 0;
    for(int i=0;i<n;i++){
        
        if(mp[-1*arr[i]]>0 && arr[i]!=0){
            count+=mp[-1*arr[i]];
        }
    }
    if(mp[0]>1){
        count+=(mp[0]*(mp[0]-1));
    }
    return count/2;
}




int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}

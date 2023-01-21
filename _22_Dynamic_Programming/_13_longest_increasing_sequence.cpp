//  Longest Increasing Subsequence
// Send Feedback
// Given an array with N elements, you need to find the length of the longest subsequence in the 
// given array such that all elements of the subsequence are sorted in strictly increasing order.
// Input Format

// The first line of input contains an integer N. The following line contains N space separated 
// integers, that denote the value of elements of array.

// Output Format

// The first and only line of output contains the length of longest subsequence.

// Constraints

// 1 <= N <= 10^3
// Time Limit: 1 second

// Sample Input 1 :

// 6
// 5 4 11 1 16 8

// Sample Output 1 :

// 3

// Sample Output Explanation

// Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

// Sample Input 2 :

// 3
// 1 2 2

// Sample Output 2 :

// 2


#include <iostream>
using namespace std;
#include<vector>
int helper(int* arr, int n, int index, int prev_index, vector< vector<int> >& dp){
    if(index>=n){
        return 0;
    }
    if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];
    int pick = 0;
    if(prev_index==-1 || arr[index]>arr[prev_index]){
    	pick = 1 + helper(arr, n, index+1, index, dp);
    }
        
	int notPick = helper(arr, n, index+1, prev_index, dp);
    
    // dp[index]=max(pick, notPick);
    
    return dp[index][prev_index+1] = max(pick, notPick);
}
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    return helper(arr, n, 0, -1, dp);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}

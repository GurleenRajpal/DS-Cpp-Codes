// Code : No. of balanced BTs using DP
// Send Feedback
// Given an integer h, find the possible number of balanced binary trees of height h. You 
// just need to return the count of possible binary trees which are balanced.
// This number can be huge, so, return output modulus 10^9 + 7.
// Time complexity should be O(h).
// Input Format :
// The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
// Output Format :
// The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
// Constraints :
// 1 <= h <= 10^6
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315

int balancedBTs(int n) {
    // Write your code here
    long long int mod = 1e9+7;
    
    int* dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        int x = dp[i-1];
        int y = dp[i-2];
        dp[i] = (x%mod*x%mod + 2*x%mod*y%mod)%mod;
    }
    return dp[n];
}

// Adjacent Bit Counts
// Send Feedback
// For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
// X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
// which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
// AdjBC(011101101) = 3
// AdjBC(111101101) = 4
// AdjBC(010101010) = 0
// Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) 
// that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
// 11100, 01110, 00111, 10111, 11101, 11011
// Input Format:
// First-line will contain T(number of the test case).
// Each test case consists of a single line containing two space-separated integers N and K, a number of bits in the bit 
// strings and desired adjacent bit count respectively.
// Output Format:
// For each test case print the answer in a new line.
// As answer can be very large print your answer modulo 10^9+7.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= K <= 100
// Sample Input
// 10
// 5 2
// 20 8
// 30 17
// 40 24
// 50 37
// 60 52
// 70 59
// 80 73
// 90 84
// 100 90
// Sample Output
// 6
// 63426
// 1861225
// 168212501
// 44874764
// 160916
// 22937308
// 99167
// 15476
// 23076518

#include <bits/stdc++.h>
using namespace std;
 
long long countStrings(int n, int k)
{
    // dp[i][j][0] stores count of binary
    // strings of length i with j consecutive
    // 1's and ending at 0.
    // dp[i][j][1] stores count of binary
    // strings of length i with j consecutive
    // 1's and ending at 1.
    int m = 1e9+7;
    long long dp[n + 1][k + 1][2];
    memset(dp, 0, sizeof(dp));
 
    // If n = 1 and k = 0.
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
 
    for (int i = 2; i <= n; i++) {
 
        // number of adjacent 1's can not exceed i-1
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1])%m;
            dp[i][j][1] = (dp[i - 1][j][0])%m;
 
            if (j - 1 >= 0)
                dp[i][j][1] = (dp[i][j][1]%m + dp[i - 1][j - 1][1]%m)%m;
        }
    }
 
    return (dp[n][k][0]%m + dp[n][k][1]%m)%m;
}
 
// Driver code
int main()
{
    int t;
    cin>>t;
     int m = 1e9+7;
    long long dp[101][101][2];
    memset(dp, 0, sizeof(dp));
 
    // If n = 1 and k = 0.
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
 
    for (int i = 2; i <= 100; i++) {
 
        // number of adjacent 1's can not exceed i-1
        for (int j = 0; j <= 100; j++) {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1])%m;
            dp[i][j][1] = (dp[i - 1][j][0])%m;
 
            if (j - 1 >= 0)
                dp[i][j][1] = (dp[i][j][1]%m + dp[i - 1][j - 1][1]%m)%m;
        }
    }
    while(t--){
        int n, k;
        cin>>n>>k;
        cout << (dp[n][k][0]%m + dp[n][k][1]%m)%m<<endl;
    }
    
    return 0;
}

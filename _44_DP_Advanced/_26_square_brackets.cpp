// Square Brackets
// Send Feedback
// You are given:
// a positive integer n,
// an integer k, 1<=k<=n,
// an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
// What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
// Illustration
// Several proper bracket expressions:
// [[]][[[]][]] 
// [[[][]]][][[]]
// An improper bracket expression:
// [[[][]]][]][[]]
// There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
// Task
// Write a program which for each data set from a sequence of several data sets:
// 1. reads integers n, k and an increasing sequence of k integers from input,
// 2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
// 3. writes the result to output.
// Note: since result can be pretty large output the answer % mod (10^9 + 7).
// Input Format:
// The first line of the input file contains one integer T(number of test cases), each test case follows as.
// The first line contains two integers n and k separated by single space.
// The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
// Output Format:
//  For each test case print the number of balanced square bracket sequence % mod (10^9 + 7), that can be formed using the above rules in a new line.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 100
// 1 <= K <= N
// Sample Input
// 5 
// 1 1 
// 1 
// 1 1 
// 2 
// 2 1 
// 1 
// 3 1 
// 2 
// 4 2 
// 5 7 
// Sample Output
// 1 
// 0 
// 2 
// 3 
// 2 
// Explanation
// Output1: Proper bracket expressions of length 2 with opening brackets appearing in position 1- []. 
// Output2: Proper bracket expressions of length 2 with opening brackets appearing in position 2 - none.
// Output3: Proper bracket expressions of length 4 with opening brackets appearing in position 1 - [][],  [[]].

#include<bits/stdc++.h>
using namespace std;

int f(int open, int close,bool* a, int n, int** dp){
    int mod = 1e9+7;
    if(open>n || close>n){
        return 0;
    }
    int ans;
    if(dp[open][close]!=-1) return dp[open][close];
    if(open==n && close==n){
        return 1;
    }
    else if(open==close || a[open+close]==true){
        ans = f(open+1, close, a, n, dp)%mod;
    }
    else if(open==n){
        ans = f(open, close+1, a, n, dp)%mod;
    }
    else{
        ans = f(open+1, close, a, n, dp)%mod+f(open, close+1, a, n, dp)%mod;
    }
    return dp[open][close] = ans%mod;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        int n, k;
        cin>>n>>k;
        bool* a = new bool[2*n];
        for(int i=0; i<2*n; i++){
            a[i] = false;
        }
        
        int** dp = new int*[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = new int[n+1];
            for(int j=0; j<=n; j++){
                dp[i][j] = -1;
            }
        }
        
        for(int i=0; i<k; i++){
            int x;
            cin>>x;
            a[x-1] = true;
        }
        
        int sum = 0;
        int open = 0;
        int close = 0;
        
        sum = f(open, close, a, n, dp);
        
        cout<<sum<<endl;
        
    }
    return 0;
}

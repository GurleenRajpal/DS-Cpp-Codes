// Trader Profit
// Send Feedback
// Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and 
// sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n 
// upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = 
// buying + selling). Can you help him maximize his profit?
// Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
// The stock prices are given in the form of an array A for n days.
// Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
// Input Format:
// The first line of input contains an integer T(number of test cases).

// The first line of each test case contains a positive integer k, denoting the number of transactions. 

// The second line of each test case contains a positive integer n, denoting the length of the array A.

// The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
// Output Format
// For each test case print the maximum profit earned by Mike on a new line. 
// Constraints:
// 1 <= T <= 10^3
// 0 < k <= 10

// 2 <= n <= 10^4

// 0 <= elements of array A <= 10^5
// Sample Input
// 3
// 2
// 6
// 10 22 5 75 65 80
// 3
// 4
// 20 580 420 900
// 1
// 5
// 100 90 80 50 25
// Sample Output
// 87
// 1040
// 0
// Explanation
// Output 1: Mike earns 87 as the sum of 12 and 75 i.e. Buy at price 10, sell at 22, buy at 5 and sell at 80.
// Output 2: Mike earns 1040 as the sum of 560 and 480 i.e. Buy at price 20, sell at 580, buy at 420 and sell at 900. 
// Output 3: Mike cannot make any profit as the selling price is decreasing day by day. Hence, it is not possible to earn anything.

#include<bits/stdc++.h>
using namespace std;

int f(int* a, int n, int k, bool on, int*** dp){
    if(n<0 || k<0){
        return 0;
    }
    
    if(dp[n][k][on]!=-1)return dp[n][k][on];
    
    int k1 = f(a+1, n-1, k, on, dp);
    int k2 = 0;
    if(on){
        k2 = f(a+1, n-1, k-1, 0, dp) + a[0];
    }
    else{
        if(k>0){
            k2 = f(a+1, n-1, k, 1, dp) - a[0];
        }
    }
    
    return dp[n][k][on] = max(k1, k2);
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int k, n;
        cin>>k>>n;
        int* a = new int[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        bool on = false;
        int*** dp = new int**[n];
        for(int i=0; i<n; i++){
            dp[i] = new int*[k+1];
            for(int j=0; j<=k; j++){
                dp[i][j] = new int[2];
                for(int k=0; k<2; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = f(a, n-1, k, on, dp);
        cout<<ans<<endl;
        
    }
    return 0;
}

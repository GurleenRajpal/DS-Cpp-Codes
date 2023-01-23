//  Coin Change Problem
// Send Feedback
// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
// You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.
// W can be pretty large so output the answer % mod(10^9 + 7)
// Input Format

// First line will contain T (number of test case), each test case is consists of 3 three lines.
// Line 1 : Integer n i.e. total number of denominations
// Line 2 : N integers i.e. n denomination values
// Line 3 : Value V

// Output Format

// For each test case print the number of ways (W) % mod(10^9 +7) in new line.

// Constraints :

// 1 <= T <= 10
// 1 <= N <= 10
// 1 <= V <= 5000


#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int f(int* a,int n, int v, int** dp){
    // if(si==(n-1) && a[si]==v){
    //     return 1;
    // }
    if(n<0){
        return 0;
    }
    if(v==0){
        return 1;
    }
    if(v<0){
        return 0;
    }
    
    
    if(dp[v][n]!=-1){
        return dp[v][n];
    }
    
    
    
    int pick = 0;
    if(a[n]<=v){
        pick = f(a, n, v-a[n], dp)%mod;
    }
    int notPick = f(a, n-1, v, dp)%mod;
    
    return  dp[v][n] = (pick%mod+notPick%mod)%mod;
    
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int a[n];
        
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int v;
        cin>>v;
        int** dp = new int*[v+1];
        for(int i=0; i<=v; i++){
            dp[i] = new int[n];
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }
        int count = f(a, n-1, v, dp);
        cout<<count<<endl;
        
    }
    return 0;
}

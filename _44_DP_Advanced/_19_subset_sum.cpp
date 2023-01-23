// Subset Sum - Problem
// Send Feedback
// Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
// Input Format
// First-line will contain T(number of test cases), each test case consists of three lines. 
// First-line contains a single integer N(length of input array).
// Second-line contains n space-separated integers denoting the elements of array.
// The last line contains a single positive integer k.
// Output Format
// Output Yes if there exists a subset whose sum is k, else output No for each test case in new line.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 500
// 1 <= arr[i] <= 10^4
// 1 <= K <= 500
// Sample Input
// 1
// 3
// 1 2 3
// 4
// Sample Output
// Yes

#include<bits/stdc++.h>
using namespace std;

bool f(int* a, int n, int k, int** dp){
    
    if(k==0) return true;
    
    if(n==0) return (a[n]==k);
    
    if(dp[n][k]!=-1) return dp[n][k];
    
    bool notPick = f(a, n-1, k, dp);
    
    bool pick = false;
    if(a[n]<=k){
        pick = f(a, n-1, k-a[n], dp);
    }
    
    return  dp[n][k] = pick||notPick;
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
        int k;
        cin>>k;
        int** dp = new int*[n];
        for(int i=0; i<n; i++){
            dp[i] = new int[k+1];
            for(int j=0; j<=k; j++){
                dp[i][j] = -1;
            }
        }
        // for(int i=0; i<=k; i++){
        //     dp[0][i] = true;
        // }
        
        bool result = f(a, n-1, k, dp);
        if(result){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}

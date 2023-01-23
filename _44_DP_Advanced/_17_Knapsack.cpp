//  Knapsnack - Problem
// Send Feedback
// A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and 
// ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
// Note: Space complexity should be O(W).
// Input Format :

// Line 1 : N i.e. number of items
// Line 2 : N Integers i.e. weights of items separated by space
// Line 3 : N Integers i.e. values of items separated by space
// Line 4 : Integer W i.e. maximum weight thief can carry

// Output Format :

// Line 1 : Maximum value V

// Constraints

// 1 <= N <= 10^4
// 1<= wi <= 100
// 1 <= vi <= 100
// 1 <= W <= 1000

// Sample Input 1 :

// 4
// 1 2 4 5
// 5 4 8 6
// 5

// Sample Output :

// 13

#include<bits/stdc++.h>
using namespace std;

int f(int* wn, int* vn, int n, int weight, int** dp){
    
    if(n==0){
        if(wn[0]<=weight){
            return vn[0];
        }
        return 0;
    }
    if(weight<=0){
        return 0;
    }
    if(dp[n][weight]!=-1) return dp[n][weight];
    int notPick = f(wn, vn, n-1, weight, dp);
    int pick = 0;
    if(wn[n]<=weight){
        pick = vn[n] + f(wn, vn, n-1, weight-wn[n], dp);
    }
    
    return dp[n][weight] = max(pick, notPick);
    
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    int* wn = new int[n];
    int* vn = new int[n];
    
    for(int i=0; i<n; i++){
        cin>>wn[i];
    }
    
    for(int i=0; i<n; i++){
        cin>>vn[i];
    }
    
    int weight;
    cin>>weight;
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[weight+1];
        for(int j=0; j<=weight; j++){
            dp[i][j] = 0;
        }
    }
    
    // int value = f(wn, vn, n-1, weight, dp);
    
   
    // if(n==0){
    //     if(wn[0]<=weight){
    //         return vn[0];
    //     }
    //     return 0;
    // }
    // if(weight<=0){
    //     return 0;
    // }
//     int notPick = f(wn, vn, n-1, weight, dp);
//     int pick = 0;
//     if(wn[n]<=weight){
//         pick = vn[n] + f(wn, vn, n-1, weight-wn[n], dp);
//     }
    
//     return dp[n][weight] = max(pick, notPick);
    for(int i=wn[0]; i<=weight; i++){
        
            dp[0][i] =vn[0];
        
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=weight; j++){
            int notPick = dp[i-1][j];
            int pick = INT_MIN;
            if(wn[i]<=j){
                pick = vn[i] + dp[i-1][j-wn[i]];
            }
            dp[i][j] =  max(pick, notPick);
        }
    }
    
    
    cout<<dp[n-1][weight]<<endl;
    
    return 0;
}

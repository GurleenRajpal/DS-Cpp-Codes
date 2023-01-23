// Shortest Subsequence
// Send Feedback
// Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
// Note: input data will be such so there will always be a solution.
// Input Format :
// Line 1 : String S of length
// Line 2 : String V of length
// Output Format :
// Length of shortest subsequence in S such that it is not a subsequence in V
// Constraints:
// 1 <= |S|, |V| <= 1000
// Sample Input :
// babab
// babba
// Sample Output :
// 3

#include<bits/stdc++.h>
using namespace std;

int f(string s, string t,int m,int n, int** dp){
    if(m==0){
        return 1001;
    }
    
    if(n<=0){
        return 1;
    }
    if(dp[m][n] !=-1) return dp[m][n];
    int notInclude = f(s.substr(1), t, m-1, n, dp);
    //search s[0] in t
    int i=0;
    for(; i<n; i++){
        if(s[0]==t[i]){
            break;
        }
    }
    
    if(i==n){
        return 1;
    }
    
    int include = 1 + f(s.substr(1), t.substr(i+1), m-1, n-i-1, dp);
    
    int ans = min(include, notInclude);
    
    return dp[m][n] = ans;
    
}

int main(){
    
    // write your code here
    
    
    string s, t;
    cin>>s>>t;
    int m = s.length();
    int n = t.length();
    int**  dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    cout<<f(s,t,m, n, dp)<<endl;
    return 0;
}

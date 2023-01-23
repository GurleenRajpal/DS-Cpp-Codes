//  Edit Distance - Problem
// Send Feedback
// Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. 
// Edit Distance of two strings is minimum number of steps required to make one string equal to other. 
// In order to do so you can perform following three operations only :

// 1. Delete a character

// 2. Replace a character with another one

// 3. Insert a character

// Note - Strings don't contain spaces
// Input Format :

// First line of input will contain T (number of test cases), each test case consists of two lines.
// Line 1 : String s
// Line 2 : String t

// Output Format :

// For each test case print the Edit Distance value in new line.

// Constraints:

// 1 <= T <= 100
// 1<= m,n <= 100

// Sample Input 1 :

// 1
// abc
// dc

// Sample Output 1 :

// 2


#include<bits/stdc++.h>
using namespace std;

int f(string s1, string s2, int** dp){
    if(s1==s2){
        return 0;
    }
    if(s1.empty()||s2.empty()){
        return max(s1.length(), s2.length());
    }
    
    int m = s1.length();
    int n = s2.length();
    
    if(dp[m][n]!=-1) return dp[m][n];
    
    if(s1[0]==s2[0]){
        return dp[m][n] = f(s1.substr(1),s2.substr(1), dp);
    }
    
    
    int k1 = 1 + f(s1.substr(1), s2.substr(1), dp);
    int k2 = 1 + f(s1.substr(1), s2, dp);
    int k3 = 1 + f(s1, s2.substr(1), dp);
    
    return dp[m][n] = min(k1, min(k2, k3));
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        
        int m = s1.length()+1;
        int n = s2.length()+1;
        
        int** dp = new int*[m];
        for(int i=0; i<m; i++){
            dp[i] = new int[n];
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }
        
        int k = f(s1, s2, dp);
        
        cout<<k<<endl;
        
        
    }
    return 0;
}

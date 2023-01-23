// Smallest Super-Sequence
// Send Feedback
// Given two strings S and T, find and return the length of their smallest super-sequence.
// A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
// Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
// Input Format:
// First line will contain T(number of test case), each test consists of two lines.
// Line 1 : A string
// Line 2: Another string
// Output Format:
// Length of the smallest super-sequence of given two strings for each test case in new line.
// Constraints:
// 1 <= T <= 50
// 1 <= |str1|, |str2| <= 500
// Sample Input:
// 1
// ab
// ac
// Sample Output:
// 3
// Sample Output Explanation:
// Their smallest super-sequence can be "abc" which has length=3.

#include<bits/stdc++.h>
using namespace std;

int f(string s1, string s2, int** dp){
    if(s1.empty()||s2.empty()){
        return max(s1.length(), s2.length());
    }
    if(s1[0]==s2[0]){
        return 1 + f(s1.substr(1), s2.substr(1), dp);
    }
    
    int l1 = s1.length();
    int l2 = s2.length();
    
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    
    int k1 =  f(s1.substr(1), s2, dp);
    int k2 =  f(s1, s2.substr(1), dp);

    return dp[l1][l2] = 1 + min(k1, k2);

}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        int l1 = s1.length()+1;
        int l2 = s2.length()+1;
        
        int** dp = new int*[l1];
        for(int i=0; i<l1; i++){
            dp[i] = new int[l2];
            for(int j=0; j<l2; j++){
                dp[i][j] = -1;
            }
        }
        
        int ans = f(s1, s2, dp);
        cout<<ans<<endl;
    }
    return 0;
}

//  String Maker
// Send Feedback
// According to Ancient Ninjas , string making is an art form . There are various methods of string 
// making , one of them uses previously generated strings to make the new one . Suppose you have two 
// strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a 
// subsequence of characters from B and then merge these two subsequences to form the new string.
// Though while merging the two subsequences you can not change the relative order of individual subsequences. 
// What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j ,
// then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
// Given string A , B , C can you count the number of ways to form string C from the two strings A and B by 
// the method described above. Two ways are different if any of the chosen subsequence is different .
// As the answer could be large so return it after modulo 10^9+7 .
// Input Format :

// First line will contain T(number of test cases), each test case consists of three lines.
// Line 1 : String A
// Line 2 : String B
// Line 3 : String C

// Output Format :

// The number of ways to form string C for each test case in new line.

// Constraints :

// 1 <= T <= 500
// 1 <= |A| , |B|, |C| <=50

// Sample Input :

// 1
// abc
// abc 
// abc

// Sample Output :

// 8


#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int f(string s1, string s2, string s3, long long*** dp){
    
    if(s3.length()==0){
        return 1;
    }
    if(s1.length()<=0 && s2.length()<=0){
        return 0;
    }
    
    if(dp[s1.length()][s2.length()][s3.length()]!=-1){
        return dp[s1.length()][s2.length()][s3.length()];
    }
    
    long long ans = 0;
    for(int i=0; i<s1.length(); i++){
        if(s1[i]==s3[0]){
            ans += f(s1.substr(i+1), s2, s3.substr(1), dp)%mod;
        }
    }
    
    for(int i=0; i<s2.length(); i++){
        if(s2[i]==s3[0]){
            ans += f(s1, s2.substr(i+1), s3.substr(1), dp)%mod;
        }
    }
    
    
    return dp[s1.length()][s2.length()][s3.length()] = ans%mod;
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--){
    	string s1, s2, s3;
    	cin>>s1>>s2>>s3; 
        long long*** dp = new long long** [51];
        for(int i=0; i<51; i++){
            dp[i] = new long long* [51];
            for(int j=0; j<51; j++){
                dp[i][j] = new long long [51];
                for(int k=0; k<51; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int x = f(s1, s2, s3, dp)%mod;
        cout<<x<<endl;
    }
    
    return 0;
}

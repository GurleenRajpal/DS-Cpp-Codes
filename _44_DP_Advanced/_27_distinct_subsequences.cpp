// Distinct Subsequences
// Send Feedback
// Given a string, count the number of distinct subsequences of it ( including empty subsequence ). 
// For the uninformed, A subsequence of a string is a new string which is formed from the original string by 
// deleting some of the characters without disturbing the relative positions of the remaining characters.
// For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
// Input Format:
// First line of input contains an integer T which is equal to the number of test cases.
// Each of next T lines contains a string s.
// Output Format:
// Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. 
// Since, this number could be very large, you need to output ans%(10^9 + 7) where ans is the number of distinct subsequences. 
// Constraints:
// T ≤ 100
// 1 <= length(S) ≤ 10^5
// All input strings shall contain only uppercase letters.

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int f(string input,string output,map<string, int>& mp){
    int mod = 1e9+7;
    if(input.empty()){
        if(mp[output]!=1){
            mp[output]=1;
            return 1;
        }
        else{
            return 0;
        }
    }
    
    long long x1 = f(input.substr(1), output+input[0], mp);
    
    long long x2 = f(input.substr(1), output, mp);
    
    return (x1%mod+x2%mod)%mod;
    
    
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string input;
        cin>>input;
        int mod = 1e9+7;
        // map<string, int> mp;
        // string output="";
        // int x = f(input, output, mp);
        // cout<<x<<endl;
        long long n = input.length();
        long long * dp = new long long[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        
        vector<int> chars(256, -1);
        
        for(long long i=1; i<=n; i++){
            dp[i] = (2*(dp[i-1]%mod))%mod;
            int repetition = 0;
            if(chars[input[i-1]]!=-1){
                dp[i] = (dp[i]%mod-dp[chars[input[i-1]]]%mod)%mod;
            }
            chars[input[i-1]] = (i-1);
        }
        cout<<(dp[n])%mod<<endl;
        
    }
    return 0;
}

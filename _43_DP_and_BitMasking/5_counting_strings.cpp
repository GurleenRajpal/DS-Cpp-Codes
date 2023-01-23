//  Counting Strings
// Send Feedback
// Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find 
// how many strings 't' with length equal to that of 's', also consisting of upper case alphabets 
// are there satisfying the following conditions:

// -> String 't' is lexicographical larger than string 's'.
// -> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.

// Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.
// Input Format:

// First line will contain T(number of test cases).
// Each test case consists of a single line containing the string s.

// Output Format:

// For each test case output the number of strings (t) %(10^9 + 7) in new line.

// Constraints:

// 1 <= T <= 50
// 1 <= |S| <= 10^5

// Sample Input:

// 2
// A
// XKS

// Sample output:

// 25
// 523

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        string s;
		cin >> s;
		int n = s.size();
		int M = 1e9 + 7;
		vector<long> dp(n);
        
        dp[0] = 'Z' - s[0];
        long ans = dp[0];
        
        for(int i=1; i<n; i++){
        	int v = 'Z' - s[i];
            ans = (ans + v + v * dp[i-1])%M;
            dp[i] = (v + dp[i-1]*26)%M;
        }
        
        cout<<ans<<endl;
        
        
    }
    return 0;
}

//  AlphaCode-Question
// Send Feedback
// Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:

// Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

// Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

// Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ 
// and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

// Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be
// tons of different decodings and with that many you would find at least two different ones that would make sense.”

// Alice: “How many different decodings?”

// Bob: “Jillions!”

// For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine 
// how many decodings there can be for a given string using her code.
// Input Format:

// First line will contain T (number of test case).
// Each input is consists of a single line containing the message string

// Output Format:

// For each test case print the answer % mod (10^9 +7)

// Constraints:

// 1 <= T <= 100
// 1 <= |S| <= 10^5
// sum of length of all string doesn't exceed 5*10^6

// Sample Input 1:

// 3
// 47974
// 6349988978
// 1001

// Sample Output 1:

// 1
// 1
// 0

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000000+7;

ll countWays(char* s, ll* dp, ll len){
    if(s[0]=='\0'){
        return 1;
    }
    if(s[0]=='0'){
        return 0;
    }
    ll way1 = 0;
    
    if(dp[len]!=-1) return dp[len];
    
    way1 = countWays(s+1,dp, len-1)%mod;

    int x = s[0] - '0';
    if(s[1]!='\0'){
        int y = s[1] - '0';
        if((10*x+y)<=26){
            way1 += countWays(s+2, dp, len-2);
            way1 %= mod;
        }
        else{
            way1 += 0;
        }
    }
    
    return dp[len] = way1%mod;
}

int main(){
    
    // write your code here
    ll t;
    cin>>t;
    
    while(t--){
        char s[100002];
        cin>>s;
        ll len = strlen(s);
        ll dp[len+1];
        for(int i=0; i<=len; i++){
            dp[i]=-1;
        }
        ll k = countWays(s, dp, len)%mod;
        if(k<0){
            cout<<1<<endl;
        }
        else{
        	cout<<k<<endl;
        }
        
    }
    return 0;
}

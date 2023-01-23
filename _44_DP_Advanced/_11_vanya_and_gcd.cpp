//  Vanya and GCD
// Send Feedback
// Vanya has been studying all day long about sequences and other Complex Mathematical Terms. 
// She thinks she has now become really good at it. So, her friend Vasya decides to test her 
// knowledge and keeps the following challenge it front of her:
// Vanya has been given an integer array A of size N. Now, she needs to find the number of 
// increasing sub-sequences of this array with length ≥1 and GCD=1. A sub-sequence of an array .
// is obtained by deleting some (or none) elements and maintaining the relative order of the rest 
// of the elements. As the answer may be large, print it Modulo 109+7
// She finds this task really easy, and thinks that you can do it too. Can you?
// Input Format:

// First line will contain T(number of test case), each test consists of two line.
// The first line contains a single integer N denoting size of array A. 
// The next line contains N space separated integers denoting the elements of array A

// Output Format:

// Print the required answer Modulo 10^9+7 for each test case in new line

// Constraints:

// 1 <= T <= 50
// 1 <= N <= 200
// 1 <= A[i] <= 100

// Sample Input

// 1
// 3
// 1 2 3

// Sample Output

// 5


#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}
int main(){
    
    // write your code here
    int mod = 1000000007;
    int t, n;
    
    cin>>t;
    while(t--){
        cin>>n;
        long long** dp = new long long*[n];
    
        for(int i=0; i<n; i++){
            dp[i] = new long long[101];
            for(int j=0; j<101; j++){
                dp[i][j] = 0;
            }
        }
        
        long long* a = new long long[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        dp[0][a[0]] = 1;
        
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(a[i]<=a[j]){
                    continue;
                }
                //int val = a[i];   
                for(int k = 1; k<101; k++ ){
                    long long val = gcd(a[i], k);
                    dp[i][val] = (dp[i][val]%mod+ dp[j][k]%mod)%mod;
                }
            }
  
            //Important line
            dp[i][a[i]]++;
            
            
        }
        long long val = 0;
        
        for(int i=0; i<n; i++){
            val = (val+dp[i][1])%mod;
        }
        
        cout<<val%mod<<endl;
        delete[] dp;
        delete[] a;
    }
    
    return 0;
}

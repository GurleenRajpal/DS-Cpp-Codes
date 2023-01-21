// Fibonacci Sum
// Send Feedback
// The fibonacci sequence is defined by the following relation:
//  F(0) = 0
//  F(1) = 1
//  F(N) = F(N - 1) + F(N - 2), N >= 2
// Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
// Input Format :
// First line of input will contain T(number of test cases), each test case follows as.
// Two non-negative space-separated integers N and M. (N <= M)
// Output Format :
// A new line containing the answer for the each test case.
// Constraints:
// 1 <= T <= 10^3
// 1 <= N <= M <= 10^18
// Sample Input :
// 1 
// 10 19 
// Sample Output :
// 10857


#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

void multiply(long long a[2][2], long long m[2][2]){
    long long fv = (a[0][0]%mod * m[0][0]%mod)%mod + (a[0][1]%mod * m[1][0]%mod)%mod;
    long long sv = (a[0][0]%mod * m[0][1]%mod)%mod + (a[0][1]%mod * m[1][1]%mod)%mod;
    long long tv = (a[1][0]%mod * m[0][0]%mod)%mod + (a[1][1]%mod * m[1][0]%mod)%mod;
    long long av = (a[1][0]%mod * m[0][1]%mod)%mod + (a[1][1]%mod * m[1][1]%mod)%mod;
    a[0][0] = fv;
    a[0][1] = sv;
    a[1][0] = tv;
    a[1][1] = av;

}

void power(long long A[2][2], long long n){
    if(n==0 || n==1){
        return;
    }
    power(A, n/2);

    multiply(A, A);

    if(n%2!=0){
        long long M[2][2] = {{1,1}, {1,0}};
        multiply(A, M);
    }
}

long long fib(long long n){
    long long A[2][2] = {{1,1}, {1,0}};

    if(n==0){
        return 0;
    }

    power(A, n-1);

    return A[0][0]%mod;
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        cout<<(fib(m+2)%mod-fib(n+1)%mod+mod)%mod<<endl;
        
    }
    return 0;
}

// Sum of LCM
// Send Feedback
// Given n, calculate and print the sum :
// LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
// where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
// Input Format :
// First line of input will contain T(number of test case), each test case follows as.
// An Integer N
// Output Format :
// Required sum for each test case in newline.
// Constraints :
// 1 <= T <= 10^4
// 1 <= n <= 10^5
// Sample Input 1 :
// 1
// 5
// Sample Output 1 :
// 55
// Sample Input 2 :
// 1
// 2
// Sample Output 2 :
// 4

#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(a%b==0){
        return b;
    }
    return gcd(b, a%b);
}
int euler(int n){
    int* phi = new int[n+1];
    for(int i=0; i<=n; i++){
        phi[i] = i;
    }
    
    for(int i=2; i<=n; i++){
        if(phi[i]==i){
            phi[i] = i-1;
            for(int j = 2*i; j<=n; j+=i){
                phi[j] = (phi[j] * (i-1))/i;
            }
        }
        
    }
}

int main(){
    
    // write your code here
    long long n = 1e5+1;
    long long* phi = new long long[n+1];
    for(long long i=0; i<=n; i++){
        phi[i] = i;
    }
    
    for(long long i=2; i<=n; i++){
        if(phi[i]==i){
            phi[i] = i-1;
            for(long long j = 2*i; j<=n; j+=i){
                phi[j] = (phi[j] * (i-1))/i;
            }
        }
    }
    
    long long* ans = new long long[n+1];
    for(int i=0; i<=n; i++){
        ans[i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            ans[j] += phi[i]*i;
        }
    }
    
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        // int* g = new int[n+1];
        // for(int i=0; i<=n; i++){
        //     g[i] = 1;
        // }
        // g[n] = n;
        // for(int i=1; i<=n/2; i++){
        //     int x = gcd(n, i);
        //     g[i] = x;
        //     g[n-i] = x;
        // }
        //int* phi = new int[n+1];
        //euler(n);
        long long sum = 0;
        // for(long long i=1; i<=k; i++){
        //     if(k%i==0){
        //         sum += phi[i] * i;
        //     }
        // }
        sum = ans[k];
        sum +=1;
        sum *=k;
        sum /=2;
        cout<<sum<<endl;
    }
    return 0;
}

// GCD Extreme
// Send Feedback
// Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
// G=0;
// for(i = 1 ; i < N ; i++)
//    for(j = i+1 ; j <= N ; j++) 
//        G+=gcd(i,j);
// Here gcd() is a function that finds the greatest common divisor of the two input numbers.
// Input Format:
// The first line of input will contain T(number of the test case). Each test case contains an integer N.
// Output Format:
// For each test case print the answer in a new line.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^5
// Sample Input:
// 3
// 10
// 100
// 3
// Sample Output:
// 67
// 13015
// 3

#include<bits/stdc++.h>
using namespace std;

#define MAX 100001
 
long long phi[MAX], result[MAX];

void euler(){
    phi[1] = 1;
    for(int i=1; i<MAX; i++){
        phi[i] = i;
    }
    for(int i=2; i<MAX; i++){
        if(phi[i]==i){
            phi[i] = i-1;
            for(int j=2*i; j<MAX; j+=i){
                phi[j] = (phi[j]*(i-1))/i;
            }
        }
    }
    
}

void gcdPair(){
    euler();
    for(int i=1; i<MAX; i++){
        result[i] = 0;
    }
    for(int i=1; i<MAX; i++){
        for(int j=2; j*i<MAX; j++){
            result[i*j] += i*phi[j];
        }
    }
    for(int i=1; i<MAX; i++){
        result[i] += result[i-1];
    }
}

int gcd(int i, int j){
    if(i<j){
        return gcd(j, i);
    }
    if(j==0){
        return i;
    }
    return gcd(j, i%j);
}
int main(){
    
    // write your code here 
    gcdPair();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
//         int g = 0;
//         for(int i=1; i<n; i++){
//             for(int j = i+1; j<=n; j++){
//                 g += gcd(i,j);
//             }
//         }
        
        cout<<result[n]<<endl;
    }
    return 0;
}

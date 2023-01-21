// Find Prime Numbers From 1 to N
// Send Feedback
// Given a number N, find number of primes in the range [1,N].
// Input Format:
// The only line of input consists of a number N
// Output Format:
// Print the number of primes in the range [1,N].
// Constraints:
// 1 ≤ N ≤ 10^6
// Sample Input :
// 3 
// Sample Output -
// 2

#include<bits/stdc++.h>
using namespace std;

bool f(int n){
    if(n==1){
        return 0;
    }
    int count = 0;
    for(int i=1;i<=sqrt(n); i++){
        if(i*i==n){
            count+=1;
        }
        else if(n%i==0){
            count+=2;
        }
    }
    if(count==2){
        return true;
    } 
    return false;
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    int ct = 0;
    vector<bool> v(n+1, true);
    // for(int i=1; i<=n; i++){
    //     if(f(i)){
    //         ct++;
    //     }
    // }
    
    v[0] = false;
    v[1] = false;
    
    for(int i=2; i*i<=n; i++){
        if(v[i]==false){
            continue;
        }
        for(int j=i*i; j<=n; j+=i ){
            // v[j] = false;
            if(j%i==0){
                v[j] = false;
            }
        }
    }
    
    for(int i=0; i<=n; i++){
        if(v[i])ct++;
    }
    
    cout<<ct<<endl;
    return 0;
}

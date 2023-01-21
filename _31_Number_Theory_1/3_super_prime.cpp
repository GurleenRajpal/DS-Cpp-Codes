// Super Prime
// Send Feedback
// A number is called super-prime if it has exactly two distinct prime divisors
// Example 10 , 6
// You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
// Input Format:
// Contain an integer N
// Output Format:
// Print the number of super prime between [1, N]
// Constraints:
// 1 <= N <= 10^6
// Sample Input 1:
// 10
// Sample Output 1:
// 2
// Sample Input 2:
// 25
// Sample Output 2:
// 10
// Explanation:
// The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24.

#include<bits/stdc++.h>
using namespace std;

int f(int n){
    
    int ct = 0;
    vector<bool> primes(n+1, true);
    primes[0] = false;
    primes[1] = false;
    
    
    for(int i = 2; i*i<=n; i++){
        if(primes[i]==false){
            continue;
        }
        for(int j = i*i; j<=n; j+=i){
            if(j%i==0){
                primes[j] = false;
            }
        }
    }
    
    
    vector<int> v(n+1, 2);
    v[0] = 0;
    v[1] = 1;
    
    for(int i=2; i<=n; i++){
    	if(!primes[i]){
    	continue;
    	}
        for(int j = i+i; j<=n; j+=i){
            if(j%i==0){
                v[j]+=1;
            }
        }
        
    }
    
    for(int i=0; i<=n; i++){
        if(v[i]==4){
            ct++;
        }
    }
    
    return ct;
    
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    
    cout<<f(n)<<endl;
    
    
    return 0;
}
